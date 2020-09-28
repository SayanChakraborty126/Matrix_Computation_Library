#ifndef Hessenberg_h
#define Hessenberg_h

#include "MatrixMath1.h"
#include "Householder.h"
//#include "uURut.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Hessenberg
{
public:
	//Householder();
	void hess(double* A, int m, int n,int p,double* H, int precision);
	
};

extern Hessenberg Hessen;
#endif
