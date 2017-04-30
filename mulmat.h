#ifndef MULMAT_H
#define MULMAT_H

void mulMat_park(const int matsize, const double *mata, const double *matb, double *matc);
void mulMat_fukuda(const int matsize, const double *mata, const double *matb, double *matc);
void mulMat_yamazaki(const int matsize, const double *mata, const double *matb, double *matc);
void mulMat_goto(const int matsize, const double *mata, const double *matb, double *matc);
void mulMat_kazawa(const int matsize, const double *mata, const double *matb, double *matc);
void mulMat_miyamoto(const int matsize, const double *mata, const double *matb, double *matc);
void mulMat_inoue(const int matsize, const double *mata, const double *matb, double *matc);

#endif

