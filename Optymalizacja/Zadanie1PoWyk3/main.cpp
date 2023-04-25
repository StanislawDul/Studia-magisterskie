//Program znajdujący minimum funkcji F metodą zlotego podziału

#include <functional>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

// Funkcja F
double F(double w){
    double Wynik;
    Wynik = 0.1*pow(w, 3) + 2*pow(w, 2) + 5*w + 7;

    return Wynik;
}

// Obliczanie nowych wartości przedziału oraz dokładności eps
void obliczW12(double *minBorder, double *maxBorder, double * eps)
{
    double w1;
    double w2;
    double a = *minBorder;
    double b = *maxBorder;

    w1 = b-(b-a)/1.61803;
    w2 = a+(b-a)/1.61803;
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

    // Pętla powtarzająca obliczenia aż do otrzymania różnicy wartości przedziałów < 0.01
    do
    {
       obliczW12(minBorder, maxBorder, eps);
       std::cout<<"epsilon = "<<*eps<<std::endl;

       i++;
    }while(*eps > 0.01);
    xMin = *minBorder + 0.5 * *eps;
    std::cout <<"Wynik to "<< xMin<<std::endl;

    double c = -3.3;
    std::cout << "Liczba iteracji = "<< i << std::endl;

    return 0;
}