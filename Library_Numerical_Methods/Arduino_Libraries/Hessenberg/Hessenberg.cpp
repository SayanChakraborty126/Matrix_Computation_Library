#include "Hessenberg.h"
#include "Householder.h"
#include "MatrixMath1.h"


#define NR_END 1

Hessenberg Hessen;



void Hessenberg::hess(double* A, int m, int n,int p,double* H1,int precision)
{
double X1[m-1][p];
//double X2[N-2][p];
//double X3[N-3][p];
double Y[m][p];
double h1[(m-1)][(m-1)];
//double h2[(N-2)][(N-2)];
//double H1[m][m];
//double H2[N][N];
double H1T[m][m];
//double H2T[N][N];
//double Q[N][N];
//double A2[N][N];
double L[m][m];
//double A1[N][N];
int k =0;

	
	for(int j=0; j<(m-2); j++)
  {
    if(j==0)
    {
    for(int i=0; i<(m-(1+k)); i++)
    {
      
      X1[i][j]=A[n*(i+1)+j];
   
    }
    }
    
    k++;
    
   }
   Matrix1.Print((double*)X1,(m-1),p,"X1",precision);
   
   House.Hldr((double*)X1,(m-1),p,(double*)Y, (double*)h1,precision);
   
	//Matrix1.Print((double*)h1,(m-1),(m-1),"h1",precision);
	Matrix1.Identity(m,m,(double*)H1);
  for(int i=0; i<m-1; i++)
  {
    for(int j=0; j<m-1; j++)
    {
      H1[n*(i+1)+(j+1)]=h1[i][j];
    }
  }
   Matrix1.Print((double*)H1,m,m,"H1(Householder matrix)",precision);
   
  
   //Matrix1.Print((double*)H2,N,N,"H2",pre);
   Matrix1.Transpose((double*)H1,m,m,(double*)H1T);
   Matrix1.Multiply((double*)H1,(double*)A,m,m,m,(double*)L);
   Matrix1.Multiply((double*)L,(double*)H1T,m,m,m,(double*)H1);
   //Matrix1.Print((double*)H1,m,m,"A1=Hu(Hessenberg matrix)",precision);
   
    /* for(int j=0; j<(N-3); j++)
  {
    for(int i=0; i<(N-(2)); i++)
    {
        X2[i][0]=A1[i+2][1]; 
    }
    
    
    //k++;
    
   }
   Matrix1.Print((double*)X2,(N-2),M,"X2",pre);
  House.Hldr((double*)X2,(N-2),M,(double*)Y, (double*)h2,pre);
  Matrix1.Identity(N,N,(double*)H2);
  for(int i=0; i<N-2; i++)
  {
    for(int j=0; j<N-2; j++)
    {
      H2[i+2][j+2]=h2[i][j];
    }
  }
  Matrix1.Print((double*)H2,N,N,"H2",pre);
  Matrix1.Transpose((double*)H2,N,N,(double*)H2T);
   Matrix1.Multiply((double*)H2,(double*)A1,N,N,N,(double*)Q);
   Matrix1.Multiply((double*)Q,(double*)H2T,N,N,N,(double*)A2);
   Matrix1.Print((double*)A2,N,N,"A2",pre);*/
	
	
	
}
