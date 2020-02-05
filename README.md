# Social-Network-in-C++
 A simple C++ example of social media.

## How to run the program
**1.** Open terminal
**2A.** Install gcc (g++) the C++ compiler.
   ```
   $ sudo apt install g++
   ```
**2B.** Install build-essential. This package will also install libraries as well as the gcc compiler.
   ```
   $ sudo apt-get install build-essential
   ```
**3.** Check the gcc version
   ```
   $ gcc –version
   ```
**4.** Go to the folder of the program. Write the path to the folder.
   ```
   $ cd /path_to_folder/folder
   ```
**5.** Compiling the C++ program (**main.cpp**).
   ```
   $ sudo g++ main.cpp 
   ```
**6.** Run the C++ program.
   ```
   $ ./main
   ```
   
## Folders and Files

### Folders
The only folder exists is the folder of the header files (**header_files**). More details about the header files later.

### User files
Each user file has as file name the name of the corresponding user and contains
other users with whom they are friends.  
For example if we take the file with name *kostas* then this file contains all friends of user **kostas**.  
The following files have already been created for easier understanding and use of this social network.

```
kostas
maria
tom
george
anna
john
```

### Network files
1. **conversations**  
   Contains conversations between users and their friends. It follows the form :

   ```
   Logged_in_user : post_of_logged_in_user
                    reply_from_friend_user (name_of_friend)
                    
2. **database**  
   Contains pairs of usernames and passwords from all of the registered users in the Social Network.

   ```
   user1
   password_of_user1
   user2
   password_of_user2
   ```

3. **likes**  
   Contains posts of users and likes from friends and their names.

   ```
   Logged_in_user : post_of_logged_in_user
                    LIKE! (name_of_friend)
   ```

4. **posts**  
   Contains posts from all of the registered users in the Social Network.

   ```
   user_name_1
   post_of_user_name_1
   user_name_2
   post_of_user_name_2
   ```
 
5. **Requests**  
   Contains friends' requests that have been sent from a user to another user with whom they are not friends.

   ```
   user_sent_request -> user_to_accept/reject_request
   ```

6. **TempReq**  
   A temporary file used in the program.

7. **users**  
   Contains only the names of all registered users in the Social Network.

## Header files

### Basic Header files
The main header files used in the program are :

```
iostream, fstream, sstream, unistd.h
```

### Local Header files
The header files contained in the header files folder, used in the program are:

* mainmenu.h 
* registration.h 
* login.h
* menu2.h 
* viewposts.h
* viewfriendposts.h
* menu3.h
* friendrequest.h
* friends.h
* deletefriends.h
* listusers.h
* goback.h
* exxit.h
 
**mainmenu.h**  
The very first menu that user can see. User can select one of the 3 available choices :

```
1) Register
2) Log In
3) Exit the program
```

by pressing the number which corresponds to his choice (1,2,3). If user presses a number different from the given ones then he goes back to the first menu. 

**registration.h**  
The user logs in with the desired username and password. If any of these already exists then user is being asked to repeat the process. If the process is done correctly then he can choose from 3 options :  

```
1) Log In
2) Return to main menu 
3) Exit the program
```

**login.h**  
Initially a check is made whether the user is already registered or not. Then user enters his username and password and goes to the second menu.

**menu2.h**  
After the user logs in successfully he enters the Social Network menu where he can choose one of the following options :

```
1) My wall
2) Friend’s wall
3) Send friend request
4) Accept/Reject friend request
5) My friends
6) Delete friend
7) Back
8) Log out
9) Exit the program
```

**viewposts.h**  
By choosing the first option *My wall* from the above menu the user can see one of the following:

```
i) His own posts
ii) His friends' posts
iii) Conversations with friends
iv) Likes of friends to his own posts
```
Finally he is being asked to return to the Social Network menu or not.

**viewfriendposts.h**  
By selecting *Friend's wall* from the menu, user can choose one of the following options:

```
i) Post a message on his wall
ii) Reply to a post
iii) Leave a Like
iv) Main Menu
```
- If he chooses the first one **(i)**, he can write the post that he wants and this will be added to the posts file at the end after the login name is added above.  
- If he chooses the second option **(ii)**, then he can choose one of his friends, view friend's posts and choose the post that he wants to reply on. The user then writes the reply which is stored in the **conversations** file as a reply to the friend's post. This reply will be saved with his name in brackets at the end. Finally, the logged-in user can reply to another post of the same friend if he wants.  
- If he chooses the third option **(iii)**, then the process is exactly the same as before but instead of a reply, user leaves a LIKE! which is stored in the **likes** file under the selected friend's post and before the older likes.  
- If he chooses the 4th option **(iv)**, he returns to the Social Network menu.

**menu3.h**  
By selecting *Send friend request* the logged in user can send a friend request to someone of the registered users with whom he is not already friends.  
By pressing the number that corresponds to the desired friend-user, the request is being saved in the **Requests** file as :

```
user_to_sent_request → user_to_accept/reject_request
```
Finally user can also choose whether to send or not a friend request to other non-friend users. 

**friendrequest.h**  
By selecting *Accept/Reject friend request* the logged in user can check all of the requests that he has received and he can press the number which corresponds to the name of user he wants to accept the request. When a request is accepted, then the two users are added to each user's file as a friend and the request is deleted from the **Requests** file. If there are additional friend requests but the user exits the Accept/Reject friend request menu then this is equivalent to rejecting the rest of the requests.  

**friends.h**  
By selecting *My friends* the logged in user can check the other registered users with whom he is friend and then he can return to the Social Network menu if he wants. 

**deletefriends.h**  
By selecting *Delete friend* the logged in user can see a list of his friends and if he wants he can delete one of them by typing the number which corresponds to the friend he wants to delete. Then the two involved users are going to be deleted from each other's file. Finally the user can delete more friends if he wants. 

**listusers.h**  
Counts the number of all registered users by reading from the database file the pairs (username-password).

**goback.h**  
By selecting *Back* the logged in user can return to the menu or leave the Social Network and the program. If user selects the *Log out* option then he will return to the first menu of the program.

**exxit.h**  
By selecting *Exit the program* the logged in user leaves the Social Network. The program is being terminated and a message appears like the following one.

```
Program termination
Thanks for your visit logged_in_user_name !
```

## Author
**Konstantinos Thanos**
