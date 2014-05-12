#ifndef MATFUNC_H
#define MATFUNC_H

//void testMulMat(const int matsize, const double *mata, const double *matb, const double *matc);

double diffMat(const int matsize, const double *mata, const double *matb);
double checkMulMatFunc(void (*func)(const int matsize, const double *mata, const double *matb, double *matc),
		       const int matsize,
		       const double *mata,
		       const double *matb,
		       const double *matc);

double* allocMat(const int matsize);
void freeMat(double *mat);
void genMat(const int matsize, double *mat);
void printMat(const int matsize, const double *mat);

void writeMat(const int matsize, const double *mat, const char *filename);
int readMat(double *mat, const char *filename);

void clearMat(const int matsize, double *mat);
void mulMatSample(const int matsize, const double *mata, const double *matb, double *matc);

#endif
