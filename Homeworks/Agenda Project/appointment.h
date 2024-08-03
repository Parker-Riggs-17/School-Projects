/**
 *   @file: appointment_main.cc
 * @author: Parker Riggs
 *   @date: 04 / 12 / 2023
 *  @brief: This program handles the information for 1 appointment.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

using namespace std;

class Appointment{
public:
    // Constructors
    Appointment();
    Appointment(string appData);

    // Getters
    string getTitle();
    int getYear();
    int getMonth();
    int getDay();
    int getTime();  // Military Time
    int getDuration();
    string getDate();
    string getStandardTime();

    // Setters
    void setTitle(string newTitle);
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);
    void setTime(int newTime);  // Military Time
    void setDuration(int newDuration);
    void setDate(int newYear, int newMonth, int newDay);

    // Helper Functions
    string militaryToStandard(int time);
    int standardToMilitary(string time);
    void output(ofstream &out);
private:
    string title;
    string date;
    string standardTime;
    int year;
    int month;
    int day;
    int time;
    int duration;
};
bool operator <(Appointment &first, Appointment &last);
#endif