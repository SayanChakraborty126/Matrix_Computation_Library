#include <complex.h>

#include <ComplexMatrix1.h>

#define N (3)
#define P (1)

Complex X[N][P];

double r = 0;
double im = 0;
int pre = 5;
String s = "enter ";
String s1 = "value";
Complex c1(0, 0);

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(25);
  Serial.println("Enter a vector");
  for (int i = 0; i < N ; i++)
  {
    for (int j = 0; j < P; j++)
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
      X[i][j].set(r, im);
    }
  }

}

void loop() {
  Complex v[N][N];
  Complex u[N][P];
  Complex uc[N][P];
  Complex U[P][N];
  Complex a[P][P];
  Complex I[N][N];
  Complex H[N][N];
  ComplexMat1.Print((Complex*)X, N, P, "X", pre);

  double maximum = 0;
  double norm = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < P; j++)
    {
      double m = X[i][j].modulus();
      double p = X[i][j].phase();
      double r = X[i][j].real();
      double im = X[i][j].imag();
      maximum = max(maximum, m);
      c1.set(m, p);
      norm = norm + (pow(r, 2) + pow(im, 2));
    }
  }
  norm = sqrt(norm);
  Serial.println("maximum is: ");
  Serial.println(maximum, pre);
  Serial.println(c1);
  Serial.println("norm is: ");
  Serial.println(norm, 5);

  double p = X[0][0].phase();
  Serial.println("phase");
  Serial.println(p);
  double r = cos(p);
  double im = sin(p);
  c1.set(r, im);
  Serial.println("cos()+j*sin()");
  Serial.println(c1);
  Complex nrm(norm, 0);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i == j)
      {
        Complex t = nrm * c1;

        if (abs(p) == p)
        {
          Complex x = X[i][j] + t;
          double r1 = x.real();
          double im1 = x.imag();
          u[i][j].set(r1, im1);
        }
        else
        {
          Complex x = X[i][j] - t;
          double r1 = x.real();
          double im1 = x.imag();
          u[i][j].set(r1, im1);
        }
      }
      else
      {
        double r = X[i][j].real();
        double im = X[i][j].imag();
        u[i][j].set(r, im);
      }


    }
  }

  ComplexMat1.Print((Complex*)u, N, P, "u", pre);
  
  ComplexMat1.Conj((Complex*)u,N,P, (Complex*)uc);
  ComplexMat1.Print((Complex*)uc, N, P, "u conjugate", pre);
  ComplexMat1.Transpose((Complex*)uc, N,P, (Complex*)U);
  ComplexMat1.Print((Complex*)U, P,N, "u*", pre);
  
  ComplexMat1.Mult((Complex*)u, (Complex*)U,  N,P,N, (Complex*)v );
  ComplexMat1.Print((Complex*)v, N,N, "uu*", pre);
  
  ComplexMat1.Mult((Complex*)U, (Complex*)u,  P,N,P, (Complex*)a );
  ComplexMat1.Print((Complex*)a, P,P, "u*u", pre);
  
  Complex b(2,0);
  b = b /(a[0][0]);
  
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      v[i][j] = b * v[i][j];
    }
  }
  ComplexMat1.Print((Complex*)v, N,N, "(2uu*)/(u*u)", pre);
  
  ComplexMat1.Identity(N,N, (Complex*)I);
  
  ComplexMat1.Subtract((Complex*)I, (Complex*)v, N,N, (Complex*)H);
  ComplexMat1.Print((Complex*)H, N,N, "H", pre);
  
  ComplexMat1.Mult((Complex*)H, (Complex*)X,  N,N,P, (Complex*)u);
  ComplexMat1.Print((Complex*)u, N,P, "H*X", pre);
  

  while (1);
}
