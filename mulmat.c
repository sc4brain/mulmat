
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


