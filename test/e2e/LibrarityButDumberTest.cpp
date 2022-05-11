//
// Created by apenchev on 5/11/2022.
//

#include "gtest/gtest.h"
#include "librarity-but-dumber/LibrarityButDumber.h"

class LibrarityButDumberFixture : public ::testing::Test {
protected:
    std::stringstream inputStream;
    std::stringstream outputStream;

    void SetUp() override {
        // Redirect cin and cout to stringstreams
        std::cin.rdbuf(inputStream.rdbuf());
        std::cout.rdbuf(outputStream.rdbuf());
    }

    void TearDown() override {
        // Delete created files
        remove("books.bin");
        remove("users.bin");

        // Reset streams
        inputStream.str("");
        outputStream.str("");
    }
};

TEST_F(LibrarityButDumberFixture, ShouldAcceptDefaultCredentials) {
    std::stringstream expectedOutputStream;
    std::stringstream expectedErrorStream;

    // Login with default credentials
    // Requesting username
    expectedOutputStream << "Username: ";
    inputStream << "admin\n";

    // Requesting password
    expectedOutputStream << "Password: ";
    inputStream << "admin\n";

    // Expecting no error thrown, just regular prompt indicator
    expectedOutputStream << "|> ";

    // Expect a new line before program ending
    expectedOutputStream << "\n";

    // Running the program
    LibrarityButDumber::run();

    // Asserting if expected output equals actual
    ASSERT_TRUE(outputStream.str() == expectedOutputStream.str());
}
