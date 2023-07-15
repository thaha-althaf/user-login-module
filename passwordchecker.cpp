#include <iostream>
#include <fstream>
#include "sha256.h"
#include <sqlite3.h>
#include <string>
using namespace std;

bool auth(string username,string password)
{
    sqlite3* db;
    int trash = sqlite3_open("database.db", &db);
    string query="SELECT * FROM users WHERE username = ? AND password_hash = ? ;";
    sqlite3_stmt* stmt;
    trash = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    trash = sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    trash = sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    bool authSuccess = false;
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        authSuccess = true;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return authSuccess;
}
int main()
{
    cout<<"enter the username"<<endl;
    string username;
    cin>>username;
    cout<<"enter the password"<<endl;
    string password;
    cin>>password;
    password=SHA256(&password[0]);
    if(auth(username,password))
    cout<<"welcome"<<endl;
    else
    cout<<"Errr....."<<endl;
}
