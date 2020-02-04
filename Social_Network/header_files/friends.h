// friends.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//=================================
// Check friends for logged in user
//=================================
#ifndef FRIENDS_H
#define FRIENDS_H

// Local header files
#include "goback.h"

// Declaration of variables, defined in main.cpp
extern string frend;

void friends()
{
    cout << endl << "Your friends are :" << endl << string(18,'=') << endl;
    // Open file of logged in user
    ifstream logUser;
    logUser.open(logname.c_str());
    // Read and print the names of the friends of the logged in user
    while(!logUser.eof()) 
    {
        getline(logUser, frend); 
        cout << frend << endl;
    }
    goback();
}


#endif // FRIENDS_H
