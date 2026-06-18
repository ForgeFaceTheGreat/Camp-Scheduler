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
    
    // Get line from .CSV
    while (getline(file, line))
    {
        if (!line.empty() && line.back() == '\r')
        {
            line.pop_back();
        }

        vector<string> data;
        string word;

        // Break up words from line
        for (int iter = 0; iter < line.length(); iter++)
        {
            if (line[iter] == ',')
            {
                data.push_back(word);                
                word = ""; // Reset variable
            }
            else
            {
                word += line[iter]; // Add characters to word
            }

            // profile.push_back(Camper(data.front(), data));
            profile.push_back(Camper(data.front()));
        }
        
        // cout << endl;
    }

    file.close();
}

void print()
{
    for (const auto& item : profile)
    {
        cout << item.name;
    }
}