#include <ComplexMatrix1.h>

#include <complex.h>

#define N (2)
#define M (2)
#define P (1)
int pre = 5;
Complex A[N][M];
Complex B[N][M];
double r = 0;
double im = 0;
Complex c1(0, 0);
Complex c2(0, 0);
Complex c3(0, 0);
String s = "enter ";
String s1 = "value";
Complex C[N][M];
float norm;
float maximum;
void setup() {

  Serial.begin(115200);
  Serial.setTimeout(25);

  for (int i = 0; i < N ; i++)
  {
    for (int j = 0; j < M; j++)
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

  for (int i = 0; i < N ; i++)
  {
    for (int j = 0; j < M; j++)
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
      B[i][j].set(r, im);
    }
  }

}

void loop() {

  //*****printing complex matrix********//
  ComplexMat1.Print((Complex*)A, N, M, "A", pre);
  ComplexMat1.Print((Complex*)B, N, M, "B", pre);
  //************************************//
  int t1 = micros();
  //*****multiply complex matrix********//
  ComplexMat1.Mult( (Complex*)A, (Complex*)B, N, M, N, (Complex*)C );
  ComplexMat1.Print((Complex*)C, N, M, "C=A*B", pre);
  //***********************************//

  //*******transpose complex matrix****//
  ComplexMat1.Transpose((Complex*)A, N, M, (Complex*)C);
  ComplexMat1.Print((Complex*)C, N, M, "A'", pre);
  //***********************************//

  //****conjugate of complex matrix****//
  ComplexMat1.Conj((Complex*)C, N, M, (Complex*)B);
  ComplexMat1.Print((Complex*)B, N, M, "A*", pre);
  //***********************************//

  //*******addition of complex matrices****//

  ComplexMat1.Add((Complex*)A, (Complex*)B, N, M, (Complex*)C);
  ComplexMat1.Print((Complex*)C, N, M, "A+A*", pre);

  //***********************************//

  //********subtraction of complex matrices****//

  ComplexMat1.Subtract((Complex*)A, (Complex*)B, N, M, (Complex*)C);
  ComplexMat1.Print((Complex*)C, N, M, "A-A*", pre);

  //******************************************//

  //**********identity matrix**************//
  ComplexMat1.Identity(N, M, (Complex*)C);
  ComplexMat1.Print((Complex*)C, N, M, "I", pre);
  //*************************************//
  int t2 = micros();

  Serial.println(t2 - t1);











  while (1);
}




