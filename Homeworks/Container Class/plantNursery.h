#ifndef PLANTNURSERY_H
#define PLANTNURSERY_H

#include "plant.h"
#include "date.h"
#include <iostream>
#include <string>
#include <fstream>

class PlantNursery{
    public:
    static const size_t SIZE = 200;

    //C-Tor
    PlantNursery(){
        used = 0;
    }

    //Functions
    void load_from_file(std::istream& ins); // Loads information from file to array

    void show_all(std::ostream& cout) const; // Shows all plants in array

    void add_plant(std::istream& cin); // Adds plant to array
    
    void remove(std::string name, std::string color); // Removes plant from array

    void change_stock_amt(std::string name, std::string color, int amt); // Changes the stock amount of a given plant

    void name_sort(); // Sorts the array by Name (bubble sort)

    void date_sort(); // Sorts the array by date (insertion sort)

    void stock_sort(); // Sorts the array by stock amount (selection sort)

    void show_plants(std::string color) const; // Shows all plants of a certain color

    void show_before(Date d) const; // Shows all plants that arrived before a certain date

    void show_colors(std::string name) const; // Shows all different colors of a plant

    int average(); // Returns the average stock of all plants 

    void save(std::ostream& ofs); // Back's up to the same file it was read from

    private:
    Plant data[SIZE]; // Stored Plants
    size_t used;    // Array Count
};

#endif