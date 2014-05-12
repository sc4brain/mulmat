
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
void mulMat_miyamoto(const int matsize,
	     const double *mata,
	     const double *matb,
	     double *matc)
{
  ;
}


