#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <SQLAPI.h>
#include <string>

// Function to initialize database connection to Azure
void initDatabaseAzure();

// Function to close the database connection
void closeDatabase();

// Function to get the existing connection object
SAConnection &getConnection();

#endif // DBCONNECTION_H