#include "recursion.h"

using namespace std;

void counting(int n){
    // Base Case //
    if(n < 0){
        return;
    }else{
        counting(n - 1);
        if(n % 2 == 0){
            cout << n << endl;
        }
    }
}

void reversing(std::string& s, int start, int end){
    // Base Case //
    if(start > end){
        return;
    }else{
        reversing(s, start + 1, end - 1);
        swap(s[start], s[end]);
    }
}