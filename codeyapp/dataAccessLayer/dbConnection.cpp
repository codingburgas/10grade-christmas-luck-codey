#include "dbConnection.h"
#include <SQLAPI.h> // Main SqlAPI++ header
#include <iostream>

using sa_connection = SAConnection;
static sa_connection dbConn;

void initDatabaseAzure() {
    try {
        std::string server = "tcp:codey-server.database.windows.net,1433";
        std::string database = "codeyDb";
        std::string username = "admin1";
        std::string password = "$ilnaParola1";

        std::string connectionString = "Server=" + server +
                                        ";Database=" + database +
                                        ";UID=" + username +
                                        ";PWD=" + password +
                                        ";Encrypt=True;"
                                        "TrustServerCertificate=False;"
                                        "Connection Timeout=30;";

        dbConn.setOption("PacketSize") = "4096";
        dbConn.setOption("SSLMode") = "preferred";

        dbConn.Connect(
            connectionString.c_str(),
            static_cast<const char*>(nullptr),
            static_cast<const char*>(nullptr),
            SA_SQLServer_Client
        );

        std::cout << "Connected to Azure SQL database successfully!" << std::endl;
    } catch (SAException &e) {
        std::cerr << "Database connection error: " << e.ErrText().GetMultiByteChars() << std::endl;
        throw;
    }
}

void closeDatabase() {
    try {
        dbConn.Disconnect();
        std::cout << "Database connection closed." << std::endl;
    } catch (SAException &e) {
        std::cerr << "Error while disconnecting: " << e.ErrText().GetMultiByteChars() << std::endl;
    }
}


bool DbConnection::loginUser(const std::string &username, const std::string &password, std::string &role) {
    try {
        SACommand selectCmd(
            &dbConn,
            "SELECT password, role FROM Users WHERE username = :1"
        );

        selectCmd << username.c_str();
        selectCmd.Execute();

        if (selectCmd.FetchNext()) {
            std::string dbPassword = selectCmd.Field("password").asString().GetMultiByteChars();
            role = selectCmd.Field("role").asString().GetMultiByteChars();

            if (dbPassword == password) {
                return true; // Login successful
            }
        }
        return false; // Invalid username or password
    } catch (SAException &e) {
        std::cerr << "Database error: " << e.ErrText().GetMultiByteChars() << std::endl;
        return false;
    }
}


sa_connection &getConnection() {
    return dbConn;
}
