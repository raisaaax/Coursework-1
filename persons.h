#ifndef _PERSONS_H_
#define _PERSONS_H_

#include <string>

class Person {
  std::string name;
  std::string address;
  std::string email;
 public:
  Person(const std::string& name, const std::string& address, const std::string& email);
  
  std::string getName();
  std::string getEmail();
  std::string getEmail();

  void  setName(std::string name);
  void setEmail(std::string email);
  void setEmail(std::string email);  
};



