#include <MatrixMath1.h>
#define N  (3) //rows
#define M  (2) //coloumns


double A[N][M];
double B[N][M];
double C[N][M];
double v[N];      // This is a row vector
double w[N];
double max = 10;  // maximum random matrix entry range
String str;
String s="enter ";
String s1= "value";
int pre=5;
void setup() {
	Serial.begin(9600); 
        Serial.setTimeout(10);
        // Initialize matrices
        for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < M; j++)
          {
          Serial.println("Enter value of matrix A");
          Serial.println(s+i+j+s1);
          while(Serial.available()==0){}
          str=Serial.readString();
          Serial.println(str);
            A[i][j] = str.toFloat(); //random(max) - max/2.0f;  // A is random
            /*if (i == j)
            {
              B[i][j] = 1.0f;                  // B is identity
            } else
            { 
              B[i][j] = 0.0f;
            }*/
          }
        }
        for(int i=0;i<N; i++)
        {
          Serial.println("Enter value of matrix V");
          Serial.print(s+i+s1);
          while(Serial.available()==0){}
          str=Serial.readString();
          Serial.println(str);
          v[i] = str.toFloat();
        }

}

void loop(){

  //Matrix1.Multiply((double*)A,(double*)B,N,N,N,(double*)C);

        //Serial.println("\nAfter multiplying C = A*B:");
	Matrix1.Print((double*)A,N,M,"A",pre);

	Matrix1.Print((double*)B,N,M,"B",pre);
	//Matrix1.Print((double*)C,N,N,"C",pre);
       Matrix1.Print((double*)v,N,1,"v",pre);

       /*Matrix1.Add((double*) B, (double*) C, N, N, (double*) C);
        Serial.println("\nC = B+C (addition in-place)");
        Matrix1.Print((double*)C,N,N,"C",pre);
        Matrix1.Print((double*)B,N,N,"B",pre);

        Matrix1.Copy((double*)A,N,N,(double*)B);
        Serial.println("\nCopied A to B:");
	Matrix1.Print((double*)B,N,N,"B",pre);

        Matrix1.Invert((double*)A,N);
        Serial.println("\nInverted A:");
	Matrix1.Print((double*)A,N,N,"A",pre);

        Matrix1.Multiply((double*)A,(double*)B,N,N,N,(double*)C);
        Serial.println("\nC = A*B");
	Matrix1.Print((double*)C,N,N,"C",pre);

        // Because the library uses pointers and DIY indexing,
        // a 1D vector can be smoothly handled as either a row or col vector
        // depending on the dimensions we specify when calling a function
        Matrix1.Multiply((double*)C,(double*)v,N,N,1,(double*)w);
        Serial.println("\n C*v = w:");
        Matrix1.Print((double*)v,N,1,"v",pre);
        Matrix1.Print((double*)w,N,1,"w",pre);*/

while(1);
}
