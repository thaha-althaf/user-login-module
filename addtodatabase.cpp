#include <iostream>
#include <sqlite3.h>
#include "sha256.h"
using namespace std;
bool inuse=false;
int callback(void* data, int argc, char** argv, char** azColName) 
{
    if (argc > 0) 
    {
        cout << "Username exists. Please enter a new username "<<endl;
        inuse=true;
    } 
    return 0;
}
int main() 
{
    sqlite3 *db;
    int rc;
    bool flag=true;
    rc = sqlite3_open("database.db", &db);
    while(flag)
    {
        int trash;
        string user;
        do
        {
            inuse= false;
            cout<<"Enter username : ";
            cin>>user;
            string selectQuery = "SELECT username FROM users WHERE username = '"+ user+ "';";
            trash=sqlite3_exec(db, selectQuery.c_str(), callback, nullptr, nullptr);
        }
        while(inuse);

        cout<<"Enter password : ";
        string pass;
        cin>>pass;
        pass=SHA256(&pass[0]);
        string insertQuery = "INSERT INTO users (username, password_hash) VALUES ('" + user + "', '" + pass+ "');";
        trash = sqlite3_exec(db, insertQuery.c_str(), nullptr, nullptr, nullptr);
        cout<<"Do you want to enter more username ? (yes=1,No=0)"<<endl;
        cin>>flag;
    }
   sqlite3_close(db);
}