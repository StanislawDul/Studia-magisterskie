//Program znajdujący minimum funkcji F metodą Fibonacciego

#include <functional>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

// Funkcja generująca N-ty element ciągu Fibonacciego
double generujFiOdN(int N)
{
    double A = (1+sqrt(5))/2;
    double B = (1-sqrt(5))/2;
    double fi = 1/sqrt(5) * (pow(A, N) - pow(B, N));
    return fi;
}

// Funkcja wyznaczająca ro(k)
double generujRo(double a, double b, double eps, int k){

    double xN = 1;
    double xN1 = 1; 
    double xN2 = xN + xN1;
    int lCiagu = 1;
    double xMax = (b-a)/eps;
    while (xN2 < xMax)
    {
        xN = xN1;
        xN1 = xN2;
        xN2 = xN+xN1;

        lCiagu++;
    }
    double ro = generujFiOdN(lCiagu-k-1)/generujFiOdN(lCiagu-k);

    std::cout <<"a = " << a << " b = "<< b <<  " eps = "<< eps <<std::endl;
    std::cout <<"(a-b)/eps = " << xMax << " fi(n) = "<< xN2 <<std::endl;
    std::cout <<"xN = " << xN << " xN1 = "<< xN1 <<std::endl;
    std::cout << "ro = " << ro << std::endl;

    return ro;
}

// Minimalizowana funkcja
double F(double w){
    double Wynik;
    Wynik = 0.1*pow(w, 3) + 2*pow(w, 2) + 5*w + 7;

    return Wynik;
}

// Obliczanie nowych wartości przedziału oraz dokładności eps
void obliczW12(double *minBorder, double *maxBorder, double * eps, int k)
{
    double w1;
    double w2;
    double a = *minBorder;
    double b = *maxBorder;
    double ro = generujRo( *minBorder, *maxBorder, 0.01, k);
    w1 = b-(b-a)*ro;
    w2 = a+(b-a)*ro;
    double W1 = F(w1);
    double W2 = F(w2);

    // Reguła zmiany granicy przedziału
    if(W1 < W2)
        *maxBorder = w2;
    else
        *minBorder = w1;

    *eps = *maxBorder - *minBorder;
    if (*eps<0)
        *eps = -1* *eps;
}

int main()
{
    // Wybór dolnego i górnego ograniczenia przedziału
    double a = -5;
    double b = 3;
    double * minBorder = &a;
    double * maxBorder = &b;
    double xMin;
    double zero = 0;
    double * eps = &zero;
    int i = 0;
    int k = 1;

    // Pętla powtarzająca obliczenia aż do otrzymania różnicy wartości przedziałów < 0.01
    do
    {
       obliczW12(minBorder, maxBorder, eps, k);
       std::cout<<"minBorder "<<*minBorder<<" MaxBorder "<<*maxBorder<<std::endl;
       std::cout<<"epsilon "<<*eps<<std::endl;
       k++;
       i++;
    }while(*eps > 0.01);
    xMin = *minBorder + 0.5 * *eps;
    std::cout <<"Wynik to "<< xMin<<std::endl;

    std::cout<< "Liczba iteracji = " << i << std::endl;

    return 0;
}

