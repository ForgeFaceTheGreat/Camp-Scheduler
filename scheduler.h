#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <vector>

using namespace std;


// Reads data from .CSV and parses it
void dataReader();

// Prints all campers and activities
void print();

class Camper
{
    public:
    string name;
    vector<string> activities;
    
    // Camper(string name, vector<string>& activities)
    Camper(string name)
    {
        this->name = name;
        // this->activities = activities;
    }
};

vector<Camper> profile;

#endif