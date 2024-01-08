#ifndef MEMBER_H
#define MEMBER_H

#include "persons.h"
#include "book.h"
#include <vector>

class Member : public Person {
private:
    int memberID;
    std::vector<Book> booksLoaned;

public:
    // Constructor
    Member(int memberID, const std::string& name, const std::string& address, const std::string& email);

    // Getters and setters
    int getMemberID() const;
    const std::vector<Book>& getBooksBorrowed() const;
    void setBooksBorrowed(const std::vector<Book>& newBooksBorrowed);
};

#endif // MEMBER_H
