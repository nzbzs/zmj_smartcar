#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "dynamic_tf_broadcaster");
    ros::NodeHandle node;

    tf2_ros::TransformBroadcaster broadcaster;
    ros::Rate rate(10.0);

    while (node.ok()) {
        geometry_msgs::TransformStamped t;
        t.header.stamp = ros::Time::now();
        t.header.frame_id = "odom";
        t.child_frame_id = "base_link";

        // 设置变换参数
        t.transform.translation.x = 0.1;
        t.transform.translation.y = 0.2;
        t.transform.translation.z = 0.0;
        t.transform.rotation.x = 0.0;
        t.transform.rotation.y = 0.0;
        t.transform.rotation.z = 0.0;
        t.transform.rotation.w = 1.0;

        broadcaster.sendTransform(t);
        rate.sleep();
    }

    return 0;
}