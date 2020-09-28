#include <Householder.h>

#include <MatrixMath1.h>
#define N  (3)//rows
#define M  (1)//coloumns
float norm;
double A[N][N];

float offdiag1;
float offdiag2;
float offdiag3;
int iter = 1;
int pre = 4;
int k = 0;
String s = "enter ";
String s1 = "value";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(25);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < (N); j++)
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
  double X2[N - 1][M];
  //double X3[N-3][M];
  double Y[N][M];
  double Y1[N][M];
  double h1[(N)][(N)];
  double h2[(N - 2)][(N - 2)];
  double H1[N][N];
  double H2[N][N];
  double H1T[N][N];
  //double H2T[N][N];
  double Q[N][N];
  //double A2[N][N];
  double A1[N][N];
  double A2[N][N];



  float t1 = millis();
  for (int i = 0; i < iter; i++)
  {
    for (int j = 0; j < (M); j++)
    {

      for (int i = 0; i < (N); i++)
      {

        X1[i][j] = A[i][j];

      }
    }
    //Matrix1.Print((double*)X1, (N), M, "X1", pre);


    House.Hldr((double*)X1, (N), M, (double*)Y, (double*)h1, pre);

    Matrix1.Multiply((double*)h1, (double*)A, N, N, N, (double*)A1);
    //Matrix1.Print((double*)A1, N, N, "A1", pre);

    for (int j = 0; j < (M); j++)
    {

      for (int i = 0; i < (N - 1); i++)
      {

        X2[i][j] = A1[i + 1][j + 1];

      }
    }
    // Matrix1.Print((double*)X2, (N - 1), M, "X2", pre);
    House.Hldr((double*)X2, (N - 1), M, (double*)Y, (double*)h2, pre);
    // Matrix1.Print((double*)h2, (N - 1), (N - 1), "h2", pre);
    h2[1][1] = abs(h2[0][0]);

    Matrix1.Identity(N, N, (double*)H2);
    for (int i = 0; i < (N - 1); i++)
    {
      for (int j = 0; j < (N - 1); j++)
      {
        H2[i + 1][j + 1] = h2[i][j];
      }
    }

    // Matrix1.Print((double*)H2, N, N, "H2", pre);
    Matrix1.Multiply((double*)H2, (double*)A1, N, N, N, (double*)A2);
    //Matrix1.Print((double*)A2, N, N, "A2=R", pre);
    Matrix1.Multiply((double*)h1, (double*)H2, N, N, N, (double*)Q);
    //Matrix1.Print((double*)Q, N, N, "Q", pre);
    Matrix1.Multiply((double*)A2, (double*)Q, N, N, N, (double*)A);
    offdiag1 = abs(A[1][0]);
    offdiag2 = abs(A[2][0]);
    offdiag3 = abs(A[2][1]);
    if (((offdiag1) > 0.0001) || ((offdiag2) > 0.0001) || ((offdiag3) > 0.0001)  )
    {
      iter++;
    }

  }
  float t2 = millis() - t1;
  Matrix1.Print((double*)A, N, N, "A", pre);
  Serial.println(iter);
  Serial.println(t2);


  while (1);

}
