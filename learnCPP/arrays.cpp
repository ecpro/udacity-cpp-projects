#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
     int arr[] = {2,1,2,3,5,3,1,12,23,0};
     cout<< "running loop" <<endl;
     for(auto& ref_to_arr : arr) {
          ref_to_arr *= 2;
     }
     
     for(auto *ptr = arr; *ptr != 0; ++ptr) {
          cout << *ptr << "\t";
     }

     return 0;
}