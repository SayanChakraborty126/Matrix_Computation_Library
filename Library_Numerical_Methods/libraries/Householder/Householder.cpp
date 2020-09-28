#include "Householder.h"
#include "MatrixMath1.h"


#define NR_END 1

Householder House;



void Householder::Hldr(double* A, int m, int n, double* Y,double* H,int precision)

{
	
	double I[m][m];
	double u[m][n];
	double U[n][m];
	double p[m][m];
	double P[m][m];
    double Q[n][n];
    double Z[m][m];
    //double H[m][m];
	
	for (int i=0;i<m;i++)
	{
	
		for(int j=0;j<m;j++)
		{
			if(i==j)
			{
				I[i][j] = 1.0;
			}
			else
			{
				I[i][j] = 0;
			}
			
		}
	
	}
	//Matrix1.Print((double*)I,m,m,"I",precision);
	
	float maximum,maximum1;
	String l="u";
	float norm1;
	float power=0;
	float norm;
	
	maximum1= Matrix1.Maximum(A,m,n,maximum);
	//Serial.print("Maximum value is:");
	//Serial.println(maximum1,precision);
	
	int i, j;
	for (i=0;i<m;i++)
	{
	
		for(j=0;j<n;j++)
		{
			
			norm1 = (pow((A[n*i+j]/maximum1),2));
			power = (power+norm1);
			
		}
	
	}
	norm = sqrt(power);
	//Serial.print("The 2 norm is: ");
	//Serial.println(norm,precision);
	
	House.uMat((double*)A,m,n,(double*)u,norm,maximum1,precision);
	//Matrix1.Print((double*)u,m,n,"u",precision);
	
	Matrix1.Transpose((double*)u,m,n,(double*)U);
//	Matrix1.Print((double*)U,n,m,"U",precision);
	
	Matrix1.Multiply((double*)u,(double*)U,m,n,m,(double*)p);
//	Matrix1.Print((double*)p,m,m,"p",precision);
	
	for (int i = 0; i < m; i++)
        {                   
          for (int j = 0; j < m; j++)
          {
         
            P[i][j] = 2*(p[i][j]); 
          
          }
        }

	
	Matrix1.Multiply((double*)U,(double*)u,n,m,n,(double*)Q);
	/*u[m][n]=0;
	U[n][m]=0;*/

	for (int i = 0; i < m; i++)
        {                   
          for (int j = 0; j < m; j++)
          {
         
            Z[i][j] = (P[i][j])/(Q[0][0]); 
          
          }
        }
   
	/*p[m][m]=0;
	P[m][m]=0;
    Q[n][n]=0;*/
    
    Matrix1.Subtract((double*) I, (double*) Z, m, m, (double*) H);
    //Matrix1.Print((double*)H,m,m,"H",precision);
    //I[m][m]=0;
    Matrix1.Multiply((double*)H,(double*)A,m,m,n,(double*)Y);
    //Serial.println("The result of the Algorithm: ");
    
    
    
    
	
}


//eigen vector Routine	
void Householder::uMat(double* A, int m, int n,double* u,float norm,float max,int precision)
{
	
	for (int i = 0; i < m; i++)
        {                   
          for (int j = 0; j < n; j++)
          {
          	if(i==j)
          	{
          		if(abs(A[n*0+0])== A[n*0+0])
          		{
          			u[n*i+j]=((A[n*0+0])/max) + norm;
				}
          		else
          		{
          			u[n*i+j]=((A[n*0+0])/max) - norm;
				}
          	}
            else
			{
				u[n*i+j] = (A[n*i+j])/max; 
			}
        }
        }
    //Matrix1.Print(u,m,n,"u",precision);
    //House.UMat(u,m,n,U,precision);
}


/*void Householder::HMat(double* Z, int m, int n,int precision)
{
	double I[m][m];
	int i, j;
	for (int i=0;i<m;i++)
	{
	
		for(int j=0;j<m;j++)
		{
			if(i==j)
			{
				I[i][j] = 1.0;
			}
			
		}
	
	}
	//Matrix1.Identity(m,m,(double*)I);
	Matrix1.Print((double*)I,m,m,"I",precision);
}*/










