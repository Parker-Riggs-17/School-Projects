#include <iostream>

using namespace std;

void pretty(){
    int x = 0;
    x++;
    for(int i = 0; i < x; i++){
        cout << "*";
    }
    cout << endl;
}

int main(){
    for(int i = 0; i < 6; i++){
        pretty();
    }
}