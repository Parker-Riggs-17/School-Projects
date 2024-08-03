/**
 *   @file: appointment_main.cc
 * @author: Parker Riggs
 *   @date: 04 / 12 / 2023
 *  @brief: This program handles the information for 1 appointment.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "appointment.h"
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

Appointment::Appointment(){ 
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
}

Appointment::Appointment(string appData){
    int bar[5];
    int j = 0;
    for (size_t i = 0; i < 5; i++)  // Sets the array so that all values are -1, checks to make sure that a bar has not been set as an index in the array yet.
    {
        bar[i] = -1;
    }
    
    for (size_t i = 0; i < appData.length(); i++)  // Loads the | character into each index of bar.
    {
        if(appData[i] == '|'){  // ERROR
            bar[j] = i;
            j++;
        }
    }

    title = appData.substr(0, bar[0]);
    while(title[0] == ' '){ // Deletes Leading Spaces
        title.erase(0, 1);
    }

    while(title[title.length() - 1] == ' '){    // Deletes spaces after
        title.erase(title.length() - 1, 1);
    }

    year = stoi(appData.substr(bar[0] + 1, bar[1] - bar[0] - 1));

    if(stoi(appData.substr(bar[1] + 1, bar[2] - bar[1] - 1)) >= 0){
        month = stoi(appData.substr(bar[1] + 1, bar[2] - bar[1] - 1));
    }else{
        month = 1;
    }

    if(stoi(appData.substr(bar[2] + 1, bar[3] - bar[2] - 1)) >= 0){
        day = stoi(appData.substr(bar[2] + 1, bar[3] - bar[2] - 1));
    }else{
        day = 1;
    }

    standardTime = appData.substr(bar[3] + 1, bar[4] - bar[3] - 1);
    while(standardTime[0] == ' '){ // Deletes Leading Spaces
        standardTime.erase(0, 1);
    }

    while(standardTime[standardTime.length() - 1] == ' '){    // Deletes spaces after
        standardTime.erase(standardTime.length() - 1, 1);
    }

    time = standardToMilitary(standardTime);

    if(stoi(appData.substr(bar[4] + 1)) >= 0){
        duration = stoi(appData.substr(bar[4] + 1));
    }else{
        duration = 1;
    }
    
}

string Appointment::getTitle(){
    return title;
}

int Appointment::getYear(){
    return year;
}

int Appointment::getMonth(){
    return month;
}

int Appointment::getDay(){
    return day;
}

int Appointment::getTime(){ // In military time
    return time;
}

int Appointment::getDuration(){
    return duration;
}

string Appointment::getDate(){
    if(month < 10){
        date = to_string(year) + "-0" + to_string(month) + "-" + to_string(day);
    }else{
        date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }

    return date;
}

string Appointment::getStandardTime(){
    standardTime = militaryToStandard(time);
    return standardTime;
}

void Appointment::setTitle(string newTitle){
    title = newTitle;
}

void Appointment::setYear(int newYear){
    if(newYear > 0){
        year = newYear;
    }
}

void Appointment::setMonth(int newMonth){
    if(newMonth > 0 && newMonth <= 12 && newMonth > 0){
        month = newMonth;
    }
}

void Appointment::setDay(int newDay){
    if(newDay > 0 && newDay <= 31){
        day = newDay;
    }
}

void Appointment::setTime(int newTime){  // Military Time
    string hour;
    string minute;
    int upHour;
    int upMinute;
    string fTime = to_string(newTime);

    if(newTime > 0 && newTime < 1200){
        hour = fTime.substr(0, 1);
        minute = fTime.substr(1, 2);

        upHour = stoi(hour);
        upMinute = stoi(minute);

        if(upHour >= 0 && upHour <= 9 && upMinute >= 0 && upMinute <= 59){
            time = newTime;
        }
    }

    if(newTime >= 1200 && newTime <= 2359){
        hour = fTime.substr(0, 2);
        minute = fTime.substr(2, 2);

        upHour = stoi(hour);
        upMinute = stoi(minute);

        if(upHour >= 12 && upHour <= 23 && upMinute >= 0 && upMinute <= 59){
            time = newTime;
        }
    }
} 
 
void Appointment::setDuration(int newDuration){
    if(newDuration > 1){
        duration = newDuration;
    }
}

void Appointment::setDate(int newYear, int newMonth, int newDay){
    setYear(newYear);
    setMonth(newMonth);
    setDay(newDay);
    
    date = to_string(newYear) + "-" + to_string(newMonth) + "-" + to_string(newDay);
}

string Appointment::militaryToStandard(int time){
    string sTime = to_string(time);

    if(time == 0){
        sTime = "12:00AM";
    }

    else if(time < 100 && time != 0){
        sTime = "12:" + to_string(time) + "AM";
    }

    else if(time == 1200){
        sTime = "12:00PM";
    }
    
    else if(time < 1200){
        if(sTime.length() == 3){
            sTime = sTime.substr(0, 1) + ":" + sTime.substr(1, 2) + "AM";
        }else{
            sTime = sTime.substr(0, 2) + ":" + sTime.substr(2, 2) + "AM";
        }
    }

    else if(time > 1200){
        sTime = to_string(time - 1200);
        if(sTime.length() == 2){
            sTime = "12:" + sTime.substr(0, 2) + "PM";
        }
        else if(sTime.length() == 3){
            sTime = sTime.substr(0, 1) + ":" + sTime.substr(1, 2) + "PM";
        }else{
            sTime = sTime.substr(0, 2) + ":" + sTime.substr(2, 2) + "PM";
        }
    }

    return sTime;
}

int Appointment::standardToMilitary(string time){
    int mTime = 0;
    int minute;

    for (size_t i = 0; i < time.length(); i++)
    {
        if(time[i] == ':'){
            time.erase(i, 1);
        }

        if(time[i] == ' '){
            time.erase(i, 1);
        }
    }

    if(time.find('P') != string::npos || time.find('p') != string::npos){
        for (size_t i = 0; i < time.length(); i++)  // Sets time so that it only consists of digits
        {
            if(time[i] == 'p' || time[i] == 'P'){
                time.erase(i);
            }
        }
        if(time.length() == 3){
            minute = stoi(time.substr(1, 2));
            mTime = stoi(time);
            if(mTime <= 1201){
                mTime += 1200;
            }
        }else{
        mTime = stoi(time);
        if(mTime < 1200){
        mTime += 1200;
        }
        }
    }
    
    if(time.find('A') != string::npos || time.find('a') != string::npos){
        for (size_t i = 0; i < time.length(); i++)  // Sets time so that it only consists of digits
        {
            if(time[i] == 'a' || time[i] == 'A'){
                time.erase(i);
            }
        }
        if(time.length() == 3){
            minute = stoi(time.substr(1, 2));
            mTime = stoi(time);
        }else{
        minute = stoi(time.substr(2, 2));
        mTime = stoi(time);
        if(mTime >= 1200){
            mTime = minute;
        }
        }
        
    }
    return mTime;
}

void Appointment::output(ofstream &out){
    out << title << "|" << year << "|" << month << "|" << day << "|" << standardTime << "|" << duration << endl;
}

bool operator <(Appointment &first, Appointment &last){
    return first.getTime() < last.getTime();
}