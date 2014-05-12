#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matfunc.h"

int main(int argc, char **argv)
{
  int matsize;
  char *filename_a, *filename_b, *filename_c;
  double *mata, *matb, *matc;

  if(argc != 5){
    printf("Useage : \n\t$ genmat matsize filename1 filename2 filename3\n");
    printf("\tmatsize : N\n");
    printf("\tfilename1 : input matrix A\n");
    printf("\tfilename2 : input matrix B\n");
    printf("\tfilename3 : answer matrix C\n");
    
    exit(0);
  }

  srand((unsigned)time(NULL));

  matsize = atoi(argv[1]);
  filename_a = argv[2];
  filename_b = argv[3];
  filename_c = argv[4];


  printf("NxN : %dx%d\n", matsize, matsize);
  printf("mat A : [%s]\n", filename_a);
  printf("mat B : [%s]\n", filename_b);
  printf("mat C : [%s]\n", filename_c);

  mata = allocMat(matsize);
  matb = allocMat(matsize);
  matc = allocMat(matsize);

  genMat(matsize, mata);
  writeMat(matsize, mata, filename_a);

  genMat(matsize, matb);
  writeMat(matsize, matb, filename_b);


  readMat(mata, filename_a);
  readMat(matb, filename_b);

  mulMatSample(matsize, mata, matb, matc);
  writeMat(matsize, matc, filename_c);

  freeMat(mata);
  freeMat(matb);
  freeMat(matc);

  return(0);
}
