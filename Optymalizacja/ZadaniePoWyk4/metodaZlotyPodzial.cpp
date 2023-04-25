#include <functional>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "rownanie.h"
using namespace std;

// Program znajdujący minimum funkcji 1-wymiarowej Fun.funkcja1D metodą zlotego podziału

// Obliczanie nowych wartości przedziału oraz dokładności eps. Minimalizowana funkcja jest zawarta w obiekcie Fun
void obliczW12(double *minBorder, double *maxBorder, double * eps, int k, vector<double> X, vector<double> dX, Rownanie Fun)
{
    double w1;
    double w2;
    double a = *minBorder;
    double b = *maxBorder;
    double ro = 1/1.61803;
    w1 = b-(b-a)*ro;
    w2 = a+(b-a)*ro;

    double W1 = Fun.funkcja1D(X, dX, w1);
    double W2 = Fun.funkcja1D(X, dX, w2);
    
    // Reguła zmiany granicy przedziału
    if(W1 < W2)
        *maxBorder = w2;
    else
        *minBorder = w1;

    *eps = *maxBorder - *minBorder;
    if (*eps<0)
        *eps = -1* *eps;
    
}

double metodaZlotyPodzial(double minBord, double maxBord, vector<double> X, vector<double> dX, Rownanie rown)
{
    // Wybór dolnego i górnego ograniczenia przedziału
    double * minBorder = &minBord;
    double * maxBorder = &maxBord;
    double xMin;
    double zero = 0;
    double * eps = &zero;
    int i = 0;
    int k = 1;

    // Pętla powtarzająca obliczenia aż do otrzymania różnicy wartości przedziałów < 0.01
    do
    {
       obliczW12(minBorder, maxBorder, eps, k, X, dX, rown);
       k++;
       i++;
    }while(*eps > 1e-6);
    xMin = *minBorder + 0.5 * *eps;

    return xMin;
}
