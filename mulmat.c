
/***************** PARK *******************/
void mulMat_park(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  //  int s = matsize;
  int i;
  int j;
  //  double *answer=0;

  for(i=0; i<(matsize*matsize); i++){
    *(matc+i)=0;
  }
  
  for(i=0; i<(matsize*matsize); i++){
    for(j=0; j<matsize; j++){
      *(matc+i) = *(matc+i) + *(mata+ i - i%matsize + j) * *(matb + i % matsize + j*matsize);
    }
  }
  //  matc = answer;

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


