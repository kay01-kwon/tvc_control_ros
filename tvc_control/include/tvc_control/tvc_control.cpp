#include "tvc_control.h"

tvc_test::tvc_test()
{
    cout<<"Constructor"<<endl;
    nh.getParam("a",a);
    nh.getParam("r",r);
    nh.getParam("h0",h0);

    nh.subscribe("/des_roll_pitch",1,&tvc_test::CallbackDesRollPitch,this);

    cout<<"Width Parameter: "<<a<<endl;
    cout<<"Thrust to Linear Actuator: "<<r<<endl;
    cout<<"Initial Height: "<<h0<<endl;
}

void tvc_test::CallbackDesRollPitch(rollpitch &rp_des)
{
    roll = rp_des.roll;
    pitch = rp_des.pitch;


}

void tvc_test::InverseKinematics(double &roll, double &pitch)
{

}

tvc_test::~tvc_test()
{
    cout<<"Destructor"<<endl;
}