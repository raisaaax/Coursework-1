#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Date.h" 

class Member; 

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    Date dueDate;
    Member* borrower;

public:
    Book(int bookID, const std::string& bookName, 
         const std::string& authorFirstName, const std::string& authorLastName);

    // Getters
    int getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    std::string getBookType() const;
    Date getDueDate() const;
    void setDueDate(const Date& newDate);
    void returnBook();
    void borrowBook(Member member, const Date& date);
};

#endif
