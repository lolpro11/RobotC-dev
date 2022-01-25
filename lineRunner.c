#pragma config(Sensor, S1,     touchSensor,              sensorTouch)
#pragma config(Sensor, S2,     compassSensor,            sensorVirtualCompass)
#pragma config(Sensor, S3,     lightSensor,              sensorLightActive)
#pragma config(Sensor, S4,     sonarSensor,              sensorSONAR)
#pragma config(Motor,  motorA,          gripperMotor,       tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,          tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/***********************************  *\
|*  Programmer: Dominic Diaz          *|
|*                                    *|
|*code completes Line Runner Challenge*|
|*  MAKE SURE TO "SAVE AS" INSTEAD    *|
\***********************************  */



void driveStraight (int powerLevel) {
	string forwardStatus = "Moving Forward...";
	displayTextLine(2, "%s", forwardStatus);
	motor[motorC] = powerLevel;
	motor[motorB] = powerLevel;
}

void driveBack (int powerLevel) {
	string backwardStatus = "Moving Backward...";
	displayTextLine(2, "%s", backwardStatus);
	motor[motorC] = powerLevel;
	motor[motorB] = powerLevel;
	wait1Msec(1000);
}

task main()
{
	int fullPower = 100;
	int partialPower = 30;




	while (SensorValue(touchSensor) == 0) {
		if (SensorValue(lightSensor) > 20) {
			driveStraight(partialPower);
		}

		else if (SensorValue(lightSensor) < 15){
			driveBack(-fullPower);
		}

	}

}