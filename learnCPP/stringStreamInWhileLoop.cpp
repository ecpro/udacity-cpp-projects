#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {

    string input = "1 2 3";
    istringstream input_stream(input);
    int in;
    char ch;
    while(input_stream >> in) {
        cout << in << endl;
    }
    return 0;
}