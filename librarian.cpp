#include "librarian.h"
#include "date.h"
#include <iostream>
#include <algorithm>

// made global because addMember in librarian has no way to access a list of members without deviating from UML
std::vector<Member> members;
std::unordered_map<int, Book> books; // same as members

Librarian::Librarian(int staffId, const std::string &name, const std::string &address,
                     const std::string &email, int salary)
    : Person(name, address, email), staffId(staffId), salary(salary) {}

int Librarian::getStaffId() const
{
    return staffId;
}

void Librarian::setStaffId(int newStaffId)
{
    staffId = newStaffId;
}

int Librarian::getSalary() const
{
    return salary;
}

void Librarian::setSalary(int newSalary)
{
    salary = newSalary;
}

void Librarian::addMember()
{
    int memberID;
    std::string name, address, email;

    std::cout << "Enter Member ID: ";
    std::cin >> memberID;
    std::cin.ignore(); 

    std::cout << "Enter Member Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Member Address: ";
    std::getline(std::cin, address);

    std::cout << "Enter Member Email: ";
    std::getline(std::cin, email);

    members.push_back(Member(memberID, name, address, email));

    std::cout << "New member added successfully.\n";
}

// Issues a book to a member
void Librarian::issueBook(int memberId, int bookId)
{
    // Find the member by memberId
    auto itMember = std::find_if(members.begin(), members.end(),
                                 [memberId](const Member &m)
                                 { return m.getMemberID() == memberId; });

    // Check if both member and book exist
    if (itMember != members.end() && books.find(bookId) != books.end())
    {
        // Get the list of books currently borrowed by the member
        std::vector<Book> borrowedBooks = itMember->getBooksBorrowed();

        Book book = books.find(bookId)->second;

        // Get current date
        time_t currentTime = time(nullptr);
        char dateStr[100];
        strftime(dateStr, sizeof(dateStr), "%d-%m-%Y", localtime(&currentTime));

        // Calculates due date by adding 3 days in seconds
        time_t dueTime = currentTime + (3 * 24 * 60 * 60); 
        char dueDateStr[100];
        strftime(dueDateStr, sizeof(dueDateStr), "%d-%m-%Y", localtime(&dueTime));

        book.borrowBook(*itMember, Date(dueDateStr));

        // Add the new book to the list
        borrowedBooks.push_back(book);

        // Update the member's borrowed books
        itMember->setBooksBorrowed(borrowedBooks);

        std::cout << "Book issued successfully.\n";
    }
    else
    {
        // Handle the case where the member or book is not found
        std::cout << "Member or Book not found.\n";
    }
}
   
