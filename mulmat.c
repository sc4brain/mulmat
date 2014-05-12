
/***************** PARK *******************/
void mulMat_park(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  ;
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
  ;
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
  ;
}



void mulMat0(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  int i,j,k;
  for(j=0; j<matsize; j++){
    for(i=0; i<matsize; i++){
      for(k=0; k<matsize; k++){
	matc[i*matsize+j] += mata[i*matsize+k] * matb[k*matsize+j];
      }
    }
  }
}


void mulMat1(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  int i,j,k;
  double tmp;
  for(i=0; i<matsize; i++){
    for(j=0; j<matsize; j++){
      tmp = 0.0;
      for(k=0; k<matsize; k++){
	tmp += mata[i*matsize+k] * matb[k*matsize+j];
	//matc[i*matsize+j] += mata[i*matsize+k] * matb[k*matsize+j];
      }
      matc[i*matsize+j] = tmp;
    }
  }
}

void mulMat2(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  int i,j,k;

  double sum[4];
  double tmp;

  for(k=0; k<matsize; k++){
    for(i=0; i<matsize; i+=4){
      sum[0] = mata[(i+0)*matsize+k];
      sum[1] = mata[(i+1)*matsize+k];
      sum[2] = mata[(i+2)*matsize+k];
      sum[3] = mata[(i+3)*matsize+k];
      for(j=0; j<matsize; j++){
	tmp = matb[k*matsize+j];
	matc[(i+0)*matsize+j] += sum[0] * tmp;
	matc[(i+1)*matsize+j] += sum[1] * tmp;
	matc[(i+2)*matsize+j] += sum[2] * tmp;
	matc[(i+3)*matsize+j] += sum[3] * tmp;
	//matc[i*matsize+j] += mata[i*matsize+k] * matb[k*matsize+j];
      }
    }
  }
}


#define BLOCK_SIZE 32

void mulMat3(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
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

}
