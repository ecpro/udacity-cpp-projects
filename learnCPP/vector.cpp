#include "vector.h"
#include<iostream>


Vector::Vector(int s) :sz{s}, elements{new double[s]} {};
double& Vector::operator[](int pos) {
    if(pos < 0 || size() <= pos) throw std::out_of_range{"Vector::operator[]"};
     return elements[pos]; };
int Vector::size() { return sz; };


int main() {
    return 0;
}




