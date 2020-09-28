
#include "ComplexMatrix.h"
#include "Complex.h"

#define NR_END 1

ComplexMatrix ComplexMat;			// Pre-instantiate

// Matrix Printing Routine
// Uses tabs to separate numbers under assumption printed double width won't cause problems
void ComplexMatrix::Print(Complex* A, int m, int n, String label, int precision){
	// A = input matrix (m x n)
	Complex c1(0,0);
	int i,j;
	Serial.println();
	Serial.println(label);
	for (i=0; i<m; i++){
		for (j=0;j<n;j++){
			double r=A[n*i+j].real();
			double im = A[n*i+j].imag();
			c1.set(r, im);
			Serial.print(c1);
			Serial.print(" ");
		}
		Serial.println();
	}
	
}



//highest number in an entered matrix
/*float MatrixMath1::Maximum(double* A, int m, int n, float maximum1)
{
		
	maximum1=0;
	 for(int i=0; i<m ; i++)
    {
    for(int j=0; j<n; j++)
    {
       (maximum1)=max(maximum1,abs(A[n*i+j]));
    }
   }
   return abs(maximum1);
	
	
	
    
    
}

void MatrixMath1::Identity(int m, int n,double* A)
{
	
	
	int i, j;
	for (i=0;i<m;i++)
	{
	
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				A[n*i+j] = 1.0f;
			}
			else
			{
				A[n*i+j] =0;
			}
			
		}
	
	}
}



//Matrix Multiplication Routine
// C = A*B
void MatrixMath1::Multiply(double* A, double* B, int m, int p, int n, double* C)
{
	// A = input matrix (m x p)
	// B = input matrix (p x n)
	// m = number of rows in A
	// p = number of columns in A = number of rows in B
	// n = number of columns in B
	// C = output matrix = A*B (m x n)
	int i, j, k;
	for (i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			C[n*i+j]=0;
			for (k=0;k<p;k++)
				C[n*i+j]= C[n*i+j]+A[p*i+k]*B[n*k+j];
		}
}


//Matrix Addition Routine
void MatrixMath1::Add(double* A, double* B, int m, int n, double* C)
{
	// A = input matrix (m x n)
	// B = input matrix (m x n)
	// m = number of rows in A = number of rows in B
	// n = number of columns in A = number of columns in B
	// C = output matrix = A+B (m x n)
	int i, j;
	for (i=0;i<m;i++)
		for(j=0;j<n;j++)
			C[n*i+j]=A[n*i+j]+B[n*i+j];
}


//Matrix Subtraction Routine
void MatrixMath1::Subtract(double* A, double* B, int m, int n, double* C)
{
	// A = input matrix (m x n)
	// B = input matrix (m x n)
	// m = number of rows in A = number of rows in B
	// n = number of columns in A = number of columns in B
	// C = output matrix = A-B (m x n)
	int i, j;
	for (i=0;i<m;i++)
		for(j=0;j<n;j++)
			C[n*i+j]=A[n*i+j]-B[n*i+j];
}


//Matrix Transpose Routine
void MatrixMath1::Transpose(double* A, int m, int n, double* C)
{
	// A = input matrix (m x n)
	// m = number of rows in A
	// n = number of columns in A
	// C = output matrix = the transpose of A (n x m)
	int i, j;
	for (i=0;i<m;i++)
		for(j=0;j<n;j++)
			C[m*j+i]=A[n*i+j];
}*/






