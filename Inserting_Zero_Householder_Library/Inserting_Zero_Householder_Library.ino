#include <Householder.h>

#include <MatrixMath1.h>
#define N  (4)//rows
#define M  (1)//coloumns
float norm;
double X[N][M];
double Y[N][M];
double H[N][N];
int pre = 5;
String str;
String s="enter ";
String s1= "value";

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(25);
  for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < M; j++)
          {
          Serial.println("Enter value of matrix X");
          Serial.println(s+i+j+s1);
          while(Serial.available()==0){}
          str=Serial.readString();
          Serial.println(str);
            X[i][j] = str.toFloat(); 
          
          }
        }

}

void loop() {
 
  Matrix1.Print((double*)X,N,M,"X",pre);
  House.Hldr((double*)X,N,M,(double*)Y, (double*)H,pre);
  Matrix1.Print((double*)H,N,N,"H",pre);
  Matrix1.Print((double*)Y,N,M,"Y",pre);
  
  
 while(1);

}
