#include <iostream>

#include "include/classes.h"
#include "include/print.h"
#include "include/parser.h"
#include "include/helper.h"

using namespace std;

int main()
{
    dataReader();
    printCamperClass();
    printActivityClass();
    
    for (int i = 0; i <= 14; i++)
    {
        assignCamperActivity(i, 0);
        // Activity_V[0].assignedCampers.push_back(i);
    }
    
    printCampersWithAssignedActivities();

    cout << endl;

    printActivitiesWithAssignedCampers();

    return 0;
}
