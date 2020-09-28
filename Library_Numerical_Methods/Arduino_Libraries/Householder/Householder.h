#ifndef Householder_h
#define Householder_h

#include "MatrixMath1.h"
//#include "uURut.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Householder
{
public:
	//Householder();
	void Hldr(double* A, int m, int n, double* Y,int precision);
	void uMat(double* A, int m, int n, double* u,float norm, float max,int precision);
	void UMat(double* u, int m, int n,double* U,int precision);
	void HMat(double* Z, int m, int n,int precision);
};

extern Householder House;
#endif
