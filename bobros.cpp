#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>
#include <ctime>
#include <time.h>
#include <iostream>
#include <stdlib.h>


ros::Publisher velocity_publisher;

const double PI = 3.14159265359;

void move(double speed, double distance, bool isForward);
void rotate(double angular_speed, double angle, bool cloclwise);
double degrees2radians(double angle_in_degrees);
int first_display;
char second_display;
char reply;

using namespace std;

int main(int argc, char **argv)
{
	/* Initiate new ROS node named "bobros" */
	ros::init(argc, argv, "bobros");
	ros::NodeHandle n;
	double speed, angular_speed;
	double distance, angle;
	bool isForward, clockwise;
        time_t now = time(0);
        tm *ltm = localtime(&now);

	velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
	ros::Rate loop_rate(100);
	/*	/turtle1/cmd_vel is the Topic name and /geometry_msgs::Twist is the msg type  */
        
        cout << "\n";

        if(ltm->tm_hour < 6){
        cout << "You should sleep, but anyway\n";
        }

        else if(ltm->tm_hour >= 6 && ltm->tm_hour <= 12){
        cout << "Good Morning User\n";
        }

        else if(ltm->tm_hour >= 12 && ltm->tm_hour <= 18){
        cout << "Good Afternoon User\n";
        }

        else if(ltm->tm_hour >= 18 && ltm->tm_hour <= 24){
        cout << "Good Evening User\n";
        }
    
        cout << "\n";
	
  do{
   do{
    cout <<"If you want to have a look at the different shapes, press [1]\n";
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


           cout << "To make a star, type -> A <-\n";
           cout << "\n";
           cout << "To make a boring square, type -> B <-\n";
           cout << "\n" << "\n" << "\n";
           cout << "You can go back to the previous display by typing -> Y <-\n";
           cout << "\n";
           cout << "You selected: ";
           cin >> second_display;
           cout << "................................................................................\n";
           cout << "\n";

                 switch(second_display)
                 {
                  case 'A':   /* This case will make a star */

                  rotate(degrees2radians(70), degrees2radians(90), 1);
                  /* Here we are rotating with a desired speed and angle (1 = Counterclockwise and 0 = Clockwise) */
    
                  rotate(degrees2radians(70), degrees2radians(36), 0);
                  move(6, 2, 1); /* Here we are moveing with a desired speed, distance and in forward motion (1 = forward and 0 = backward */

                  rotate(degrees2radians(70), degrees2radians(144), 0);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(72), 1);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(144), 0);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(72), 1);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(144), 0);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(72), 1);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(144), 0);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(72), 1);
                  move(6, 2, 1);

                  rotate(degrees2radians(70), degrees2radians(144), 0);
                  move(6, 2, 1);
        
	          ros::spin();

                   break;

                   case 'B':   /* This case will make a square */ 
        
                   move(6, 3, 1);

                   rotate(degrees2radians(70), degrees2radians(90), 0);
                   move(6, 3, 1);

                   rotate(degrees2radians(70), degrees2radians(90), 0);
                   move(6, 3, 1);

                   rotate(degrees2radians(70), degrees2radians(90), 0);
                   move(6, 3, 1);


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



void move(double speed, double distance, bool isForward){
   geometry_msgs::Twist vel_msg;
   /* set a random linear velocity in the x-axis */
   if (isForward)
	   vel_msg.linear.x =abs(speed);
   else
	   vel_msg.linear.x =-abs(speed);
   vel_msg.linear.y =0;
   vel_msg.linear.z =0;
   /* set a random angular velocity in the y-axis */
   vel_msg.angular.x = 0;
   vel_msg.angular.y = 0;
   vel_msg.angular.z =0;

   double t0 = ros::Time::now().toSec();
   double current_distance = 0.0;
   ros::Rate loop_rate(100);
   do{
	   velocity_publisher.publish(vel_msg);
	   double t1 = ros::Time::now().toSec();
	   current_distance = speed * (t1-t0);
	   ros::spinOnce();
	   loop_rate.sleep();
	  
   }while(current_distance<distance);
   vel_msg.linear.x =0;
   velocity_publisher.publish(vel_msg);

}



void rotate (double angular_speed, double relative_angle, bool clockwise){

	   geometry_msgs::Twist vel_msg;

	   /* set a random linear velocity in the x-axis */

	   vel_msg.linear.x =0;
	   vel_msg.linear.y =0;
	   vel_msg.linear.z =0;

	   /* set a random angular velocity in the y-axis */

	   vel_msg.angular.x = 0;
	   vel_msg.angular.y = 0;
	   if (clockwise)
	   	vel_msg.angular.z =-abs(angular_speed);
	   else
	   	vel_msg.angular.z =abs(angular_speed);

	   double t0 = ros::Time::now().toSec();
	   double current_angle = 0.0;
	   ros::Rate loop_rate(1000);
	   do{
		   velocity_publisher.publish(vel_msg);
		   double t1 = ros::Time::now().toSec();
		   current_angle = angular_speed * (t1-t0);
		   ros::spinOnce();
		   loop_rate.sleep();
		  
	   }while(current_angle<relative_angle);
	   vel_msg.angular.z =0;
	   velocity_publisher.publish(vel_msg);
}

/*
   converts angles from degree to radians  
*/

double degrees2radians(double angle_in_degrees){
	return angle_in_degrees *PI /180.0;
}
