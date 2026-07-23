#include "classes.h"
#include "parser.h"
#include "helper.h"

void dataReader()
{
    // Create, open, parse, and close activity file stream object
    string activities = "data/activities.csv";
    fstream activities_fstream = fileValidation(activities);
    activityParser(activities_fstream);
    activities_fstream.close();
    
    // Create, open, parse, and close camper file stream object
    string campers = "data/campers.csv";
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
        for (unsigned int iter = 0; iter <= line.length(); iter++)
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
        for (unsigned int iter = 0; iter <= line.length(); iter++)
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
        string location = data[1];
        int slots = stoi(data[2]);
        int day = stoi(data[3]);
        int startTime = msm(stoi(data[4]), stoi(data[5]));
        int endTime = msm(stoi(data[6]), stoi(data[7]));

        // Create Activity object
        Activity_C activity(id, name, location, slots, day, startTime, endTime);

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