#include "include/classes.h"
#include "include/print.h"
#include "include/helper.h"

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

void printCampersWithAssignedActivities()
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

        cout << "  Assigned Activities: ";
        cout << left;

        for (const auto& activityID : camper.assignedActivities)
        {
            cout << setw(4) << activityID;
        }

        cout << endl;
    }
}

void printActivitiesWithAssignedCampers()
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

        cout << "  Assigned Campers: ";
        cout << left;

        for (const auto& camperID : activity.assignedCampers)
        {
            cout << setw(4) << camperID;
        }

        cout << endl;
    }
}