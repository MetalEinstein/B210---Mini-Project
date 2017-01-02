#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <cstdlib>
#include <list>
#include <queue>
#include <stack>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
using namespace std;

int main()
{
    int awnser = 1;
    int first_display;
    char second_display;
    char reply;

    time_t now = time(0);
    tm *ltm = localtime(&now);


   if(ltm->tm_hour < 6-00-00){
    cout << "                         You should sleep, but anyway\n";
   }

   else if(ltm->tm_hour >= 6-00-00 && ltm->tm_hour <= 12-00-00){
    cout << "                              Good Morning And\n";
   }

   else if(ltm->tm_hour > 12-00-00 && ltm->tm_hour < 18-00-00){
    cout << "                              Good Afternoon And\n";
   }

   else if(ltm->tm_hour >= 18-00-00 && ltm->tm_hour < 24-00-00){
    cout << "                              Good Evening And\n";
   }



    cout << "\n";
    cout << "                           WELCOME TO THE PROGRAM\n";
    cout <<"................................................................................\n";
    cout << "\n";

do{
 do{
    cout <<"If you want to take a look at your ROS-NODE library, press [1]\n";
    cout << "\n";
    cout << "You selected: ";
    cin >> first_display;
    cout << "................................................................................\n";
    cout << "\n";

          switch(first_display)
          {
           case 1:
        do
        {


           cout << "To launch the turtlebot, type -> A <-\n";
           cout << "\n" << "\n" << "\n";
           cout << "You can go back to the previous display by typing -> Y <-\n";
           cout << "\n";
           cout << "You selected: ";
           cin >> second_display;
           cout << "................................................................................\n";
           cout << "\n";

                 switch(second_display)
                 {
                   case 'A':

                   system("gnome-terminal -x sh -c 'bash -i -c /home/rasmus/Desktop/Launcher/RosNodes/test.py;' exec bash");
                   sleep(10);
                   system("gnome-terminal -x sh -c 'bash -i -c /home/rasmus/Desktop/Launcher/RosNodes/test2.py;' exec bash");
                   break;

                   case 'Y':

                   break;

                   default:

                   cout << "That case does not yet exist, please try again:\n";
                 }

            }while(second_display != 'A' && second_display != 'Y');


            break;


            default:

            cout << "That case does not yet exist, please try again:\n";
            break;
           }
           }while(second_display == 'Y');

  }while(first_display != 1);

        return 0;

    }

