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
    int id; // For storing camper ID number
    string firstName; // For storing camper first name
    string lastName; // For storing camper last name
    int age; // For storing camper age
    int cabin; // For storing camper cabin number
    vector<string> rankings; // For storing camper activity rankings

    Camper_C(int id, string firstName, string lastName, int age, int cabin, vector<string> rankings)
    {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->cabin = cabin;
        this->rankings = rankings;
    }
};

// Structure of activities; activity name, slots, time, assigned camper, etc...
class Activity_C
{
    public:
        int id; // For storing the activity's ID's
        string name; // For storing the activity's name
        int slots; // For storing total slots

        vector<int> assignedCampers; // Uses camper ID's

        Activity_C(string name, vector<int> assignedCampers)
        {
            this->name = name;
            this->assignedCampers = assignedCampers;
        }
};

// Holds camper names and activity ranking—Camper Objects
vector<Camper_C> Camper_V;

// Holds the available activities, total slots, times, and assigned campers
vector<Activity_C> Activity_V;

#endif