/**
 *  File: encryption.cc
 *  Name: Parker Riggs
 *  Date: 03 / 08 / 23
 * Brief: This program encrypts and decrypts documents
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

// Prototypes
void displayMenu();
int keyValue();
void encryption(int key);
void decryption(int key);

int main(){
    // Variables
    int choice;
    int key;
    key = 3; // Default
    do{
        displayMenu();
        cout << "\nChoice: ";
        cin >> choice;
        if(choice == 1){
            key = keyValue();
            cout << "\nNew Key Value = " << key << endl;
        }
        else if(choice == 2){
            encryption(key);
        }
        else if(choice == 3){
            decryption(key);
        }
    }
    while(choice != 4);
    return 0;
}

void displayMenu(){

    cout << "\n1. Change Key Value (default is 3)";
    cout << "\n2. Encrypt";
    cout << "\n3. Decrypt";
    cout << "\n4. Quit\n";
}

int keyValue(){
    int key;
    cout << "Enter Key Value (1-10): ";
    cin >> key;
    return key;
}

void encryption(int key){
    ifstream inStream;
    ofstream outStream;
    string inFilename;
    string outFilename;
    char ch;

    cout << "Enter the input file name: ";
    cin >> inFilename;

    cout << "Enter the output file name: ";
    cin >> outFilename;

    
    inStream.open(inFilename);
    if(inStream.fail()){
        cout << "ERROR INPUT FILE NOT FOUND";
        exit(0);
    }

    outStream.open(outFilename);
    if(outStream.fail()){
        cout << "ERROR";
        exit(0);
    }

    inStream.get(ch);
    while(!inStream.eof()){
        ch += key;
        outStream << ch;
        inStream.get(ch);
    }
}

void decryption(int key){
    ifstream inStream;
    ofstream outStream;
    string inFilename;
    string outFilename;
    char ch;

    cout << "Enter the input file name: ";
    cin >> inFilename;

    cout << "Enter the output file name: ";
    cin >> outFilename;

    
    inStream.open(inFilename);
    if(inStream.fail()){
        cout << "ERROR INPUT FILE NOT FOUND";
        exit(0);
    }

    outStream.open(outFilename);
    if(outStream.fail()){
        cout << "ERROR";
        exit(0);
    }

    inStream.get(ch);
    while(!inStream.eof()){
        ch -= key;
        outStream << ch;
        inStream.get(ch);
    }

}
