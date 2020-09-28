#ifndef ComplexMatrix_h
#define ComplexMatrix_h

#include "complex.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ComplexMatrix
{
public:
	//MatrixMath1();
	void Print(Complex* A, int m, int n, String label,int precision);
	//void Copy(double* A, int n, int m, double* B);
	void Multiply(Complex* A, Complex* B, int m, int p, int n, Complex* C);
	void Add(Complex* A, Complex* B, int m, int n, Complex* C);
	void Subtract(Complex* A, Complex* B, int m, int n, Complex* C);
	void Transpose(Complex* A, int m, int n, Complex* C);
	//void Scale(double* A, int m, int n, double k);
	//int Invert(double* A, int n);
	float Maximum(Complex* A, int m, int n,float maximum);
	void Identity(int m, int n,Complex* A);
};

extern ComplexMatrix ComplexMat;
#endif
