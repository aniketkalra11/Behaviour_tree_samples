import rclpy 
from rclpy.node import Node
from rclpy.node import Rate
from rclpy.action import ActionServer
from geometry_msgs.msg import Point
from sample_bt_msgs.action import FibonaciSeries
from rclpy.action.server import ServerGoalHandle

class FibonaciSeriesServer(Node):
    '''
        This class is a server for the action FibonaciSeries
        It will provide Recive the request and send the response
    '''
    def __init__(self, server_name:str):
        super().__init__(node_name= server_name) # type: ignore
        self.info_logger = self.get_logger().info
        self.info_logger(f'Creating action server for fibonaci series')
        # action
        self.action_server = ActionServer(
            self,
            FibonaciSeries,
            'fibonaci_series',
            self.execute_callback
        )
        self.info_logger(f'Action server for fibonaci series created')




    def execute_callback(self, goal_handle:ServerGoalHandle) -> FibonaciSeries.Result:
        self.info_logger(f'Type for goal handle is: {type(goal_handle)}')
        self.info_logger(f'Executin callback for fibonaci series')
        feedback_msg = FibonaciSeries.Feedback()
        feedback_msg.intermediate_num = 10
        goal_handle.publish_feedback(feedback_msg)
        self.info_logger(f'Feedback sent')
        rate = Rate(19)
        for i in range(10):
            feedback_msg.intermediate_num = i
            goal_handle.publish_feedback(feedback_msg)
            rate.sleep()
        goal_handle.succeed()
        result = FibonaciSeries.Result()
        result.final_output = 100
        return result
    

def main(args= None):
    rclpy.init(args= args)
    node = FibonaciSeriesServer('fibonaci_series_server')
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

