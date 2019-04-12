#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &a, int k) {    
    //null checks, sanity checks
    if(k < 0 || a.size() == 0) {
        return vector<int> ();
    }
    if(k == 0 || a.size() == 1) {
        return a;
    }
    //initialize temp and make it the size of a
    vector<int> temp;
    temp.resize(a.size());
    
    for(int i = a.size()-1; i >= 0; i--) {
        //if the # of rotation > size
        if(k > (int) a.size()) {
            if(i+k >= (int) a.size()) {
                temp[(i+k-a.size())%a.size()] = a[i];
            }
            else {
                temp[(i+k)%a.size()] = a[i];
            }
        }
        else {
            if(i+k >= (int) a.size()) {
                temp[i+k-a.size()] = a[i];
            }
            else {
                temp[i+k] = a[i];
            }
        }
    }
    return temp;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    int k = 6;
    std::vector<int> b = solution(a, k);

    for(int i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "" << std::endl;
    for(int i = 0; i < a.size(); i++) {
        std::cout << b[i] << " ";
    }
        std::cout << "" << std::endl;
}