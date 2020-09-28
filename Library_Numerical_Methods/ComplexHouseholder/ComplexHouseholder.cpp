#include "ComplexHouseholder.h"
#include "ComplexMatrix1.h"
#include "Complex.h"


#define NR_END 1

ComplexHouseholder ComplexHouse;



void ComplexHouseholder::ComplexHldr(Complex* A, int m, int n, Complex* Y,Complex* H,int precision) //arg = (input vector, row, coloumn, output mat1, output householder mat, precision point )

{
	
	Complex I[m][m];
	Complex u[m][n];
	Complex uc[m][n];
	Complex U[n][m];
	Complex v[m][m];
	Complex a[m][m];
    Complex X1[n][n];
    Complex Z[m][m];
    Complex c1(0, 0);
    //Complex p1(0,0);
    //Complex H[m][m];
	
	for (int i=0;i<m;i++)
	{
	
		for(int j=0;j<m;j++)
		{
			if(i==j)
			{
				I[i][j].set(1,0);
			}
			else
			{
				I[i][j].set(0,0);
			}
			
		}
	
	}
	//Matrix1.Print((Complex*)I,m,m,"I",precision);
	
	double maximum = 0;
	double norm = 0;
	
	//******** computing maximum *********//
    for (int i = 0; i < m; i++)
   {
    for (int j = 0; j < n; j++)
    {
      double m = A[n*i+j].modulus();
      double p = A[n*i+j].phase();
      maximum = max(maximum, m);
      if (maximum == m)
      {
        c1.polar(m, p);
      }

     }
   }
   
    /*Serial.println("maximum is: ");
    Serial.println(maximum, precision);
    Serial.println(c1);*/
    
    //***********************************//
    
    //************ computing norm of normalized vector ********//
    
    for (int i = 0; i < m; i++)
   {
    for (int j = 0; j < n; j++)
    {
      Complex p = A[n*i+j]/(c1);
      double r = p.real();
      double im = p.imag();
      X1[i][j].set(r,im);
    }
   }

    for (int i = 0; i < m; i++)
   {
    for (int j = 0; j < n; j++)
    {
      Complex p = X1[i][j];
      double r= p.real();
      double im = p.imag();
      norm = norm + (pow(r, 2) + pow(im, 2));
    }
   }
    //ComplexMat1.Print((Complex*)X1, m, n, "normalised X", precision);
    norm = sqrt(norm);
    /*Serial.println("norm is: ");
    Serial.println(norm, 5);*/
    
    //******************************************************//
    
	//************* computing u vector ***********************//
	
	  double p = X1[0][0].phase();
  	  /*Serial.println("phase");
	  Serial.println(p);*/
	  double r = cos(p);
	  double im = sin(p);
	  c1.set(r, im);
	  /*Serial.println("cos()+j*sin()");
	  Serial.println(c1);*/
	  Complex nrm(norm, 0);
	
	  for (int i = 0; i < m; i++)
	  {
	    for (int j = 0; j < n; j++)
	    {
	      if (i == j)
	      {
	        Complex t = nrm * c1;
	
	        if ((abs(p) == p) || (p==0))
	        {
	          Complex x = X1[i][j] + t;
	          double r1 = x.real();
	          double im1 = x.imag();
	          u[i][j].set(r1, im1);
	        }
	        else
	        {
	          Complex x = X1[i][j] - t;
	          double r1 = x.real();
	          double im1 = x.imag();
	          u[i][j].set(r1, im1);
	        }
	      }
	      else
	      {
	        double r = X1[i][j].real();
	        double im = X1[i][j].imag();
	        u[i][j].set(r, im);
	      }
	
	
	    }
	  }
	  
	  //ComplexMat1.Print((Complex*)u, m, n, "u", precision);
	  
	  //********************************************************//
	
	 //************** computing (2uu*)/(u*u) **********************// ( * = conjugate transpose)
	 
	  ComplexMat1.Conj((Complex*)u, m, n, (Complex*)uc);
	  //ComplexMat1.Print((Complex*)uc, m, n, "u conjugate", precision);
	  ComplexMat1.Transpose((Complex*)uc, m, n, (Complex*)U);
	  //ComplexMat1.Print((Complex*)U, n, m, "u*", precision);
	
	  ComplexMat1.Mult((Complex*)u, (Complex*)U,  m, n, m, (Complex*)v );
	  //ComplexMat1.Print((Complex*)v, m, m, "uu*", precision);
	
	  ComplexMat1.Mult((Complex*)U, (Complex*)u,  n, m, n, (Complex*)a );
	  //ComplexMat1.Print((Complex*)a, n, n, "u*u", precision);
	
	  Complex b(2, 0);
	  b = b / (a[0][0]);
	
	  for (int i = 0; i < m; i++)
	  {
	    for (int j = 0; j < m; j++)
	    {
	      v[i][j] = b * v[i][j];
	    }
	  }
	  //ComplexMat1.Print((Complex*)v, m, m, "(2uu*)/(u*u)", precision);
	  
	  //********************************************************//
	  
	  //***************** computing H *****************************//
    
      ComplexMat1.Identity(m, m, (Complex*)I);

	  ComplexMat1.Subtract((Complex*)I, (Complex*)v, m, m, (Complex*)H);
	  //ComplexMat1.Print((Complex*)H, m, m, "H", precision);
	
	  ComplexMat1.Mult((Complex*)H, (Complex*)A,  m, m, n, (Complex*)Y);
	  //ComplexMat1.Print((Complex*)u, m, n, "H*X", precision);
	  
	  //*********************************************************//

    
    
    
    
	
}













