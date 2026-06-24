#include <iostream>
#include <fstream>
#include <iomanip>
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
        return;
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

    file.close();
}

void print()
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