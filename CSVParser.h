// CSVParser.h
#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <unordered_map>
#include "Book.h"

using namespace std;

unordered_map<int, Book> parseCSV(string filePath);

#endif 
