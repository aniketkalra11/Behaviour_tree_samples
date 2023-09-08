#include "rclcpp/rclcpp.hpp"
#include "behaviortree_ros2/bt_action_node.hpp"
#include "sample_bt_msgs/action/fibonaci_series.hpp"


using FIBONACI_ACTION_MSG = sample_bt_msgs::action::FibonaciSeries;
namespace template_bt_samples
{
  class SampleBtActionExample : public BT::RosActionNode<FIBONACI_ACTION_MSG>
  {
    SampleBtActionExample
    (const std::string& name, const BT::NodeConfig& conf, const BT::RosNodeParams& node_param);
    virtual bool setGoal(Goal& goal)
    {
      goal.ending_num = 10;
      return true;
    }
    virtual BT::NodeStatus onResultReceived(const WrappedResult& result)
    {
      return BT::NodeStatus::SUCCESS;
    }
    virtual BT::NodeStatus onFeedback(const std::shared_ptr<const Feedback> fb)
    {
      (void)fb->intermediate_num;
      RCLCPP_INFO_STREAM(rclcpp::get_logger("Action"), "Feedback Received");
      return BT::NodeStatus::RUNNING;
    }
  };

}