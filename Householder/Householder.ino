#include <MatrixMath1.h>



#define N  (3)//rows
#define M  (1)//coloumns
int m;
double x[M][M];
int maximum;
double X[N][M];
double u[N][M];
double U[M][N];
double I[N][N];
double H[N][N];
double p[N][N];
double P[N][N];
double Q[M][M];
double Z[N][N];
double Y[N][M];
String str;
String s="enter ";
String s1= "value";
int pre=5;
float norm;
void setup() {
	Serial.begin(9600); 
        Serial.setTimeout(10);
        // Initialize matrices
        for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < M; j++)
          {
          Serial.println("Enter value of matrix X");
          Serial.println(s+i+j+s1);
          while(Serial.available()==0){}
          str=Serial.readString();
          Serial.println(str);
            X[i][j] = str.toFloat(); //random(max) - max/2.0f;  // A is random
          
          }
        }
        
        
        for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < N; j++)
          {
          Serial.println("Enter value of matrix I");
          Serial.println(s+i+j+s1);
          while(Serial.available()==0){}
          str=Serial.readString();
          Serial.println(str);
            I[i][j] = str.toFloat(); //random(max) - max/2.0f;  // A is random
          
          }
        }

}

void loop(){

 // Matrix1.Multiply((double*)A,(double*)B,N,N,N,(double*)C);

        //Serial.println("\nAfter multiplying C = A*B:");
      Serial.println("Algorithm 7.1. Creating zeroes in a vector with Householder matrix(Numerical Linear Algebra, Chapter-7, Page-229)");
      Matrix1.Print((double*)X,N,M,"X",pre);
      Serial.println();
      maximum= Matrix1.Maximum((double*)X,N,M,m);
      Serial.print("maximum of X = ");
      Serial.println(maximum);
      
     // Matrix1.Print((double*)I,N,N,"I",pre);
      Serial.print("norm = ");
      norm=sqrt((pow((X[0][0])/4,2))+(pow((X[1][0])/4,2))+(pow((X[2][0])/4,2)));
      Serial.println(norm,5);
      u[0][0]=((X[0][0])/4) + norm;
      for (int i = 1; i < N; i++)
        {                   
          for (int j = 0; j < M; j++)
          {
          
            u[i][j] = (X[i][j])/4; //random(max) - max/2.0f;  // A is random
          
          }
        }
        Serial.println();
        Serial.println("The Householder vector is:");
        Matrix1.Print((double*)u,N,M,"u",pre);
        
        Matrix1.Transpose((double*)u, N, M, (double*)U);
       // Matrix1.Print((double*)U,M,N,"U",pre);
        
        Matrix1.Multiply((double*)u,(double*)U,N,M,N,(double*)p);
        //Matrix1.Print((double*)p,N,N,"p",pre);
        
        for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < N; j++)
          {
         
            P[i][j] = 2*(p[i][j]); //random(max) - max/2.0f;  // A is random
          
          }
        }
      // Matrix1.Print((double*)P,N,N,"P",pre);
       
        Matrix1.Multiply((double*)U,(double*)u,M,N,M,(double*)Q);
        //Matrix1.Print((double*)Q,M,M,"Q",pre);
        //Serial.println(Q[0][0],pre);
        
        for (int i = 0; i < N; i++)
        {                   
          for (int j = 0; j < N; j++)
          {
         
            Z[i][j] = (P[i][j])/(Q[0][0]); //random(max) - max/2.0f;  // A is random
          
          }
        }
        //Matrix1.Print((double*)Z,N,N,"Z",pre);
      
        
        Matrix1.Subtract((double*) I, (double*) Z, N, N, (double*) H);
        Matrix1.Print((double*)H,N,N,"H",pre);
        Serial.println();
         Serial.println("Result of the algorithm: ");
         Matrix1.Multiply((double*)H,(double*)X,N,N,M,(double*)Y);
         Matrix1.Print((double*)Y,N,M,"Y",pre);
      
	/*Matrix1.Print((double*)B,N,N,"B",pre);
	Matrix1.Print((double*)C,N,N,"C",pre);
        Matrix1.Print((double*)v,N,1,"v",pre);

       Matrix1.Add((double*) B, (double*) C, N, N, (double*) C);
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
