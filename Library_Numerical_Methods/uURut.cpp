#include "uURut"
#include "Householder.h"
#include "MatrixMath1.h"

#define NR_END 1

Householder House;

void uURut::uMat(double* A, int m, int n,int norm; int max;double* u,double* U)
{
	for (int i = 0; i < m; i++)
        {                   
          for (int j = 0; j < n; j++)
          {
          	if(i==j)
          	{
          		u[n*i+j]=((A[n*0+0])/maximum1) + norm;
			}
            else
			{
				u[n*i+j] = (A[n*i+j])/maximum1; 
			}
        }
        }
	Matrix1.Print(u,m,n,l,precision);
	
	
	
}