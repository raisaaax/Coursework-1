#include "date.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
#include <iomanip> // For std::get_time

Date::Date(const std::string& date) : date(date) {}

Date::Date(){}

std::string Date::getDate() const {
    return date;
}

void Date::setDate(const std::string& newDate) {
    date = newDate;
}

int Date::calculateDaysLate() {
    std::tm dateTm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&dateTm, "%d-%m-%Y"); // Parse the date string

    //Handle error
    if (ss.fail()){
      throw std::runtime_error("Failed to parse date: " + date);
    }
    

    // Get the current time as time_t
    std::time_t currentTime = std::time(nullptr);
    
    // Convert current time to tm structure
    std::tm* nowTm = std::localtime(&currentTime);

    // Convert tm structures to time_t for comparison
    std::time_t targetTime = std::mktime(&dateTm);
    std::time_t nowTime = std::mktime(nowTm);

    // Calculate difference in seconds and then convert to days
    const double secondsPerDay = 60 * 60 * 24;
    double difference = std::difftime(targetTime, nowTime) / secondsPerDay;

    int days =  static_cast<int>(difference);

    //if data is in the future, don't count those days
    if (days > 0){
      days = 0;
    }

    return abs(days);
}

