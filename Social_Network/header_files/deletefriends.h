// deletefriends.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//================
// Delete a friend
//================
#ifndef DELETEFRIENDS_H
#define DELETEFRIENDS_H

// Local header files
#include "goback.h"

// Declaration of variables, defined in main.cpp
extern string frend;

void deletefriends()
{
	string delmoreFriends = "Y";
    while(delmoreFriends=="Y" || delmoreFriends=="y")
    {
		cout << endl << "\e[1mDELETE FRIEND\e[0m" << endl;
		ifstream myfile;
		myfile.open(logname.c_str()); // Open file of logged in user

		int lineCount = 1;
		cout << "Your friends are :" << endl << string(18, '=') << endl;
		// Print all of logged in user's friends
		while(getline(myfile, frend) && frend != ""){
				cout << "[" << lineCount << "] " << frend << endl;
				lineCount++;
		}
		myfile.close();
		
		int friendNumber;
		
		ofstream temp1; // Create first temporary file for input
		temp1.open("temp1", ios::app);

		ofstream temp2; // Create second temporary file for input
		temp2.open("temp2", ios::app);

		ifstream Myfile;
		Myfile.open(logname.c_str());

		cout << endl << "\e[3m(Type the number of your choice)\e[0m" << endl;
		cout << "Choice : ";
		cin >> friendNumber;
		
		int j=0;
		// Copy all the other friends to a temp file
		while(getline(Myfile, frend) && frend!=""){
			j++;
			if(friendNumber != j)
				temp1 << frend << endl;
			else
			{
                // Copy all friends from the friend you are about to delete, except the logged in user, to a temp file
				ifstream myuserfriend(frend.c_str());
				string muf;
				while(getline(myuserfriend, muf))
				{
                    if(muf!=logname)
                        temp2 << muf << endl;
                    else
                        continue;
				}
				remove(frend.c_str());
                rename("temp2", frend.c_str()); // Rename file in order to have friend's name as file name
            }
		}
		Myfile.close();
		// Close files
		temp1.close();
		temp2.close();
		remove(logname.c_str());
		rename("temp1", logname.c_str()); // Rename file in order to have logged in user's name
		
		cout << endl << "Delete more friends ? (Y/N) : ";
		// Choose whether to delete or not more friends
		cin >> delmoreFriends;
		if(delmoreFriends=="Y" || delmoreFriends=="y")
			deletefriends();
		else
		{
			goback();
			break;
		}
    }
}


#endif // DELETEFRIENDS_H
