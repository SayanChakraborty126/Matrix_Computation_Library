#include <complex.h>

//#include "complex.h"

#define N (3)
#define M (3)
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
  Serial.println("A");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      r = A[i][j].real();
      im = A[i][j].imag();
      c1.set(r, im);
      Serial.print(c1);
      Serial.print("\t");
    }
    Serial.println();
  }

  Serial.println("B");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      r = B[i][j].real();
      im = B[i][j].imag();
      c1.set(r, im);
      Serial.print(c1);
      Serial.print("\t");
    }
    Serial.println();
  }
  //****************************************************//

  //*********multiply complex matrix********************//
  int p = 3;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      c3.set(0, 0);
      for (int k = 0; k < p; k++)
      {
        double r1 = A[i][k].real();
        double im1 = A[i][k].imag();
        double r2 = B[k][j].real();
        double im2 = B[k][j].imag();
        c1.set(r1, im1);
        c2.set(r2, im2);
        c3 = c3 + (c1 * c2);
        double r3 = c3.real();
        double im3 = c3.imag();
        C[i][j].set(r3, im3)  ;

      }
    }
  }

  Serial.println("C=A*B");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      r = C[i][j].real();
      im = C[i][j].imag();
      c1.set(r, im);
      Serial.print(c1);
      Serial.print("\t");
    }
    Serial.println();
  }
  //*************************************************//

  //**************transpose complex matrix************//
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      r = A[i][j].real();
      im = A[i][j].imag();
      C[j][i].set(r, im);
    }
  }

  Serial.println("A'");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      r = C[i][j].real();
      im = C[i][j].imag();
      c1.set(r, im);
      Serial.print(c1);
      Serial.print("\t");
    }
    Serial.println();
  }
  //********************************************//

  //************conjugate matrix***************//

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      B[i][j] = C[i][j].conjugate();
    }
  }
  Serial.println("A* (here,A* = conjugate transpose of A)");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      r = B[i][j].real();
      im = B[i][j].imag();
      c1.set(r, im);
      Serial.print(c1);
      Serial.print("\t");
    }
    Serial.println();
  }
  //*****************************************//

  //********a vector X from A***********//
  Complex X[N][P];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < P; j++)
    {
      X[i][j] = A[i][j];
    }
  }
  Serial.println("X");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < P; j++)
    {
      r = X[i][j].real();
      im = X[i][j].imag();
      c1.set(r, im);
      Serial.print(c1);
      Serial.print("\t");
    }
    Serial.println();
  }
  //*************************************//

  //***********norm of complex vector****//
  double norm;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < P; j++)
    {
      r = X[i][j].real();
      im = X[i][j].imag();
      norm = norm + (pow(r, 2) + pow(im, 2));
    }
  }
  norm = sqrt(norm);
  Serial.print("norm = ");
  Serial.println(norm, pre);
  //************************************//

  //***********max value from complex vector*****//

  double maximum = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < P; j++)
    {
      double m = X[i][j].modulus();
      double p = X[i][j].phase();
      maximum = max(maximum, m);
      c1.polar(m, p);
    }
  }

  Serial.print("maximum is: ");
  Serial.println(maximum, pre);
  Serial.println(c1);

  //*******************************************//

  //***********Addition of complex matrix******//

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  Serial.println("Addition: A+A*");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      Serial.print(C[i][j]);
      Serial.print("\t");
    }
    Serial.println();
  }

  //************************************//

  //**********subtraction of complex matrix************//
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  Serial.println("Addition: A-A*");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      Serial.print(C[i][j]);
      Serial.print("\t");
    }
    Serial.println();
  }
  //***************************************************//

  //*****************identity matrix*****************//
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (i == j)
      {
        C[i][j].set(1, 0);
      }
      else
      {
        C[i][j].set(0, 0);
      }
    }
  }
  Serial.println("Identity matrix*");
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      Serial.print(C[i][j]);
      Serial.print("\t");
    }
    Serial.println();
  }
  //*******************************************//

  while (1);
}
