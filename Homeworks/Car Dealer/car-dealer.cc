/**
 *   @file: car-dealer.cc
 * @author: Parker Riggs
 *   @date: 04 / 03 / 23
 *  @brief: A program that allows the user to order a single car with several different options.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

///function prototypes
void mainMenu(string modelDisplay, string optionDisplay, string price[], string name[]);
void choiceList(int choice, string modelDisplay, string optionDisplay, string price[], string name[]);

int main(int argc, char const *argv[]) {

    // Variable
    vector <string> options;
    string price[15];
    string name[15];
    ifstream inStream;
    string modelDisplay = "\nNo Model Selected"; // Default
    string optionDisplay = ", Options: None"; // Default
    

    inStream.open("options.txt");
    if(inStream.fail()){
        cout << "Failed to open options.txt";
        exit(0);
    }

    string str;
    while(!inStream.eof()){     // Loads each line of option.txt into an index of a vector.
        getline(inStream, str);
        options.push_back(str);
    }

    for (size_t i = 0; i < 15; i++) // Sets prices to its own array
    {
        string inputString = options[i];
        int spacePos = inputString.find(' ');
        price[i] = inputString.substr(0, spacePos);
    }

    for (size_t i = 0; i < 15; i++) // Sets names to its own array
    {
        string inputString = options[i];
        int spacePos = inputString.find(' ');
        name[i] = inputString.substr(spacePos + 1);
    }
    
    mainMenu(modelDisplay, optionDisplay, price, name);

    inStream.close();
    return 0;
}/// main

// Function for the menu
void mainMenu(string modelDisplay, string optionDisplay, string price[], string name[]){
    int choice;
    if(modelDisplay == "\nNo Model Selected"){
        cout << modelDisplay << endl;
    } else{
        cout << modelDisplay << optionDisplay << endl;
    }
    cout << endl;
    cout << "1. Select Model(E, L, X)" << endl;
    cout << "2. Display available options and prices" << endl;
    cout << "3. Add an option" << endl;
    cout << "4. Remove an option" << endl;
    cout << "5. Cancel order" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    choiceList(choice, modelDisplay, optionDisplay, price, name);
}

// Function for the options and how they work.
void choiceList(int choice, string modelDisplay, string optionDisplay, string price[], string name[]){
    switch(choice){
        case 1:
        {
            char model;

            cout << "Enter Model(E, L, X): ";
            cin >> model;

            char ch = toupper(model);
            while(ch != 'E' && ch != 'L' && ch != 'X'){
                cout << "Please enter a valid model choice (E, L, X): ";
                cin >> model;
            }

            cout << endl;
            if(ch == 'E'){
                modelDisplay = "Model: E, $10,000.00";
            }
            if(ch == 'L'){
                modelDisplay = "Model: L, $12,000.00";
            }
            if(ch == 'X'){
                modelDisplay = "Model: X, $18,000.00";
            }

            mainMenu(modelDisplay, optionDisplay, price, name);

            break;
        }
        case 2:
        {

            cout << endl;
            cout << "Prices for model E, L, & X: $10,000.00, $12,000.00, $18,000.00" << endl;
            cout << "Available Options" << endl << endl;
            cout << name[0] << "($" << price[0] << ")" << "          " << name[1] << "($" << price[1] << ")" << "          " << name[2] << "($" << price[2] << ")" << endl;
            cout << name[3] << "($" << price[3] << ")" << "      " << name[4] << "($" << price[4] << ")" << "              " << name[5] << "($" << price[5] << ")" << endl;
            cout << name[6] << "($" << price[6] << ")" << "        " << name[7] << "($" << price[7] << ")" << "        " << name[8] << "($" << price[8] << ")" << endl;
            cout << name[9] << "($" << price[9] << ")" << "           " << name[10] << "($" << price[10] << ")" << "    " << name[11] << "($" << price[11] << ")" << endl;
            cout << name[12] << "($" << price[12] << ")" << "          " << name[13] << "($" << price[13] << ")" << "           " << name[14] << "($" << price[14] << ")" << endl;

            mainMenu(modelDisplay, optionDisplay, price, name);

            break;
        }
        case 3:
        {
            string option[6];

            if(modelDisplay == "\nNo Model Selected"){
                mainMenu(modelDisplay, optionDisplay, price, name);
            }

            cout << "Enter option: ";
            cin >> option[0];

            break;

        }
        case 4:
        {
            string optionTR[6];

            if(modelDisplay == "\nNo Model Selected"){
                mainMenu(modelDisplay, optionDisplay, price, name);
            }

            cout << "Enter option to remove: ";
            cin >> optionTR[0];


            break;
        }
        case 5:
        {
            int choice = 0;
            char model = '\0';
            char ch = '\0';
            string modelDisplay = "\nNo Model Selected";

            mainMenu(modelDisplay, optionDisplay, price, name);
            break;
        }
        case 6:
        {
            exit(0);
            break;
        }
        default:
        {
            mainMenu(modelDisplay, optionDisplay, price, name);
        }
    }

}
