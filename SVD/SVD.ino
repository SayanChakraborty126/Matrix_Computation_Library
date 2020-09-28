#include <Householder.h>

#include <MatrixMath1.h>
#define N  (3)//rows
#define M  (1)//coloumns
float norm;
double A[N][N];


int pre = 5;
int k = 0;
String s = "enter ";
String s1 = "value";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(25);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      Serial.println("Enter value of matrix A");
      Serial.println(s + i + j + s1);
      while (Serial.available() == 0) {}
      String str = Serial.readString();
      Serial.println(str);
      A[i][j] = str.toFloat();

    }
  }

}

void loop() {

  double X1[N][M];
  double Y[N][M];
  double U01[(N)][(N)];
  double A1[N][N];
  double x[M][(N - 1)];
  double X2[(N - 1)][M];
  double U[N - 1][N - 1];
  double V01[N][N];

  Matrix1.Print((double*)A, N, N, "A", pre);

  for (int j = 0; j < (M); j++) //coloumn entry
  {

    for (int i = 0; i < (N); i++) //row entry
    {

      X1[i][j] = A[i][j];

    }

  }
 // Matrix1.Print((double*)X1, (N), M, "X1", pre);
  House.Hldr((double*)X1, (N), M, (double*)Y, (double*)U01, pre);

 // Matrix1.Print((double*)U01, (N), (N), "U01", pre);
  Matrix1.Multiply((double*)U01, (double*)A, N, N, N, (double*)A1);
 // Matrix1.Print((double*)A1, (N), (N), "A1", pre);

  for (int i = 0; i < 1 ; i++)
  {
    for (int j = 0; j < (N - 1); j++)
    {
      x[i][j] = A1[i][j + 1];
    }
  }


  Matrix1.Transpose((double*)x, (M), (N - 1), (double*)X2);
 // Matrix1.Print((double*)X2, (N - 1), M, "X2", pre);

  House.Hldr((double*)X2, (N - 1), M, (double*)Y, (double*)U, pre);
 // Matrix1.Print((double*)U, (N - 1), (N-1), "U", pre);

  Matrix1.Identity(N, N, (double*)V01);
  for (int i = 0; i < (N - 1); i++)
  {
    for (int j = 0; j < (N - 1); j++)
    {
      V01[i + 1][j + 1] = U[i][j];
    }
  }

 // Matrix1.Print((double*)V01, (N), (N), "V01", pre);
  Matrix1.Multiply((double*)A1, (double*)V01, N, N, N, (double*)U01);
  //Matrix1.Print((double*)U01, (N), (N), "A2", pre);

  for (int j = 0; j < 1; j++)
  {
    for (int i = 0; i < (N - 1); i++)
    {
      X2[i][j] = U01[i + 1][j + 1];
    }
  }
 // Matrix1.Print((double*)X2, (N-1), (M), "X3", pre);
  House.Hldr((double*)X2, (N - 1), M, (double*)Y, (double*)U, pre);
 // Matrix1.Print((double*)U, (N-1), (N-1), "V", pre);

  Matrix1.Identity(N, N, (double*)V01);
  for (int i = 0; i < (N - 1); i++)
  {
    for (int j = 0; j < (N - 1); j++)
    {
      V01[i + 1][j + 1] = U[i][j];
    }
  }
 // Matrix1.Print((double*)V01, (N), (N), "U02", pre);
  Matrix1.Multiply((double*)V01, (double*)U01, N, N, N, (double*)A1);
 Matrix1.Print((double*)A1, (N), (N), "A3", pre);




  while (1);

}
