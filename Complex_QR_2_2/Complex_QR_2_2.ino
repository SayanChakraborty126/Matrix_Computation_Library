#include <complex.h>

#include <ComplexHouseholder.h>


#include <ComplexMatrix1.h>

#define N (2)
#define P (1)

Complex A[N][N];
Complex X[N][P];
int pre = 3;
double r;
double im;
String s = "enter ";
String s1 = "value";
Complex c1(0, 0);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(25);
  Serial.println("Enter a vector");
  for (int i = 0; i < N ; i++)
  {
    for (int j = 0; j < N; j++)
    {
      Serial.println(s + i + j + s1);
      Serial.println("input real part");
      while (Serial.available() == 0) {}
      String str1 = Serial.readString();
      r = str1.toFloat();
      Serial.println(r);
      Serial.println("input imaginery part");
      while (Serial.available() == 0) {}
      String str2 = Serial.readString();
      im = str2.toFloat();
      Serial.println(im);
      A[i][j].set(r, im);
    }
  }

}

void loop() {

  ComplexMat1.Print((Complex*)A, N, N, "A", pre);
  int k = 1;

  int t1 = millis();
  for (int x = 0; x < k; x++)
  {

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < P; j++)
      {
        X[i][j] = A[i][j];
      }
    }
    //ComplexMat1.Print((Complex*)X, N,P, "X", pre);
    Complex Y[N][P];
    Complex R[N][N];
    Complex H[N][N];
    ComplexHouse.ComplexHldr((Complex*)X, N, P, (Complex*)Y, (Complex*)H, pre);
    //ComplexMat1.Print((Complex*)H, N, N, "Q", pre);
    ComplexMat1.Mult((Complex*)H, (Complex*)A , N, N, N, (Complex*)R );
    //ComplexMat1.Print((Complex*)R, N, N, "R", pre);
    ComplexMat1.Mult((Complex*)R, (Complex*)H , N, N, N, (Complex*)A );
    double m = A[1][0].modulus();
    if (m > 0.001)
    {
      k++;
    }


  }
  int t2 = millis();
  ComplexMat1.Print((Complex*)A, N, N, "Ak", pre);
  Serial.print("iterations: ");
  Serial.println(k);
  Serial.print("time of computation: ");
  Serial.print(t2-t1, pre);
  Serial.println(" millisecond");


  while (1);
}
