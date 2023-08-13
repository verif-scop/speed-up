#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

#define N 6000

#define alpha 1
#define beta 1

#pragma declarations
double A[N][N];
double B[N][N];

double x[N];
double u1[N];
double u2[N];
double v2[N];
double v1[N];
double w[N];
double y[N];
double z[N];
#pragma enddeclarations

#define TIME

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

void init_array()
{
    int i, j;

    for (i=0; i<N; i++) {
        u1[i] = i;
        u2[i] = (i+1)/N/2.0;
        v1[i] = (i+1)/N/4.0;
        v2[i] = (i+1)/N/6.0;
        y[i] = (i+1)/N/8.0;
        z[i] = (i+1)/N/9.0;
        x[i] = 0.0;
        w[i] = 0.0;
        for (j=0; j<N; j++) {
            A[i][j] = ((double) i*j)/N;
        }
    }
}

void print_array()
{
    int i, j;

    for (i=0; i<N; i++) {
        fprintf(stderr, "%0.2lf ", w[i]);
        if (i%80 == 20) fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
}


double rtclock()
{
    struct timezone Tzp;
    struct timeval Tp;
    int stat;
    stat = gettimeofday (&Tp, &Tzp);
    if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}

int main()
{
    double t_start, t_end;
    int i, j;

    init_array();

    IF_TIME(t_start = rtclock());

#pragma scop
#define S1(i,j)	B[i][j] = A[i][j] + u1[i]*v1[j] + u2[i]*v2[j];
#define S2(i,j)	x[i] = x[i] + beta* B[j][i]*y[j];
#define S3(i)	x[i] = x[i] + z[i];
#define S4(i,j)	w[i] = w[i] + alpha* B[i][j]*x[j];

		int t1, t2, t3, t4;

	register int lbv, ubv;

/* Start of CLooG code */
if (N >= 1) {
  for (t2=0;t2<=N-1;t2++) {
    for (t3=0;t3<=N-1;t3++) {
      S1(t2,t3);
      S2(t3,t2);
    }
  }
  for (t2=0;t2<=N-1;t2++) {
    S3(t2);
  }
  for (t2=0;t2<=N-1;t2++) {
    for (t3=0;t3<=N-1;t3++) {
      S4(t2,t3);
    }
  }
}
/* End of CLooG code */

#pragma endscop

    IF_TIME(t_end = rtclock());
    IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

    if (fopen(".test", "r")) {
#ifdef MPI
        if (my_rank == 0) {
            print_array();
        }
#else
        print_array();
#endif
    }

    return 0;
}