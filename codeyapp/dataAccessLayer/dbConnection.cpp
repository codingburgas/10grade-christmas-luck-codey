#include "dbConnection.h"
#include <iostream>

// Static connection object
static SAConnection dbConn;

void initDatabaseAzure() {
    try {
        // Connection parameters
        std::string server = "tcp:codey-server.database.windows.net,1433";
        std::string database = "codeyDb";  // Replace with your database name
        std::string username = "Admin1";  // Replace with your username
        std::string password = "$ilnaParola1";  // Replace with your password

        // Connection string
        std::string connectionString = "Driver=/usr/local/lib/libmsodbcsql.18.dylib;"
                                       "Server=" + server +
                                       ";Database=" + database +
                                       ";UID=" + username +
                                       ";PWD=" + password +
                                       ";Encrypt=True;"
                                       "TrustServerCertificate=False;"
                                       "Connection Timeout=30;";

        // Connect to Azure SQL
        dbConn.Connect(
            connectionString.c_str(),
            "", // No username here since it's in the connection string
            "", // No password here since it's in the connection string
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

SAConnection &getConnection() {
    return dbConn;
}
