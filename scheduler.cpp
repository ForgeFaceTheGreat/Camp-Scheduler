#include <iostream>
#include <fstream>
// #include <string>
#include <sstream>

#include "scheduler.h"

using namespace std;

int main()
{
    dataReader();
    print();

    return 0;
}

void dataReader()
{
    string data = "data.csv";
    fstream file(data);

    if (!file.is_open())
    {
        cout << "Error opening " << data << "!" << endl;
    }
    else
    {
        cout << "File is open!" << endl;
    }

    string line;
    int id = 0;
    
    // Get line from .CSV
    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        vector<string> data;
        string word;
        string name;
        bool nameSet = false;

        // Break up words from line to create data vector
        for (int iter = 0; iter <= line.length(); iter++)
        {
            // Iterates one extra time to get last word
            if (line[iter] == ',' || iter == line.length())
            {
                if (nameSet)
                {
                    data.push_back(word);
                }
                else
                {
                    name = word;
                    nameSet = true;
                }
                
                word = ""; // Reset word variable
            }
            else
            {
                word += line[iter]; // Add characters to word
            }
        }

        // Create Camper object
        Camper_C camper(id, name, data);

        // Add Camper object to vector
        profile.push_back(camper);
        id++; // Increment ID for next camper
        
        data.clear(); // Reset local vector—not needed
    }

    file.close();
}

void print()
{
    for (const auto& camper : profile)
    {
        cout << camper.id << ". " << camper.name << ": ";

        for (const auto& rank : camper.rankings)
        {
            cout << rank << " ";
        }

        cout << endl;
    }
}