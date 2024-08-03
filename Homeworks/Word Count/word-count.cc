/**
 *   @file: word-count.cc
 * @author: Parker Riggs
 *   @date: 02 / 10 / 2023
 *  @brief: This program counts the number of words and sentences in some text (given by the user). To terminate the program enter "@@@".
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {

    // Variables and Constants
    string text;
    int i = 0;
    char term = '@';
    int terminate = 0;
    char space = ' ';
    char period = '.'; 
    char question = '?';
    char ex = '!';
    int wordCount = 0;
    int senCount = 0;

    cout << "Enter a paragraph... (@@@ to stop)" << endl;
    cin >> text;
    while(terminate != 3){
        if(text.at(i) == space){    // Detects if the user inputs a space and adds 1 to the word count
            wordCount++;
        }

        //  Detects if the user inputs a punctuation mark and adds 1 to the sentence count
        if(text.at(i) == period){
            senCount++;
        }
        if(text.at(i) == question){
            senCount++;
        }
        if(text.at(i) == ex){
            senCount++;
        }

        // Detects if the sentinel value has been inputted.
        if(text.at(i) == term){ // If 3 @ signs are placed back to back (sentinel value) the program will stop.
            terminate++;
        }
        if(text.at(i) != term){ // If only 1 or 2 @ signs are placed it wont pick up as sentinel value.
            terminate = 0;
        }
    }

    //  This if statement detects if there are any words or sentences inputted.
    if(text.length() == 3){
        cout << "You did not enter any words." << endl;
    } else{
        cout << "Word Count: " << wordCount << endl;
        if(senCount == 0){
            cout << "You did not enter any sentences." << endl;
        } else{
            cout << "Sentence Count: " << senCount << endl;
            double averageWPS = wordCount / senCount;
            cout << "Average words per sentence: " << averageWPS << endl;
        }
    }
    return 0;
} 