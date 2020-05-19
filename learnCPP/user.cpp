#include "vector.h"
#include<iostream>
#include<cmath>

double sqrt_sum(Vector& v) {
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum+=sqrt(v[i]); 
    return sum;
}

int main() {
    Vector v(2);
    v[0] = 1, v[1] = 2;
    double result = sqrt_sum(v);
    std::cout << result << std::endl;
    return 0;
}