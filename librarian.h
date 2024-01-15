#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "member.h"
#include <vector>
#include <unordered_map>

class Book; 

extern std::vector<Member> members; 
extern std::unordered_map<int, Book> books; 

class Librarian : public Person {
private:
    int staffId;
    int salary;

public:
    // Constructor
    Librarian(int staffId, const std::string& name, const std::string& address, 
              const std::string& email, int salary);

    // Getters and setters
    int getStaffId() const;
    void setStaffId(int newStaffId);
    int getSalary() const;
    void setSalary(int newSalary);
    void addMember();
    void issueBook(int memberId, int bookId);
    void returnBook(int memberId, int bookId);
    void displayBorrowedBooks(int memberId);
    void calcFines(int memberId);
};

#endif 
