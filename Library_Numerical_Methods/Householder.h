#ifndef Householder_h
#define Householder_h

#include MatrixMath1.h
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class Householder
{
public:
	//Householder();
	void Householder(double* A, int m, int n);
	
};

extern Householder House;
#endif