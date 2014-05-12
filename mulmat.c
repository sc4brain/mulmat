
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
  ;
}


