#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <vector>

using namespace std;


// Reads data from .CSV, parses and stores it
void dataReader();

// Prints all campers and rankings
void print();

// Structure of camper data; name, ID, rankings, etc...
class Camper_C
{
    public:
    int id;
    string name; // For storing camper names
    vector<string> rankings; // For storing camper activity rankings
    // TO DO: Add ID's

    Camper_C(int id, string name, vector<string> rankings)
    {
        this->name = name;
        this->rankings = rankings;
        this->id = id;
    }
};

// Structure of activities; activity name, slots, time, camper list, etc...
class Activity_C
{
    public:
        string name;
        vector<string> assignedCampers;
        //TO DO: Add more variables

        Activity_C(string name, vector<string> assignedCampers)
        {
            this->name = name;
            this->assignedCampers = assignedCampers;
        }
};

// Holds camper names and activity ranking—Camper Objects
vector<Camper_C> profile;

#endif