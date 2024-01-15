#include "book.h"
#include "member.h"

static Member placeholder = Member(0, "PLACEHOLDER", "PLACEHOLDER", "PLACEHOLDER" ) 

Book::Book(int bookID, const std::string &bookName,
           const std::string &authorFirstName, const std::string &authorLastName)
    : bookID(bookID), bookName(bookName),
      authorFirstName(authorFirstName),  borrower(&placeholder), authorLastName(authorLastName) {}

int Book::getBookID() const
{
    return bookID;
}

std::string Book::getBookName() const
{
    return bookName;
}

std::string Book::getAuthorFirstName() const
{
    return authorFirstName;
}

std::string Book::getAuthorLastName() const
{
    return authorLastName;
}

void Book::returnBook()
{
  dueDate = Date();
  borrower = &placeholder;
  
}

void Book::borrowBook(Member member, const Date &date)
{
    dueDate = date;
    borrower = &member;
}

void Book::setDueDate(const Date &newDueDate)
{
    dueDate = newDueDate;
}

Date Book::getDueDate() const
{
    return dueDate;
}
