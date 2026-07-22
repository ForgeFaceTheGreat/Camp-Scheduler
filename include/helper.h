#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Converts 24-hour time (9:30) to minutes since midnight (570)
int msm(int hour, int minute);

// Converts minutes since midnight to 12-hour time
string msmTooTime(int msm);

// Looks up an activity and checks if it is full
bool activityFull(int activityID);

// Assigns a camper to an activity and adds the activity to the camper's assigned activities
void assignCamperActivity(int camperID, int activityID);

#endif // HELPER_H