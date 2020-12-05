#include <ros.h>                                                                                     
#include <std_msgs/Int16.h>

ros::NodeHandle nh;

void messageCb(const std_msgs::Int16& msg){
	for(int i=0; msg.data>i; i++){
		digitalWrite(11, HIGH);
		delay(100);
		digitalWrite(11, LOW);
		delay(100);
	}
}

ros::Subscriber<std_msgs::Int16> sub("blink_times", &messageCb );

void setup(){
	pinMode(11, OUTPUT);
	digitalWrite(11, LOW); 

	nh.initNode();
	nh.subscribe(sub);
}

void loop(){
	nh.spinOnce();
	delay(1);
}
/****** END OF FILE *********/        
