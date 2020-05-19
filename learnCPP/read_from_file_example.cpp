#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main() {
    string a("1 2 3");
    istringstream input_stream(a);
    vector<int> list;
    
    int n;
    while(input_stream >> n) {
        list.push_back(n);
    }

    cout << list.front() << endl;;
    return 0;
}