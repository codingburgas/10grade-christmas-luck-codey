#include "dbConnection.h"
#include <iostream>
#include <string>

// Function to handle user login
bool login(const std::string &username, const std::string &password, std::string &role) {
    try {
        // Get database connection
        SAConnection &connection = getConnection();

        // Prepare and execute SQL command
        SACommand command(&connection, 
            "SELECT Role FROM Users WHERE Username = :1 AND Password = :2");
        command << username.c_str() << password.c_str();
        command.Execute();

        // Fetch the results
        if (command.FetchNext()) {
            role = command[1].asString().GetMultiByteChars();
            return true; // Login successful
        }
        return false; // Invalid credentials
    } catch (SAException &e) {
        std::cerr << "Login error: " << e.ErrText().GetMultiByteChars() << std::endl;
        return false;
    }
}