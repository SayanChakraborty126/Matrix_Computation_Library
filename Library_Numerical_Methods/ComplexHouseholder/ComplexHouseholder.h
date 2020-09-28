#ifndef ComplexHouseholder_h
#define ComplexHouseholder_h

#include "ComplexMatrix1.h"
#include "Complex.h"
//#include "uURut.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ComplexHouseholder
{
public:
	//Householder();
	void ComplexHldr(Complex* A, int m, int n, Complex* Y,Complex* H, int precision);
	/*void uMat(Complex* A, int m, int n, Complex* u,float norm, float max,int precision);
	void UMat(Complex* u, int m, int n,Complex* U,int precision);
	void HMat(Complex* Z, int m, int n,int precision);*/
};

extern ComplexHouseholder ComplexHouse;
#endif
