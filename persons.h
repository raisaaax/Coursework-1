#ifndef _PERSONS_H_
#define _PERSONS_H_

#include <string>

class Person {
  std::string name;
  std::string address;
  std::string email;
 public:  
  std::string getName();
  std::string getEmail();
  std::string getEmail();

  void  setName(std::string name);
  void setEmail(std::string email);
  void setEmail(std::string email);  
};

//classes inheriting from Person class

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

#endif

