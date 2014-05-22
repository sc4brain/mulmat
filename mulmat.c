//#include <omp.h>

/***************** PARK *******************/
void mulMat_park(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  /*  int i;
  int j;
  int k=0;
  int jxmatsize;
  int size = matsize*matsize;

  for(i=0; i<size; i++){
    matc[i]=0;
    jxmatsize=0;
    for(j=0; j<matsize; j++){
      matc[i] += mata[ i - k + j] * matb [k + jxmatsize];
      jxmatsize += matsize;
    }
    k++; 
    if(k==matsize){
      k = 0;
    }

    }*/

#define BLOCK_SIZE 32
  int i, j, k, ii, jj, kk;
  int ixmatsize;
  int kxmatsize;
  //#pragma omp parallel for
  for(ii=0; ii<matsize; ii+=BLOCK_SIZE){
    for(kk=0; kk<matsize; kk+=BLOCK_SIZE){
      for(jj=0; jj<matsize; jj+=BLOCK_SIZE){
	ixmatsize=ii*matsize;
	for(i=ii; i<ii+BLOCK_SIZE && i < matsize; i++){
	  kxmatsize=kk*matsize;
	  for(k=kk; k<kk+BLOCK_SIZE && k < matsize; k++){
	    for(j=jj; j<jj+BLOCK_SIZE && j < matsize; j++){
	      matc[ixmatsize+j] += mata[ixmatsize+k] * matb[kxmatsize+j];
	    }
	    kxmatsize+=matsize;
	  }
	  ixmatsize+=matsize;
	}

      }
    }
  }

  return ;

}

/***************** FUKUDA *******************/
void mulMat_fukuda(const int matsize,
		   const double *mata,
		   const double *matb,
		   double *matc)
{
  ;
}

/***************** YAMAZAKI *******************/
void mulMat_yamazaki(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  ;  
}

/***************** GOTO *******************/
void mulMat_goto(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  	int i, j, k;
	for(i = 0; i < matsize; i++) {
		for(j = 0; j < matsize; j++) {
			matc[i*matsize + j] = 0;
			for(k = 0; k < matsize; k++) {

				matc[i*matsize + j] += mata[i*matsize + k] * matb[k*matsize + j];

			}
		}
	}
 
}


/***************** KAZAWA *******************/
void mulMat_kazawa(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  ;
}


/***************** MIYAMOTO *******************/
#ifdef BLOCK_SIZE
#undef BLOCK_SIZE
#endif
#define BLOCK_SIZE 40

void mulMat_miyamoto(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  int i, j, k, ii, jj, kk;

#pragma omp parallel shared(mata, matb, matc) private(i, j, k, ii, jj, kk) num_threads(4)
  for(ii=0; ii<matsize; ii+=BLOCK_SIZE){
    for(kk=0; kk<matsize; kk+=BLOCK_SIZE){
      for(jj=0; jj<matsize; jj+=BLOCK_SIZE){

#pragma omp for
	for(i=0; i<BLOCK_SIZE; i++){
	  for(k=kk; k<kk+BLOCK_SIZE && k < matsize; k++){
	    for(j=jj; j<jj+BLOCK_SIZE && j < matsize; j++){
	      matc[(i+ii)*matsize+j] += mata[(i+ii)*matsize+k] * matb[k*matsize+j];
	    }
	  }
	}

      }
    }
  }
}


