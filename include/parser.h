#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Reads data from .CSV, parses and stores it
void dataReader();

// Checks for .csv files and opens them
fstream fileValidation(const string& file);

// Parses the campers.csv and creates IDs for campers
void camperParser(fstream& stream);

// Parses the activities.csv and creates IDs for activities
void activityParser(fstream& stream);

#endif // PARSER_H