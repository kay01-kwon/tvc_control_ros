#ifndef TVC_CONTROL_H
#define TVC_CONTROL_H

#include <ros/ros.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <lm4075e_msgs/Int32.h>
#include <tvc_control/rollpitch.h>
#include <iostream>

using std::cout;
using std::endl;

using lm4075e_msgs::Int32;
using tvc_control::rollpitch;

const double Length2Count = 1000.0/46.0; // 1000 count = 46 mm

class tvc_test{

    public:

    // Constructor
    tvc_test();
    
    // Desired Roll Pitch Callback Function
    void CallbackDesRollPitch(rollpitch & rp_des);
    void InverseKinematics(double &roll, double &pitch);

    // Destructor
    ~tvc_test();

    private:
    ros::NodeHandle nh;
    ros::Subscriber roll_pitch_subscriber;
    ros::Publisher des_pos_publisher;
    
    // Parameters
    double a,r, h0;
    
    // rp_des data
    double roll, pitch;

    // Position(Count) data to publish
    int pos_l, pos_r;

};


#endif