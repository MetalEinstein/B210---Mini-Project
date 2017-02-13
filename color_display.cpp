#include "ros/ros.h"
#include "turtlesim/Color.h"
#include "turtlesim/Pose.h"

/* Topic messages callback. This will display the color frequencies in the terminal  */
void color_callback(const turtlesim::Color::ConstPtr& col)
{
ROS_INFO("red: %d, green: %d, blue: %d", col->r, col->g, col->b);
}

/* Callback from the pose node */
void pose_callback(const turtlesim::Pose& msgIn)
{
ROS_INFO_STREAM(std::setprecision(2) << std::fixed
<< "position=(" << msgIn.x << "," << msgIn.y << ")"
<< "direction=" << msgIn.theta); 
}

int main(int argc, char **argv)
{

 /* Initiate a new ROS node named "color_display" */
 ros::init(argc, argv, "color_display");

 /* create a node handle: it is reference assigned to a new node */
 ros::NodeHandle node;

    
 
 ros::Subscriber subscriber_color = node.subscribe("/turtle1/color_sensor", 1, color_callback);
 ros::Subscriber subscriber_pose=node.subscribe("turtle1/pose", 1, pose_callback);

 /* The ROS spin will make the code enter a loop so we keep getting callbacks */ 
 ros::spin();

    return 0;
}
