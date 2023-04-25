// Klasa przechowywuje parametry A oraz B,
// Oblicza wartość funkcji dwuwymiaowej
// Oblicza wartość funkcji jednowymiareowej wzdłóż wektora poszukiwań
// Oblicza wartość pochodnej funkcji dwuwymiarowej

#include <iostream>
#include <vector>
#include "rownanie.h"
using namespace std;

// Zapisanie parametrów A oraz B
Rownanie::Rownanie(int a, int b){
  A = a;
  B = b;
}

// Metoda obliczająca wartość funkcji dwuwymiarowej
double Rownanie::funkcja(vector<double> X) {
  double x1 = X[0];
  double x2 = X[1];
  f = A*x1*x1 + B*x2*x2 - 0.25*A*x1*x2 -0.5*A*x1 - 0.5*B*x2 + A*B;
  return f;
}

// Metoda obliczająca wartość funkcji jdwnowymiarowej
double Rownanie::funkcja1D(vector<double> X, vector<double> dX, double a) {
  vector<double> Xto1D;
  Xto1D.push_back(X[0]+dX[0]*a);
  Xto1D.push_back(X[1]+dX[1]*a);
  return funkcja(Xto1D);
}

// Metoda obliczająca wartość pochodnej
vector<double> Rownanie::pochodna(vector<double> X) {
  double x1 = X[0];
  double x2 = X[1];

  double dF_dx = 2*A*x1-0.25*A*x2-0.5*A;
  double dF_dy = 2*B*x2-0.25*A*x1-0.5*B;
  vector<double> dX;
  dX.push_back(dF_dx);
  dX.push_back(dF_dy);
  return dX;

}