#include <iostream>
#include <cstdlib>
#include "recursion.h"

using namespace std;

int main(){  
    /*
    //counting, test with: 23, 18, -2
    int x;  
    for(int j = 0; j < 3; ++j){              
        cout << "Enter a number: ";  
        cin >> x;  
        cout << "The even numbers counting up to there:\n";  
        counting(x);  
    }*/ 
    
    //reversing
    string s;  
    int start, end;

    cout << "Enter a string: ";  
    getline(cin,s);

    cout << "Enter two numbers that are within the bounds of the string.\n";  
    cin >> start >> end;  
    
    cout << "This is how your string looks now:\n";  
    reversing(s, start, end);  
    cout << s << endl;

    return 0;  
} 