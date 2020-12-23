#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10


float *cholesky(float A[N][N], float B[N], int n)
{

  float   *x;
  x = malloc(sizeof(float) * n);
  float C[N][N];
  C[0][0]=sqrt(A[0][0]);
  for(int i=1;i<n;i++){
        C[i][0]=A[i][0]/C[0][0];
     }
  for(int j=1;j<n;j++){
        for(int i=0;i<j;j++){
              C[i][j]=0;
        
              float s1=0;
              for(int k=0;k<j;k++){ 
                      s1=C[j][k]*C[j][k];
              }       
              C[j][j]=sqrt(A[j][j]-s1);
           }
        for(int i=j+1;i<n;i++){
                
              float s2=0;
              for(int k=0;k<j;k++){
                      s1=C[i][k]*C[j][k];
              } 
              C[i][j]=(1/C[j][j])*(A[j][j]-s1);
           } 
      }
      return C[N][N];
}

int main()
{
  float   A[N][N], B[N];
  float   C[N][N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }








