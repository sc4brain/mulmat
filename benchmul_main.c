#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matfunc.h"

#include "mulmat.h"


int main(int argc, char **argv)
{
  int matsize;
  char *filename_a, *filename_b, *filename_c;
  double *mata, *matb, *matc;

  // set up arguments
  if(argc != 5){
    printf("Useage : \n\t$ benchmul matsize filename1 filename2 filename3\n");
    printf("\tmatsize : N\n");
    printf("\tfilename1 : input matrix A\n");
    printf("\tfilename2 : input matrix B\n");
    printf("\tfilename3 : answer matrix C\n");
    
    exit(0);
  }

  matsize = atoi(argv[1]);
  filename_a = argv[2];
  filename_b = argv[3];
  filename_c = argv[4];


  // allocate Matrix
  mata = allocMat(matsize);
  matb = allocMat(matsize);
  matc = allocMat(matsize);


  if(readMat(mata, filename_a) != matsize){ printf("ERROR : file format error.\n"); }
  printf("mat A : [%s] OK\n", filename_a);
  if(readMat(matb, filename_b) != matsize){ printf("ERROR : file format error.\n"); }
  printf("mat B : [%s] OK\n", filename_b);
  if(readMat(matc, filename_c) != matsize){ printf("ERROR : file format error.\n"); }
  printf("mat C : [%s] OK\n", filename_c);
  printf("NxN : %dx%d\n", matsize, matsize);

  printf("\n****** START BENCHMARK ******\n\n");

  printf("Park     :\t");
  checkMulMatFunc(mulMat_park, matsize, mata, matb, matc);

  printf("Fukuda   :\t");
  checkMulMatFunc(mulMat_fukuda, matsize, mata, matb, matc);

  printf("Yamazaki :\t");
  checkMulMatFunc(mulMat_yamazaki, matsize, mata, matb, matc);

  printf("Goto     :\t");
  checkMulMatFunc(mulMat_goto, matsize, mata, matb, matc);

  printf("Kazawa   :\t");
  checkMulMatFunc(mulMat_kazawa, matsize, mata, matb, matc);

  printf("Miyamoto :\t");
  checkMulMatFunc(mulMat_miyamoto, matsize, mata, matb, matc);

  printf("\n****** FINISH BENCHMARK ******\n");


  freeMat(mata);
  freeMat(matb);
  freeMat(matc);

  return(0);
}
