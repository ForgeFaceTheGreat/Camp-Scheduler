#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <iomanip>

using namespace std;

// Prints all campers and rankings
void printCamperClass();

// Prints all activities and assigned campers
void printActivityClass();

// Prints Camper's IDs, names, age, cabin, and assigned activity's IDs
void printCampersWithAssignedActivities();

// Prints activity's IDs, names, slots, day, start and end times, and assigned camper's IDs
void printActivitiesWithAssignedCampers();

#endif // PRINT_H