#include <iostream>

using namespace std;

struct Vector {
    int size;
    double* elem;
};

void vector_init(Vector& v, int size) {
    v.size = size;
    v.elem = new double[10];
}

double read_and_sum(int size) {
    Vector v;
    vector_init(v, size);

    for(int i = 0; i != size; i++) {
        cin >> v.elem[i];
    }

    double sum = 0.0;
    for(int i = 0; i != size; i++) {
        sum += v.elem[i];
    }
    return sum;
}

int main() {
    double sum = read_and_sum(10);
    cout << "sum = " << sum << endl;
    return 0;
}