# User-Login-Module
This project involved the development of a secure user authentication system using C++ and SQLite. It implemented username availability checks, SHA-256 password encryption, and parameterized queries for robust security measures. The integration of SQLite database facilitated efficient storage and validation of user credentials. Collaborative teamwork ensured the design of a user-friendly interface, resulting in a reliable authentication solution.
<br>

## Contents
1.SHA256 header file<br>
2.Code to add username and passwords<br>
3.Code for authenticating username and passwords
<br>
<br>
## How to implement
### Step 1
Run the command ```sqlite3 database.db```.<br>
A database named database.md will be created and open up a console where you can issue SQL queries to that database.
<sub>Note: Dont download database.db, instead create one.</sub>
### Step 2
Run the command ```CREATE TABLE users (
  username VARCHAR,
  password_hash VARCHAR
);``` <br>
This will create a table named users with columns username and password_hash.
### Step 3
Compile ```addtodatabase.cpp``` using the command ```g++ addtodatabase.cpp -l sqlite3```.<br>
Run the program (```./a.out```) and add the username and passwords to the database.
### Step 4
Compile ```passwordchecker.cpp``` using the command ```g++ passwordchecker.cpp -l sqlite3```.<br>
Run the program (```./a.out```) and to simulate login experience.
