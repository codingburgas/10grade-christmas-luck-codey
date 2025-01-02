#include "dbConnection.h"
#include <iostream>


static SAConnection dbConn;


void initDatabaseAzure() {
    try {

        std::string server = "tcp:codey-server.database.windows.net,1433";
        std::string database = "#";
        std::string username = "#";
        std::string password = "#";


        std::string connectionString = "Server=" + server +
                                        ";Database=" + database +
                                        ";UID=" + username +
                                        ";PWD=" + password +
                                        ";Encrypt=True;"
                                        "TrustServerCertificate=False;"
                                        "Connection Timeout=30;";


        dbConn.setOption(SA_ConnectionOption_t::SAConnectionOptionPacketSize) = "4096";
        dbConn.setOption(SA_ConnectionOption_t::SAConnectionOptionSSLMode) = "preferred";

        dbConn.Connect(
            connectionString.c_str(),
            nullptr,
            nullptr,
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