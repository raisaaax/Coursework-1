#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "member.h"
#include "CSVParser.h"
#include "librarian.h"



void showMenu()
{
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add a member" << std::endl;
    std::cout << "2. Issue a book to a member" << std::endl;
    std::cout << "3. Return a book" << std::endl;
    std::cout << "4. Display all books borrowed by a member" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    
}

int getChoice()
{
    int choice;
    std::cout << "Enter your choice: ";
    while (!(std::cin >> choice) || choice < 1 || choice > 5)
    {
        std::cout << "Invalid choice. Please enter a number between 1 and 5: ";
        // Clear the error flag
        std::cin.clear(); 
        // Ignore invalid input
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    return choice;
}

Librarian createNewLibrarian()
{
    int staffId;
    std::string name, address, email;
    int salary;

    std::cout << "Enter Staff ID: ";
    std::cin >> staffId;
    std::cin.ignore(); 

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Address: ";
    std::getline(std::cin, address);

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter Salary: ";
    std::cin >> salary;

    Librarian newLibrarian(staffId, name, address, email, salary);
    return newLibrarian;
}


int main(int argc, char *argv[])
{
    // Check if a file name is provided
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    string filename = argv[1];
    std::cout << "Starting program with file: " << filename << std::endl;
    std::cout << "\n\n Welcome to the Library System!  Please input Librarian Details" << endl;
    books = parseCSV(filename);

    Librarian librarian = createNewLibrarian();

    bool isRunning = true;


    std::string memberID;
    int memberIDint;
    std::string bookID;
    while (isRunning)
    {
        // Display menu and get choice
        showMenu();
        int choice = getChoice();

        switch (choice)
        {
        case 1:
            std::cout << "Add a member" << std::endl;
            librarian.addMember();
            break;
        case 2:
            std::cout << "Issue a book to a member" << std::endl;
            std::cout << "Enter Member ID "<< std::endl;
            std::cin>> memberID;

            std::cout << "Enter Book ID "<< std::endl;
            std::cin>> bookID;
            librarian.issueBook(stoi(memberID), std::stoi(bookID));
            break;
        case 3:
            std::cout << "Return a book" << std::endl;
            std::cout << "Enter Member ID " << std::endl;
            std::cin>>memberID;

            std::cout << "Enter Book ID " << std::endl;
            std::cin>>bookID;
            librarian.returnBook(stoi(memberID), std::stoi(bookID));
            break;
        case 4:
            std::cout << "Display all books borrowed by a member" << std::endl;
            std::cout << "Enter Member ID " << std::endl;
            std::cin >> memberID;
            memberIDint = stoi(memberID);
            librarian.displayBorrowedBooks(memberIDint);
            break;
        case 5:
            std::cout << "Exiting program." << std::endl;
            isRunning = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}
