/**
 *   @file: appointment_main.cc
 * @author: Parker Riggs
 *   @date: 04 / 12 / 2023
 *  @brief: This program handles the information for appointments.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include "appointment.h"

using namespace std;

//function prototypes
string allToLower(string title);

int main(int argc, char const *argv[]) {

    // Variables
    vector<Appointment> app;
    ifstream ins("agenda.txt");

    if(ins.fail()){
        cout << "ERROR" << endl;
        exit(0);
    }

    if(argc != 2 && argc != 3){
        cout << "Not enough command lines.\n";
        exit(0);
    }

    string str;
    while(!ins.eof()){  
        getline(ins, str);
        if(str != ""){
        app.push_back(str);
        }
    }
    
    if(string(argv[1]) == "-ps"){   // Prints schedule in order by standard time
        sort(app.begin(), app.end());
        cout << endl;
        cout << "               Title             | Year | Month | Day |  Time  | Duration" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < app.size(); i++)
        {
            cout << left << setw(35);
            cout << app[i].getTitle();
            cout << setw(8);
            cout << app[i].getYear();
            cout << setw(8);
            cout << app[i].getMonth();
            cout << setw(5);
            cout << app[i].getDay();
            cout << setw(10);
            cout << app[i].getStandardTime();
            cout << app[i].getDuration();
            cout << endl;
        }
        
    }

    if(string(argv[1]) == "-p"){    // Prints all appointments at specified military time
        int time = stoi(string(argv[2]));

        cout << endl;
        cout << "               Title             | Year | Month | Day |  Time  | Duration" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < app.size(); i++)
        {
            if(time == app[i].getTime()){
            cout << left << setw(35);
            cout << app[i].getTitle();
            cout << setw(8);
            cout << app[i].getYear();
            cout << setw(8);
            cout << app[i].getMonth();
            cout << setw(5);
            cout << app[i].getDay();
            cout << setw(10);
            cout << app[i].getStandardTime();
            cout << app[i].getDuration();
            cout << endl;
            }
        }
        
    }

    if(string(argv[1]) == "-a"){    // Add an appointment given the format "Title|Year|Month|Day|Time|Duration"
        string ap = string(argv[2]);
        app.push_back(Appointment(ap));
    }

    if(string(argv[1]) == "-dt"){   // Delete all appointments that match a title
        string title = string(argv[2]);
        for (size_t i = 0; i < app.size(); i++)
        {
            if(allToLower(title) == allToLower(app[i].getTitle())){
                swap(app[i], app[app.size() - 1]);
                app.pop_back();
            }
        }
        
    }

    if(string(argv[1]) == "-dm"){   // Deletes all appointments that match starting military time
        int time = stoi(string(argv[2]));
        
        for (size_t i = 0; i < app.size(); i++)
        {
            if(time == app[i].getTime()){
                swap(app[i], app[app.size() - 1]);
                app.pop_back();
            }
        }
        
    }

    ins.close();
    ofstream out;
    out.open("agenda.txt");
    if(out.fail()){
        cout << "Output file failed to open.";
        exit(0);
    }
    for (size_t i = 0; i < app.size(); i++)
    {
        app[i].output(out);
    }
    out.close();
    return 0;
}// main

string allToLower(string title){
    for (size_t i = 0; i < title.size(); i++)
    {
        title[i] = tolower(title[i]);
    }
    
    return title;
}