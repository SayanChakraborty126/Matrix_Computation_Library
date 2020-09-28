#include <Householder.h>

#include <MatrixMath1.h>
#define N  (3)//rows
#define M  (1)//coloumns
float norm;
double A[N][N];


int pre = 5;
int k=0;
String s="enter ";
String s1= "value";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
 for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < N; j++)
          {
          Serial.println("Enter value of matrix A");
          Serial.println(s+i+j+s1);
          while(Serial.available()==0){}
          String str=Serial.readString();
          Serial.println(str);
            A[i][j] = str.toFloat(); 
          
          }
        }
       /* for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < N; j++)
          {
          Serial.println("Enter value of matrix A");
          Serial.println(s+i+j+s1);
          while(Serial.available()==0){}
          String str=Serial.readString();
          Serial.println(str);
            A[i][j] = str.toFloat(); 
          
          }
        }*/
        

}

void loop() {
  Serial.println("Page no.-361,Example 9.31, chapter 9");
  Serial.println("Numerical Linear algebra- Prof. BN datta");
  
  double X1[N-1][M];
//double X2[N-2][M];
//double X3[N-3][M];
double Y[N][M];
double h1[(N-1)][(N-1)];
//double h2[(N-2)][(N-2)];
double H1[N][N];
//double H2[N][N];
double H1T[N][N];
//double H2T[N][N];
//double Q[N][N];
//double A2[N][N];
double L[N][N];
//double A1[N][N];
  
  
  
  
  
  
  
  
   Matrix1.Print((double*)A,N,N,"A",pre);
 
  for(int j=0; j<(N-2); j++)
  {
    if(j==0)
    {
    for(int i=0; i<(N-(1+k)); i++)
    {
      
      X1[i][j]=A[i+1][j];
   
    }
    }
    
    k++;
    
   }
   Matrix1.Print((double*)X1,(N-1),M,"X1",pre);
   
   
  House.Hldr((double*)X1,(N-1),M,(double*)Y, (double*)h1,pre);
  //Matrix1.Print((double*)h1,(N-1),(N-1),"h1",pre);
  
  //
  //Matrix1.Print((double*)h2,(N-2),(N-2),"h2",pre);
  
  Matrix1.Identity(N,N,(double*)H1);
  for(int i=0; i<N-1; i++)
  {
    for(int j=0; j<N-1; j++)
    {
      H1[i+1][j+1]=h1[i][j];
    }
  }
   Matrix1.Print((double*)H1,N,N,"H1(Householder matrix)",pre);
   
  
   //Matrix1.Print((double*)H2,N,N,"H2",pre);
   Matrix1.Transpose((double*)H1,N,N,(double*)H1T);
   Matrix1.Multiply((double*)H1,(double*)A,N,N,N,(double*)L);
   Matrix1.Multiply((double*)L,(double*)H1T,N,N,N,(double*)H1);
   Matrix1.Print((double*)H1,N,N,"A1=Hu(Hessenberg matrix)",pre);
   
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
    //Matrix1.Transpose((double*)H2,N,N,(double*)H2T);
  
   
   
    
  
  
 while(1);

}
