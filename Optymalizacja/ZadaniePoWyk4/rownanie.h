


#include <string>
#include <iostream>
#ifndef ROWNANIE_H
#define ROWNANIE_H

#include <vector>

class Rownanie {
public:
    Rownanie(int a, int b);
    double funkcja(std::vector<double> X);
    double funkcja1D(std::vector<double> X, std::vector<double> dX, double a);
    std::vector<double> pochodna(std::vector<double> X);

private:
    int A;
    int B;
    double f;
};

#endif /* ROWNANIE_H */
