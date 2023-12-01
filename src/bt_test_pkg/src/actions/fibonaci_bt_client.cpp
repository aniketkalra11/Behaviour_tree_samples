#include "bt_test_pkg/actions/fibonaci_bt_client.hpp"

namespace template_bt_samples_ns
{
  SampleBtActionExample::SampleBtActionExample
  (const std::string& name, const BT::NodeConfig& conf, const BT::RosNodeParams& params)
  : BT::RosActionNode<FIBONACI_ACTION_MSG>(name, conf, params)
  , logger_(rclcpp::get_logger("SampleBtActionExample"))
  {
    RCLCPP_INFO_STREAM(logger_, "Creating SampleBtaction Example");
    
  }

  // This method will set the goal value true and send a random number to the action server
  bool SampleBtActionExample::setGoal(Goal& goal) 
  {
    goal.ending_num = 10;
    
    return true;
  }

  BT::NodeStatus SampleBtActionExample::onResultReceived(const WrappedResult& result)
  {
    return BT::NodeStatus::SUCCESS;
  }

  BT::NodeStatus SampleBtActionExample::onFeedback(const std::shared_ptr<const Feedback> fb)
  {
    return BT::NodeStatus::RUNNING;
  }

}