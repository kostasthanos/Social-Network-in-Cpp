// friendrequest.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//=============================
// Accept/Reject Friend Request
//=============================
#ifndef FRIENDREQUEST_H
#define FRIENDREQUEST_H

// Local header files
#include "goback.h"

void friendrequest()
{
    cout << "\e[1mACCEPT/REJECT FRIEND REQUEST\e[0m" << endl;
    string line;
    string moreRequests = "Y";
    
    // Create file to save names of users who have sent requests to the logged in user 
    ofstream tempreq("TempReq");
    
    ifstream freq;
    freq.open("Requests"); // Open file with friends' requests
    
    // Create temporary file to remake Requests text file
    ofstream mytemp;
    mytemp.open("Temp");    
    
    // Process to save names of users who have sent requests to the logged in user 
    while(getline(freq, line))
    {
        // Check if logname exists in line (find method) and also not to be at the beggining of the line
        if((line.find(logname) != std::string::npos) && ((line.substr(0, line.find(" "))!=logname)))
            tempreq << line.substr(0, line.find(" ")) << endl;
        else
            mytemp << line << endl;
    }
    mytemp.close();
    remove("Requests");
    rename("Temp", "Requests");
    tempreq.close();
    
    // Process to choose whether to accept or not a friend request
    while(moreRequests!="Y" || moreRequests!="y"){
        ifstream temppreq;
        temppreq.open("TempReq"); // Open temporary file
        
        cout << "Requests from" << endl << string(14,'=') << endl;
        // Print a numbered list of users who have sent frined request to the logged in user
        int lineCount=1; 
        while(getline(temppreq, line) && line!=""){
            cout << "[" << lineCount << "] " << line << endl;
            lineCount++;
        }
        temppreq.close();
        
        int friendNumber;
        cout << endl << "\e[3m(Type the number of user you want to accept)\e[0m" << endl;
        cout << "Choice : ";
        cin >> friendNumber;
        
        ifstream tempReq;
        tempReq.open("TempReq"); // Open file of users who have sent request
        
        int j=0;
        // Add the user who have sent the request to the file of the logged in user
        // without deleting the existing text - (ios::app)
        ofstream userFile(logname.c_str(), ios::app);
        ofstream temporary("MyTemp");
        while(getline(tempReq, line) && line!=""){
            j++;
            if(friendNumber == j)
            {
                // Add friend's name to the file of user who have sent a request that has been accepted
                userFile << line << endl;
                // Add the logged in user's name in the file of user who have sent the request
                ofstream otherfile(line.c_str(), ios::app);
                otherfile << logname << endl;
                otherfile.close();
                // Replace name of accepted friend's request with empty string
                temporary << " " << endl;
            }
            else
                temporary << line << endl;
        }
        temporary.close();
        tempReq.close();
        remove("TempReq");
        rename("MyTemp", "TempReq");
        userFile.close();
            
        cout << endl << "Accept more requests ? (Y/N) : ";
        cin >> moreRequests;
        // Choose whether to accept or not more friend requests
        if(moreRequests=="Y" || moreRequests=="y")
            continue;
        else
        {
            goback();
            break;
        }
    }
}


#endif // FRIENDREQUEST_H
