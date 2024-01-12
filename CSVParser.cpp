#include "CSVParser.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "book.h"
#include <iostream>

unordered_map<int, Book> parseCSV(string filePath)
{
    unordered_map<int, Book> books;
    ifstream file(filePath);

    if (!file)
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
    else
    {
      std::cout << "File " << filePath << " opened" << std::endl;
    }
    string line;
    bool inQuotes = false;

    //skip the first header line of the CSV file
    getline(file, line);


    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> fields;
        string field;
	
        // Parse the line
        for (char c : line)
        {
            if (c == '"')
            {
                inQuotes = !inQuotes; 
            }
            else if (c == ',' && !inQuotes)
            {
                // End of a field
                fields.push_back(field);
                field.clear();
            }
            else
            {
                field += c;
            }
        }

	//add last field after the loop
	fields.push_back(field);


        // Create a Book object and add it to the map
        int id = stoi(fields[0]);
        string name = fields[1];
        
        string authorFirstName = fields[3];
        string authorLastName = fields[4];

	
        books.emplace(id, Book(id, name, authorFirstName, authorLastName));
    }

    return books;
}
