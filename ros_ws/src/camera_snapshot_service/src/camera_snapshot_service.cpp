#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/take_snapshot.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <opencv2/opencv.hpp>

using TakeSnapshot = example_interfaces::srv::TakeSnapshot;

class CameraSnapshotService : public rclcpp::Node
{
public:
    CameraSnapshotService()
        : Node("camera_snapshot_service")
    {
        service_ = this->create_service<TakeSnapshot>("take_snapshot",
            std::bind(&CameraSnapshotService::take_snapshot_callback, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    void take_snapshot_callback(const std::shared_ptr<rmw_request_id_t> request_header,
                                const std::shared_ptr<TakeSnapshot::Request> request,
                                const std::shared_ptr<TakeSnapshot::Response> response)
    {