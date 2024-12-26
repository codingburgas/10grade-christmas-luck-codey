#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <SQLAPI.h>
#include <string>


void initDatabaseAzure(const std::string &connectionString);
void closeDatabase();
SAConnection &getConnection();

#endif // DBCONNECTION_H