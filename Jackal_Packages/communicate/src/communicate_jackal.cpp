#include "ros/ros.h"
#include "std_msgs/String.h"
#include "communicate/requestToArm.h"
#include <move_base_msgs/MoveBaseAction.h>  
#include <actionlib/client/simple_action_client.h>

//	map = test-test			map = test-test2
//        x = 0.640;			x = -0.008
//        y = -3.268;			y = -2.917
//        z = 0.000;			z = 0.000
//        orientation_x = 0.000;	orientation_x = 0.000
//        orientation_y = 0.000;	orientation_y = 0.000
//        orientation_z = 0.992;	orientation_z = 0.727 
//        orientation_w = 0.129;	orientation_w = 0.727
//---------------------------------------------------------------------
//        x = 1.127;			x = -3.300
//        y = -0.150;			y = -3.097
//        z = 0.000;			z = 0.000
//        orientation_x = 0.000;	orientation_x = 0.000;
//        orientation_y = 0.000;	orientation_y = 0.000;
//        orientation_z = 0.999;	orientation_z = 0.727;
//        orientation_w = 0.058;	orientation_w = 0.727;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

bool moveToArm(float x, float y, float z,float xx,float yy,float zz,float ww){
    MoveBaseClient ac("move_base", true);
    //wait for the action server to come up  
    while(!ac.waitForServer(ros::Duration(3.0))){  //wait 3 seconds.
         ROS_INFO("Waiting for the move_base action server to come up");  
    }

    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = x;
    goal.target_pose.pose.position.y = y;
    goal.target_pose.pose.position.z = z;
    goal.target_pose.pose.orientation.x = xx;
    goal.target_pose.pose.orientation.y = yy;
    goal.target_pose.pose.orientation.z = zz;
    goal.target_pose.pose.orientation.w = ww;

    // sending goal
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);
    ac.waitForResult(ros::Duration(30.0));

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        ROS_INFO("reach goal!");
        return 1;
    }else{
        ROS_INFO("can not reach goal");
    }
    return 0;
}

int main(int argc, char **argv)
{
  // ROS节点初始化
  ros::init(argc, argv, "Jackal_Request_Arm");
  // 创建节点句柄
  ros::NodeHandle n;
  int flag = 0;    //1:arm1	0:arm2
  communicate::requestToArm srv;
  // 创建一个client，请求connect 
  //--------------- TODO -----------------
  ros::ServiceClient client1 = n.serviceClient<communicate::requestToArm>("request_arm1");
  ros::ServiceClient client2 = n.serviceClient<communicate::requestToArm>("request_arm2");
 
/*
int j = 0;

	while(1){
	//move to arm1
	j = j+1;
	if(j == 4) break;
        ROS_INFO("Jackal move to arm1.");
//	if(moveToArm(-0.378,-2.917,0.000,0.000,0.000,0.707,0.707)){
	if(moveToArm(-0.008,-2.917,0.000,0.000,0.000,0.727,0.727)){
		ROS_INFO("Jackal arrived.");
		ros::Duration(4.5).sleep();
	}else{
		ROS_INFO("Move to arm1: Failed!");
		}
//	if(moveToArm(-3.165,-3.097,0.000,0.000,0.000,0.762,0.688)){
	if(moveToArm(-3.300,-3.097,0.000,0.000,0.000,0.727,0.727)){
		ROS_INFO("Jackal arrived.");
		ros::Duration(4.5).sleep();
	}else{
		ROS_INFO("Move to arm1: Failed!");
		}

	}

*/

/*
 * Test communication.

        //move to arm1
        ROS_INFO("Jackal move to arm1.");
       // sleep(10*1000);
        ROS_INFO("Jackal arrived.");
        ROS_INFO("Jackal begin call server.");
        srv.request.arrive = true;
        if(client1.call(srv) && srv.response.grasp == true){         
               // flag = (flag + 1) % 2;
                ROS_INFO("Jackal call server success.");
            }else{
                ROS_INFO("Call server failed.");
            }
 
*/

/*
int cycle1 = 0;
int cycle2 = 0;
  while(ros::ok()){
      if(flag){
          //move to arm1
        if(moveToArm(-0.008,-2.917,0.000,0.000,0.000,0.727,0.727)){
//        if(moveToArm(0.640,-3.210,0.000,0.000,0.000,0.992,0.129)){
		ROS_INFO("move arm 2 ;");
            srv.request.arrive = true;
            if(client2.call(srv) && srv.response.grasp == true){         
                flag = (flag + 1) % 2;
		cycle1 = cycle1 + 1;
		if((cycle1 + 2) % 4 ==0) {flag = (flag + 1) % 2;}
            }
        }else{
             srv.request.arrive = false;
             ROS_INFO("Move to arm2: Failed!");
            }
      }else{
        //move to arm2
//        if(moveToArm(1.127,-0.150,0.000,0.000,0.000,0.999,0.058)){
        if(moveToArm(-3.300,-3.097,0.000,0.000,0.000,0.727,0.727)){
		ROS_INFO("move arm 1 ;");
            srv.request.arrive = true;
            if(client1.call(srv) && srv.response.grasp == true){         
                flag = (flag + 1) % 2;
		cycle2 = cycle2 + 1;
		if(cycle2 % 4 == 0){flag = (flag + 1) % 2;}
            }
        }else{
            srv.request.arrive = false;
             ROS_INFO("Move to arm1: Failed!");
        }
      }
        
  }
*/

 if(moveToArm(-3.013,-3.004,0.000,0.000,0.000,0.707,0.707)){
		moveToArm(0.001,-2.992,0.000,0.000,0.000,0.707,0.707);
	}
  return 0;
}