#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

class CameraSubscriber : public rclcpp::Node
{
public:
    CameraSubscriber() : Node("camera_subscriber")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            "/camera_sensor/image_raw",
            10,
            std::bind(&CameraSubscriber::imageCallback, this, std::placeholders::_1));
    }

private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        try
        {
            // Convert the ROS Image message to OpenCV format using CvBridge
            cv::Mat cv_image = cv_bridge::toCvShare(msg, "bgr8")->image;

            // Display the image using OpenCV
            cv::imshow("Camera Image", cv_image);
            cv::waitKey(1);
        }
        catch (cv_bridge::Exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        }
    }
};

int main(int argc, char * argv[])
{
    // Initialize ROS 2
    rclcpp::init(argc, argv);
    
    // Create a node instance
    auto node = std::make_shared<CameraSubscriber>();
    
    // Spin the node so it keeps running and processing callbacks
    rclcpp::spin(node);
    
    // Shutdown and cleanup
    rclcpp::shutdown();
    cv::destroyAllWindows();
    return 0;
}
