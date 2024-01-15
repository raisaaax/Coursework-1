#include "catch.hpp"
#include "member.h"
#include "book.h"


TEST_CASE("Member Class Tests", "[Member]") {
    // Example member details
    int memberId = 100;
    std::string name = "John Doe";
    std::string address = "123 Main Street";
    std::string email = "john.doe@example.com";

    Member member(memberId, name, address, email);

    SECTION("Constructor and Getters") {
        REQUIRE(member.getMemberID() == memberId);
        REQUIRE(member.getName() == name); // getName from Person class
        REQUIRE(member.getAddress() == address); // getAddress from Person class
        REQUIRE(member.getEmail() == email); // getEmail from Person class
    }

    SECTION("Set and Get Books Borrowed") {
        Book book1(1, "Book 1", "", "");
        Book book2(2, "Book 2", "", "");
        std::vector<Book> books = { book1, book2 };

        member.setBooksBorrowed(books);
        REQUIRE(member.getBooksBorrowed().size() == 2);
        REQUIRE(member.getBooksBorrowed()[0].getBookID() == book1.getBookID());
        REQUIRE(member.getBooksBorrowed()[1].getBookID() == book2.getBookID());
    }
}
