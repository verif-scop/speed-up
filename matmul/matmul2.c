#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define M 1024
#define N 1024
#define K 1024

double A[M][K + 13];
double B[K][N + 13];
double C[M][N + 13];


void init_array() {
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      A[i][j] = (i + j);
      B[i][j] = (double)(i * j);
      C[i][j] = 0.0;
    }
  }
}

void print_array() {
  int i, j;
  FILE* file;
  if (file = fopen("2.output", "w")) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        fprintf(file, "%lf ", C[i][j]);
        if (j % 80 == 79)
          fprintf(file, "\n");
      }
      fprintf(file, "\n");
    }
    fclose(file);
  }
}


double rtclock() {
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday(&Tp, &Tzp);
  if (stat != 0)
    printf("Error return from gettimeofday: %d", stat);
  return (Tp.tv_sec + Tp.tv_usec * 1.0e-6);
}

int main() {
  int i, j, k;
  register double s;

  init_array();
  s = rtclock();

#pragma scop
  for (k = 0; k < K; k++)
    for (j = 0; j < N; j++)
      for (i = 0; i < M; i++)
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
#pragma endscop
  printf("Time: %f\n", rtclock() - s);

  print_array();

  return 0;
}
