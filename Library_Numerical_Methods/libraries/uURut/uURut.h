#ifndef uU_h
#define uU_h

#include "MatrixMath1.h"
#include "Householder.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class uURut
{
public:
	//Householder();
	void uMat(double* A, int m, int n, double* u,double* U);
	
};

extern uURut u;
#endif