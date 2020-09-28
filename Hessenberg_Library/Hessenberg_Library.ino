#include <Hessenberg.h>

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
      
}

void loop() 
{
//  Serial.println("Page no.-363,Example 9.32, chapter 9");
//  Serial.println("Numerical Linear algebra- Prof. BN Datta");
  
  double H[N][N];
  //Matrix1.Print((double*)A,N,N,"A",pre);
  Hessen.hess((double*)A,N,N,M,(double*)H, pre);
  Matrix1.Print((double*)H,N,N,"A1=Hu(Hessenberg matrix)",pre);
  while(1);

}
