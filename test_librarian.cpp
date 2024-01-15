#include "catch.hpp"
#include "librarian.h"
#include "member.h"
#include "book.h"
#include <iostream>
#include <sstream>

TEST_CASE("Librarian Class Tests", "[Librarian]") {
  
    // Example librarian details
    Librarian librarian(1, "Librarian Name", "12 Library Street", "librarian@example.com", 50000);

    SECTION("Add Member") {
        librarian.addMember();
        REQUIRE_FALSE(members.empty());
    }

    SECTION("Issue and Return Book") {
        // Setup
        Member member(123, "John Doe", "","");
        Book book(101, "Example Book","","");

        
        books.emplace(book.getBookID(),book);
        members.push_back(member);

        // Test issueBook
        librarian.issueBook(member.getMemberID(), book.getBookID());

        time_t currentTime = time(nullptr);
        char dateStr[100];
        strftime(dateStr, sizeof(dateStr), "%d-%m-%Y", localtime(&currentTime));

        // Calculate due date (three days from today)
	//adds 3 days in seconds
        time_t dueTime = currentTime + (3 * 24 * 60 * 60); 
        char dueDateStr[100];
        strftime(dueDateStr, sizeof(dueDateStr), "%d-%m-%Y", localtime(&dueTime));

    }

  
}
