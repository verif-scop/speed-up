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
