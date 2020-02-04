// goback.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//=====================
// Go back to Main Menu
//=====================
#ifndef GOBACK_H
#define GOBACK_H

// Local header files
#include "exxit.h"

void menu2(); 

void goback()
{
    cout << endl << "Go back to main menu ? (Y/N) : ";
    string choice;
    cin >> choice;
    // User inputs "Y or y" if he wants to go back to menu2
    // else the program is being terminated
    if(choice=="Y" || choice=="y")
        menu2();
    else
        exxit();
}


#endif // GOBACK_H
