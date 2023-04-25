#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "metodaZlotyPodzial.h"
#include "rownanie.h"

double norm(std::vector<double> X)
{
    double x1 = X[0];
    double x2 = X[1];

    double no = std::sqrt(x1*x1+x2*x2);
    return no;
}



int main()
{

// Ustalanie punktu początkowego
int A, B;
A = 9;
B = 3;
vector<double> x0; 
x0.push_back(-2*A);
x0.push_back(2*B);
double alfa;

// Ustalenie oczekiwanej dokładności
double tol = 1e-4;

// Stworzenie licznika iteracji
int k = 0;
// Stworzenie obiektu umożliwiającego obliczenie wartości funkcji i wartości pochodnej funkcji
Rownanie rown(A, B);

// Obliczenie początkowego gradientu i początkowego wektora poszukiwań
std::vector<double> dX;
dX = rown.pochodna(x0);
std::vector<double> d;
d.push_back(-dX[0]);
d.push_back(-dX[1]);
double normDx = norm(dX);

// Pętla wykonująca algorytm najmniejszego spadku
while (normDx > tol){
    
    // Obliczenie minimum funkcji 1-wymiarowej zgodnie z kierunkiem poszukiwań
    // Wykorzystano moetodę złotego podziału
    // Metoda 1-wymiarowa szuka minimum funkcji w zakresie od -100 do 100
    alfa = metodaZlotyPodzial(-100, 100, x0, d, rown);
    
    // Ustalenie nowego punktu bazowego
    x0[0] = x0[0] + alfa*d[0];
    x0[1] = x0[1] + alfa*d[1];
    cout << "alfa = " << alfa << std::endl;
    dX = rown.pochodna(x0);
    normDx = norm(dX);
    
    // Znalezienie nowego wektora poszukiwań
    d[0] = -dX[0];
    d[1] = -dX[1];
    k = k + 1;
}

// Wyświetlanie wynikików
std::cout << "Wartość minimalna = " << rown.funkcja(x0) << std::endl;
std::cout << "Współrzędne szukanego punktu = ["<<x0[0] <<", "<< x0[1] << "]";

    return 0;
}

