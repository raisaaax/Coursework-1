#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    std::string date; // Date in string format

public:
    
    Date(const std::string& date);

    Date();
    std::string getDate() const;
    void setDate(const std::string& newDate);

    // Compare method
    int calculateDaysLate();
};

#endif
