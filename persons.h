#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
  
private:
    std::string name;
    std::string address;
    std::string email;

public:
    // Constructor
    Person(const std::string& name, const std::string& address, const std::string& email);

    // Getters
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;

    // Setters
    void setName(const std::string& newName);
    void setAddress(const std::string& newAddress);
    void setEmail(const std::string& newEmail);
};

#endif 


