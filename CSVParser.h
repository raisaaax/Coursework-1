// CSVParser.h
#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <string>
#include <unordered_map>
#include "book.h"

using namespace std;

unordered_map<int, Book> parseCSV(string filePath);

#endif 
