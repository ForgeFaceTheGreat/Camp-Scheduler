#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "scheduler.h"

using namespace std;

int main()
{
    dataReader();
    printCamperClass();
    printActivityClass();

    // minutesSinceMidnight(9, 0);
    // cout << msmTooTime(780) << endl;

    return 0;
}

void dataReader()
{
    // Create, open, parse, and close activity file stream object
    string activities = "activities.csv";
    fstream activities_fstream = fileValidation(activities);
    activityParser(activities_fstream);
    activities_fstream.close();
    
    // Create, open, parse, and close camper file stream object
    string campers = "campers.csv";
    fstream campers_fstream = fileValidation(campers);
    camperParser(campers_fstream);
    campers_fstream.close();
}

void camperParser(fstream& stream)
{
    string line;
    int id = 0;
    
    // Get line from .CSV
    while (getline(stream, line))
    {
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        vector<string> data;
        string word;

        // Break up words from line to create data vector
        for (int iter = 0; iter <= line.length(); iter++)
        {
            // Iterates one extra time to get last word
            if (line[iter] == ',' || iter == line.length())
            {
                data.push_back(word); // Everything goes into vector
                
                word = ""; // Reset word variable
            }
            else
            {
                word += line[iter]; // Add characters to word
            }
        }

        // Assign vector elements to variables
        string firstName = data[0];
        string lastName = data[1];
        int age = stoi(data[2]);
        int cabin = stoi(data[3]);

        // Delete the first few elements because they are in variables no
        data.erase(data.begin(), data.begin() + 4);

        // Create Camper object
        Camper_C camper(id, firstName, lastName, age, cabin, data);

        // Add Camper object to vector
        Camper_V.push_back(camper);
        id++; // Increment ID for next camper
        
        data.clear(); // Reset local vector—not needed
    }
}

void activityParser(fstream& stream)
{
    string line;
    int id = 0;
    
    // Get line from .CSV
    while (getline(stream, line))
    {
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        vector<string> data;
        string word;

        // Break up words from line to create data vector
        for (int iter = 0; iter <= line.length(); iter++)
        {
            // Iterates one extra time to get last word
            if (line[iter] == ',' || line[iter] == ':' || iter == line.length())
            {
                data.push_back(word); // Everything goes into vector
                word = ""; // Reset word variable
            }
            else
            {
                word += line[iter]; // Add characters to word
            }
        }

        // Assign vector elements to variables
        string name = data[0];
        int slots = stoi(data[1]);
        int day = stoi(data[2]);
        int startTime = msm(stoi(data[3]), stoi(data[4]));
        int endTime = msm(stoi(data[5]), stoi(data[6]));

        // Create Activity object
        Activity_C activity(id, name, slots, day, startTime, endTime);

        // Add Activity object to vector
        Activity_V.push_back(activity);
        id++; // Increment ID for next camper
        
        data.clear(); // Reset local vector—not needed
    }
}

fstream fileValidation(const string& fileName)
{
    fstream file(fileName);
    
    if (!file.is_open())
    {
        cout << "Error opening " << fileName << "!" << endl;
    }
    else
    {
        cout << fileName << " is open!" << endl;
    }

    return file;
}

int msm(int hour, int minute)
{
    int time = 60 * hour + minute;

    return time;
}

string msmTooTime(int msm)
{
    int hour = msm / 60;
    int minutes = msm % 60;

    // Adds double zeros when time is on the hour
    string min = ((minutes == 0) ? (to_string(minutes) + "0") : to_string(minutes));

    return (hour > 12) ? (to_string(hour - 12) + ":" + min + " PM") : (to_string(hour) + ":" + min + " AM");
}

bool activityFull(int activityID)
{
    for (const auto& activity : Activity_V)
    {
        if (activity.id == activityID)
        {
            return (activity.assignedCampers.size() >= activity.slots) ? true : false;
        }
    } 
}

void printCamperClass()
{
    for (const auto& camper : Camper_V)
    {
        cout << left;
        cout << setw(4)  << (to_string(camper.id) + ".");

        cout << setw(15) << camper.firstName;
        cout << setw(15) << camper.lastName;

        cout << "Age: ";
        cout << right << setw(2) << camper.age;

        cout << "  Cabin: ";
        cout << right << setw(2) << camper.cabin;

        cout << "  ";
        cout << left;

        for (const auto& rank : camper.rankings)
        {
            cout << setw(12) << rank;
        }

        cout << endl;
    }
}

void printActivityClass()
{
    for (const auto& activity : Activity_V)
    {
        cout << left;

        cout << setw(5)  << (to_string(activity.id) + ".");
        cout << setw(15) << activity.name;

        cout << "Slots: ";
        cout << right << setw(2) << activity.slots;

        cout << "  Day: ";
        cout << setw(2) << activity.day;

        cout << "  Start: ";
        cout << setw(4) << activity.startTime;
        cout << setfill(' ');

        cout << "  End: ";
        cout << setw(4) << activity.endTime;
        cout << setfill(' ');

        cout << endl;
    }
}