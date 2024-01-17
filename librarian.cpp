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


void Librarian::displayBorrowedBooks(int memberId)
{
    // Find the member by memberId
    auto itMember = std::find_if(members.begin(), members.end(),
                                 [memberId](const Member &m)
                                 { return m.getMemberID() == memberId; });

    // Check if the member was found
    if (itMember != members.end())
    {
        // Get the list of borrowed books
        const std::vector<Book> &borrowedBooks = itMember->getBooksBorrowed();

        // Check if the member has borrowed any books
        if (borrowedBooks.empty())
        {
            std::cout << "No books borrowed by member ID " << memberId << ".\n";
            return;
        }

        std::cout << "Books borrowed by member ID " << memberId << ":\n";
        for (const auto &book : borrowedBooks)
        {
            // Assuming Book class has appropriate getters or public properties
            std::cout << "Book ID: " << book.getBookID() << "\n"
                      << "Book Name: " << book.getBookName() << "\n"
                      << "Author First Name: " << book.getAuthorFirstName() << "\n"
                      << "Author Last Name: " << book.getAuthorLastName() << "\n"
                      << "Due Date: " << book.getDueDate().getDate() << "\n"
                      << std::endl; // Separate details of each book
        }
    }
    else
    {
        std::cout << "Member ID " << memberId << " not found.\n";
    }
}

void Librarian::calcFines(int memberId)
{
    // This method doesn't have anyway to know what books were just returned, so calculating fines is built into returnBook

    // instead, this method will calculate all fines that would be due if all books were returned today for a memeber
    auto itMember = std::find_if(members.begin(), members.end(),
                                 [memberId](const Member &m)
                                 { return m.getMemberID() == memberId; });

    if (itMember != members.end())
    {
        // Get the list of books currently borrowed by the member
        std::vector<Book> borrowedBooks = itMember->getBooksBorrowed();
        int totalDaysLate = 0;

        for(Book book : borrowedBooks)
        {
            totalDaysLate += book.getDueDate().calculateDaysLate();
        }

        std::cout<<"Total fines due if all books were returned today are  \xA3" << totalDaysLate <<std::endl;

    }
}
   
