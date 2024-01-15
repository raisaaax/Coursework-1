#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function
#include "catch.hpp"
#include "date.h"

#include <stdexcept>

TEST_CASE("Date Class Tests", "[Date]") {
    SECTION("Constructor and Getters") {
        Date date("01-01-2023");
        REQUIRE(date.getDate() == "01-01-2023");
    }

    SECTION("Setters") {
        Date date;
        date.setDate("01-02-2023");
        REQUIRE(date.getDate() == "01-02-2023");
    }

    SECTION("calculateDaysLate - Future Date") {
        Date futureDate("01-01-2099");
        REQUIRE(futureDate.calculateDaysLate() == 0);
    }

    SECTION("calculateDaysLate - Past Date") {
        // Get current date
        time_t currentTime = time(nullptr);
        char dateStr[100];
        strftime(dateStr, sizeof(dateStr), "%d-%m-%Y", localtime(&currentTime));

        // Calculate date 3 days in the past
        time_t dueTime = currentTime - (3 * 24 * 60 * 60); // Add 3 days in seconds
        char dueDateStr[100];
        strftime(dueDateStr, sizeof(dueDateStr), "%d-%m-%Y", localtime(&dueTime));

        Date pastDate(dueDateStr);

        // Check if the result is approximately 10 
        REQUIRE(pastDate.calculateDaysLate() == 3);
    }
}
