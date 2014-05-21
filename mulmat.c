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
    
  int i;
  int counter_a=0,counter=0;
  while(1){
    for(i=0;i<matsize;i++){
      matc[matsize*counter_a+counter] += mata[i+matsize*counter_a] * matb[i*matsize+counter];
    }
    counter++;
    if(counter==matsize){
      counter_a++;
      counter=0;
    }
    if(counter_a==matsize){
      break;
    }
  }
  
}

/***************** YAMAZAKI *******************/
void mulMat_yamazaki(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  
  int i=0;
  int row=0,col=0;
  double bus=0.0;
  int j=0,k=0;
  

  for(row=0;row<matsize;row++){
    for(col=0;col<matsize;col++){
      k=col;
      for(j=row*matsize;j<(row+1)*matsize;j++){
	bus += mata[j]*matb[k];
	k+=matsize;
      }
      matc[i]=bus;
      i++;
      bus = 0.0;
    }
    }
  
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
void mulMat_miyamoto(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
#define BLOCK_SIZE 32
  int i, j, k, ii, jj, kk;


  for(ii=0; ii<matsize; ii+=BLOCK_SIZE){
    for(kk=0; kk<matsize; kk+=BLOCK_SIZE){
      for(jj=0; jj<matsize; jj+=BLOCK_SIZE){

	for(i=ii; i<ii+BLOCK_SIZE && i < matsize; i++){
	  for(k=kk; k<kk+BLOCK_SIZE && k < matsize; k++){
	    for(j=jj; j<jj+BLOCK_SIZE && j < matsize; j++){
	      matc[i*matsize+j] += mata[i*matsize+k] * matb[k*matsize+j];
	    }
	  }
	}

      }
    }
  }



  ;
}


