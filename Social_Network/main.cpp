/*======================================
        Social Network in C++
           Copyright 2020, 
Konstantinos Thanos [Mathematician, MSc]
         All rights reserved
=========================================*/
// Header files
#include <sstream> // for string stream classes (std::stringstream)
// Local header files
#include "header_files/listusers.h"
#include "header_files/mainmenu.h"

// Variables
string regname, regpass;  // name and password for the Registration part
string logname, logpass;  // name and password for the Log In  part
string name, password;    // name and password existing in Database
string namepost, reply;   // name of user who left a post and the reply of a friend to this
string posts;             // posts of user who is logged in
string friendname, frend; // strings for friend names
int numofusers = -1;      // initialization of the number of users

// Main function
int main()
{
    string graph_title = "||"+string(39,'=')+"||";
    cout << graph_title << endl;
    cout << "||"+string(9,' ')+"\e[1mSOCIAL NETWORK in C++\e[0m"+string(9,' ')+"||" << endl; // "\e[1mtext\e[0m" for bold text in terminal
    cout << "|| \e[3mA Social Network project built in C++\e[0m ||" << endl;                 // "\e[3mtext\e[0m" for italic text in terminal
    cout << graph_title << endl;
    listusers(); // execute code from listusers.h header file
    // Process to convert numofusers into string (to use it's size later)
    ostringstream tstr; tstr << numofusers; string mystr = tstr.str();
    
    cout << "||    Number of registered users : " << numofusers << string(6-mystr.size(),' ')+"||" << endl; // Print the number of registered users in this social network
    cout << graph_title << endl;
    mainmenu(); // execute code from mainmenu.h header file
}
