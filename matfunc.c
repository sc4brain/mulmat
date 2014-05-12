#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "matfunc.h"

#define ALLOW_ERROR 0.00001

double diffMat(const int matsize, const double *mata, const double *matb)
{
  int i,j;
  double calcerror=0.0;

  for(i=0; i<matsize; i++){
    for(j=0; j<matsize; j++){
      calcerror += (mata[i*matsize+j] - matb[i*matsize+j]) * (mata[i*matsize+j] - matb[i*matsize+j]);
    }
  }
  return(calcerror);
}


double checkMulMatFunc(void (*func)(const int matsize, const double *mata, const double *matb, double *matc),
		       const int matsize,
		       const double *mata,
		       const double *matb,
		       const double *matc)
{
  clock_t start, end;
  double *tmp_matc;
  double calcerror;
  double time;
  tmp_matc = allocMat(matsize);
  clearMat(matsize, tmp_matc);

  start = clock();
  func(matsize, mata, matb, tmp_matc);
  end = clock();

  time = (double)(end-start)/CLOCKS_PER_SEC;
  printf("Time=%f sec , ", time);

  calcerror = diffMat(matsize, tmp_matc, matc);

  if(calcerror > ALLOW_ERROR){
    printf("\tWrong Calculation! (error=%.10f)\n", calcerror);
  }else{
    printf("\tOK (error =%.10f)\n", calcerror);
  }

  return(time);
}

double* allocMat(int matsize)
{
  double *mat;
  mat = (double *)malloc(matsize * matsize * sizeof(double));
  if(mat == NULL){ printf("Error : allocation fault.\n"); exit(-1); }
  return(mat);
}

void freeMat(double *mat)
{
  free(mat);
}


void genMat(const int matsize, double *mat)
{
  int i,j;
  
  for(i=0; i<matsize; i++){
    for(j=0; j<matsize; j++){
      mat[i*matsize + j] = ((double)rand())/((double)RAND_MAX+1);
    }
  }
 }

void printMat(const int matsize, const double *mat)
{
  int i,j;
  printf("N=%d\n", matsize);
  for(i=0; i<matsize; i++){
    for(j=0; j<matsize; j++){
      printf("%f\n", mat[i*matsize + j]);
    }
  }
}

void writeMat(const int matsize, const double *mat, const char *filename)
{
  int i,j;
  FILE *fp;
  fp = fopen(filename, "w");
  
  fprintf(fp, "%d\n", matsize);
  for(i=0; i<matsize; i++){
    for(j=0; j<matsize; j++){
      fprintf(fp, "%.10f\n", mat[i*matsize + j]);
    }
  }
  fclose(fp);
}

/* return mat size */
int readMat(double *mat, const char *filename)
{
  int i;
  int matsize;
  char buf[1024];
  FILE *fp;
  char *result;

  fp = fopen(filename, "r");
  if(fp==NULL){ printf("ERROR : file open failure\n"); exit(-1); }

  result = fgets(buf, sizeof(buf), fp);
  if(result==NULL){ printf("ERROR : file read failure\n"); exit(-1); }
  sscanf(buf, "%d", &matsize);
  if(matsize <= 0){ printf("ERROR : file format failure\n"); exit(-1); }

  for(i=0; i<matsize*matsize; i++){
    result = fgets(buf, sizeof(buf), fp);
    if(result==NULL){ printf("ERROR : file read failure\n"); exit(-1); }
    sscanf(buf, "%lf", &(mat[i]));
  }

  fclose(fp);
  return(matsize);
}

void clearMat(const int matsize, double *mat)
{
  int i,j;

  for(i=0; i<matsize; i++){
    for(j=0; j<matsize; j++){
	mat[i*matsize+j] = 0.0;
    }
  }

}

void mulMatSample(const int matsize, const double *mata, const double *matb, double *matc)
{
  int i,j,k;

  for(k=0; k<matsize; k++){
    for(j=0; j<matsize; j++){
      for(i=0; i<matsize; i++){
	matc[i*matsize+j] += mata[i*matsize+k] * matb[k*matsize+j];
      }
    }
  }
}
