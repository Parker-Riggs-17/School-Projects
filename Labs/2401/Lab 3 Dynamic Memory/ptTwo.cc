#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    /*new int;
    int *ptr;

    ptr = new int;
    *ptr = 2401;

    cout << "         Address of new int: " << ptr << endl; 
    cout << "             Address of ptr: " << &ptr << endl;
    cout << "What is being stored in ptr: " << *ptr << endl << endl;

    for(int i = 0; i < 10; i++){
        ++(ptr);
        cout << *ptr << " Is stored at " << ptr << endl;
    }
    cout << endl;
    */

    size_t capacity = 5;
    size_t used = 0;
    int *tmpptr;
    int *ptr;

    ptr = new int[capacity];
    for(size_t i = 0; i < 25; i++){
        ptr[used] = rand();
        //cout << ptr[used] << endl;
        used++;
        if(used == capacity){
            tmpptr = new int[capacity + 5];
            for(size_t i = 0; i < used; i++){
                tmpptr[i] = ptr[i];
            }
            capacity += 5;
            delete []ptr;
            ptr = tmpptr;
            cout << "Resized.\n";
        }
    }
    
    tmpptr[2] = 0;
    for(size_t i = 0; i < capacity; i++){
        cout << ptr[i] << endl;
    }
}