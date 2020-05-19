#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
    // https://doc.bccnsoft.com/docs/cppreference_en/cppsstream/all.html
    ostringstream s1;
    s1 << "Hello World" << 23 << endl;
    string s = s1.str();
    cout << s;
    string input = "1 2 3";
    istringstream input_stream(input);
    int out;
    input_stream >> out;
    cout << out << endl;
    return 0;
}