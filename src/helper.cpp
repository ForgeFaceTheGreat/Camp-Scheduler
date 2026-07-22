#include "include/helper.h"
#include "include/classes.h"

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
            return (activity.assignedCampers.size() >= activity.slots);
        }
    }
    
    assert(false && "Activity ID not found!");
    return false;
}

void assignCamperActivity(int camperID, int activityID)
{
    // Add the activity to the Camper's assigned activiies
    for (auto& camperIter : Camper_V)
    {
        if (camperIter.id == camperID)
        {
            camperIter.assignedActivities.push_back(activityID);
            break;
        }
    }

    // Add the camper to the Activity's assigned campers
    for (auto& activityIter : Activity_V)
    {
        if (activityIter.id == activityID)
        {
            activityIter.assignedCampers.push_back(camperID);
            break;
        }
    }
}