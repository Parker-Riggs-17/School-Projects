#include "plantNursery.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Functions

void PlantNursery::load_from_file(istream& ins){
    while(!(ins.eof())){
        add_plant(ins);
    }
}

void PlantNursery::show_all(ostream& cout) const{
    cout << endl;
    for(size_t i = 0; i < used; i++){
        cout << data[i] << endl;
    }
}

void PlantNursery::add_plant(istream& cin){
    if(used >= SIZE){
        cout << "No more Room!";
        return;
    }
    data[used].input(cin);
    used++;
}
 
void PlantNursery::remove(string name, string color){
   for(size_t i = 0; i < used; i++){
    if(data[i].get_name() == name && data[i].get_color() == color){
        data[i] = data[i + 1];
        used--; 
    }
   }
}

void PlantNursery::change_stock_amt(string name, string color, int amt){ 
    cout << endl;
    for(size_t i = 0; i < used; i++){
        if(data[i].get_name() == name && data[i].get_color() == color){
            data[i].change_stock(amt);
            data[i].output(cout);
        }
    }
    cout << endl;
}

void PlantNursery::name_sort(){ //Bubble Sort (takes 2 numbers and switches their pos if out of order)
    Plant tmp;
    for(size_t i = 1; i < used; i++){ // Just tells func to go through used # of times
        for(size_t j = 1; j < used; j++){
            if(data[j - 1].get_name() > data[j].get_name()){ // checks the element to left of index to see if greater than index
                tmp = data[j - 1] = data[j]; // if true, this swaps them
                data[j] = tmp;
            }
        }
    }
    show_all(cout);
}

void PlantNursery::date_sort(){ // Insertion Sort (scans through all elements, if out of order they swap)
    size_t next;
    cout << endl;
    for (size_t i = 0; i < used; i++)
    {
        // Save the value that you are trying to insert
        next = i;
        for(size_t j = i + 1; j < used; j++){ // (i) is the current index, (j) is the index 1 over
            if(data[j].get_cameIn() < data[next].get_cameIn()){ // If the element to the right is less than element @ index
                next = j; // Basically sets next to i + 1
            }
        }
        if(next != i){ // If next != i, next = j
            swap(data[next], data[i]);
        }
    }
    show_all(cout);
}

void PlantNursery::stock_sort(){ // Selection Sort (takes smallest to beg and push)
    size_t i, j, small;
    Plant tmp;

    // this loop (i) keeps track of the position where I am putting the smallest piece of data
    cout << endl;
    for(i = 0; i < used - 1; i++){
        small = i;
        // this loop (j) looks for the smallest piece of data in the rest of the array
        for(j = i + 1; j < used; j++){
            // if the data where I am looking is "smaller" than the data in the current small, make small equal to j
            if (data[j].get_stock() < data[small].get_stock()){
                small = j;
            }
        }
        tmp = data[i];
        data[i] = data[small];
        data[small] = tmp;
    }
    show_all(cout);
}

void PlantNursery::show_plants(string color) const{ //Shows all plants based off of its color
    cout << endl;
    for(size_t i = 0; i < used; i++){  
        if(data[i].get_color() == color){ // Checks if the color of plant[i] = the color asked for by user
            data[i].output(cout);
            cout << endl;
        }
    }
    cout << endl;
}

void PlantNursery::show_before(Date date) const{   //Shows all plants in PlantNursery before a specific date
    cout << endl;
    for(size_t i = 0; i < used; i++){ 
        if(data[i].get_cameIn() < date){ // if the date it came in is less than the date entered, output plant
            data[i].output(cout);
            cout << endl;
        }
    }
    cout << endl;
}

void PlantNursery::show_colors(string name) const{  //Shows all colors of a specific plant
    cout << endl;
    for(size_t i = 0; i < used; i++){
        if(data[i].get_name() == name){ // Checks if names = then displays the color of the plant
            cout << data[i].get_color() << endl;
        }
    }
    cout << endl;
}

int PlantNursery::average(){
    int stockArray[used];
    int totalStock = 0;
    int denomCount = 0;
    cout << endl;
    for(size_t i = 0; i < used; i++){
        stockArray[i] = data[i].get_stock(); //Loads all stocks into the stock array
        totalStock += stockArray[i];  // Finds the sum of all stocks
        denomCount++; // Finds the total number of times totalStock gets updated
    }
    int average = totalStock / denomCount;
    return average;
    cout << endl;
}

void PlantNursery::save(ostream& ofs){
    for(size_t i = 0; i < used; i++){
        data[i].output(ofs);    // Outputs all plants back
    }
}
