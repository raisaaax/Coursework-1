#include "catch.hpp"
#include "person.h"

TEST_CASE("Person Class Tests", "[Person]") {
    // Example person details
    std::string name = "John Doe";
    std::string address = "1234 Main Street";
    std::string email = "john.doe@example.com";

    Person person(name, address, email);

    SECTION("Constructor and Getters") {
        REQUIRE(person.getName() == name);
        REQUIRE(person.getAddress() == address);
        REQUIRE(person.getEmail() == email);
    }

    SECTION("Setters and Getters") {
        std::string newName = "Jane Doe";
        std::string newAddress = "4321 Elm Street";
        std::string newEmail = "jane.doe@example.com";

        person.setName(newName);
        person.setAddress(newAddress);
        person.setEmail(newEmail);

        REQUIRE(person.getName() == newName);
        REQUIRE(person.getAddress() == newAddress);
        REQUIRE(person.getEmail() == newEmail);
    }
}
