#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <vector>

using namespace std;

// Reads data from .CSV, parses and stores it
void dataReader();

// Checks for .csv files and opens them
fstream fileValidation(const string& file);

// Parses the campers.csv and creates IDs for campers
void camperParser(fstream& stream);

// Parses the activities.csv and creates IDs for activities
void activityParser(fstream& stream);

// Converts 24-hour time (9:30) to minutes since midnight (570)
int msm(int hour, int minute);

// Converts minutes since midnight to 12-hour time
string msmTooTime(int msm);

// Looks up an activity and checks if it is full
bool activityFull(int activityID);

// Assigns a camper to an activity and adds the activity to the camper's assigned activities
void assignCamperActivity(int camperID, int activityID);

// Prints all campers and rankings
void printCamperClass();

// Prints all activities and assigned campers
void printActivityClass();

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
vector<Camper_C> Camper_V;

// Holds the available activities, total slots, times, and assigned campers
vector<Activity_C> Activity_V;

#endif