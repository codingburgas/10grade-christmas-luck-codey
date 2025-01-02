#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <SQLAPI.h>
#include <string>

class DbConnection {
public:
    static bool loginUser(const std::string &username, const std::string &password, std::string &role);
};

void initDatabaseAzure(const std::string &connectionString);
void closeDatabase();
SAConnection &getConnection();

#endif // DBCONNECTION_H