#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

using namespace std;

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

        vector<int> assignedActivities; // For storing assigned activity ID's

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
        int day; // For storing the day of the activity
        int startTime; // For storing the end time
        int endTime; // For storing the end time

        vector<int> assignedCampers; // For storing assigned camper ID's

        Activity_C(int id, string name, int slots, int day, int startTime, int endTime)
        {
            this->id = id;
            this->name = name;
            this->slots = slots;
            this->day = day;
            this->startTime = startTime;
            this->endTime = endTime;
        }
};

// Holds camper names and activity ranking—Camper Objects
extern vector<Camper_C> Camper_V;

// Holds the available activities, total slots, times, and assigned campers
extern vector<Activity_C> Activity_V;

#endif // CLASSES_H