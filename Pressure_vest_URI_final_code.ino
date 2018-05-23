/******************************************************************************
PIN NO: A0,A1 and A2 are for the 3 flex sensors at the back 
Pin No: A3,A4 are for 2 flex sensors in the front
pin no: A9 for neck
pin no: 


******************************************************************************/
const int FLEX_PIN1 = A0; // for the front LATITUDIONAL ORIENTATION 
const int FLEX_PIN4 = A3; // for the front straight
const int FLEX_PIN2 = A1; //BACK MIDDLE
const int FLEX_PIN3 = A2; //BACK TOP
const int FLEX_PIN5 = A4; //BACK BOTTOM


//Assigning pins for the pressure sensors
const int Pressure_sensor1= A9; //neck
const int Pressure_sensor2= A14;//right shoulder blade
const int Pressure_sensor3= A15;//left shoulder blade
const int Pressure_sensor4= A11;//left shoulder top
const int Pressure_sensor5= A13;//right shoulder top
const int Pressure_sensor6= A10;//left shoulder front
const int Pressure_sensor7= A12;//right shoulder front

//putting the intitial values to be zero
int sensorValue1 = 0;        
int sensorValue2 = 0;        
int sensorValue3 = 0;        
int sensorValue4 = 0;        
int sensorValue5 = 0;        
int sensorValue6 = 0;
int sensorValue7 = 0;        
        

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 22000.0; // Measured resistance of 3.3k resistor

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 13200.0; // resistance when straight
const float BEND_RESISTANCE = 30000.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(2400);
  
  //declaring the pins for flex sensors as input
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN3, INPUT);


  //giving the voltage to the pressure sensors
  digitalWrite(Pressure_sensor1, HIGH);
  digitalWrite(Pressure_sensor2, HIGH);
  digitalWrite(Pressure_sensor3, HIGH);
  digitalWrite(Pressure_sensor4, HIGH);
  digitalWrite(Pressure_sensor5, HIGH);
  digitalWrite(Pressure_sensor6, HIGH);
  digitalWrite(Pressure_sensor7, HIGH);

  //specify the key nos for each of the operation
  Serial.println("please press the appropiate key according to requirement");
  Serial.println();
  Serial.println("press 1 for flex sensors (three) at the back");
  Serial.println("press 2 for flex sensors (two) in the front");
  Serial.println("press 3 for pressure sensors at the neck");
  Serial.println("press 4 for pressure sensors at the front of shoulder near the chest");
  Serial.println("press 5 for pressure sensors at the shoulder blades");
  Serial.println("press 6 for pressure sensors on the uppers side of shoulders");

  while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available());                 // wait for data
     
}

void loop() 
{ 
  int input_data;
  static int flag=0;
  if(flag==0){
  input_data = Serial.read()-'0';
  flag=1;
  }
  static int input=input_data;
  
                          ///////////////////FLEX SENSORS /////////////////////////////////

  //////////FLEX SENSORS AT THE BACK//////////
  if(input==1){
  int flexADC1 = analogRead(FLEX_PIN1);
  float flexV1 = flexADC1 * VCC / 1023.0;
  float flexR1 = R_DIV * (VCC / flexV1 - 1.0);
  
  int flexADC2 = analogRead(FLEX_PIN2);
  float flexV2 = flexADC2 * VCC / 1023.0;
  float flexR2 = R_DIV * (VCC / flexV2 - 1.0);

  int flexADC3 = analogRead(FLEX_PIN3);
  float flexV3 = flexADC3 * VCC / 1023.0;
  float flexR3 = R_DIV * (VCC / flexV3 - 1.0);

  Serial.print(flexR1);
  Serial.print(",");
  Serial.print(flexR2);
  Serial.print(",");
  Serial.print(flexR3);
  Serial.println();
  }

  else if(input==2){
  /////////FLEX SENSORS FOR FRONT//////////////////
  int flexADC4 = analogRead(FLEX_PIN4);
  float flexV4 = flexADC4 * VCC / 1023.0;
  float flexR4 = R_DIV * (VCC / flexV4 - 1.0);
  
  int flexADC5 = analogRead(FLEX_PIN5);
  float flexV5 = flexADC5 * VCC / 1023.0;
  float flexR5 = R_DIV * (VCC / flexV5 - 1.0);

  Serial.print(flexR4);
  Serial.print(",");
  Serial.print(flexR5);
  Serial.println();
  }
 
                          ////////////////////PRESSURE SENSORS////////////////////
  ////pressure sensors for the neck/////
  else if (input == 3){
  sensorValue1 = analogRead(Pressure_sensor1);
  Serial.print(sensorValue1);
  Serial.println();
  }
  //pressure sensors for shoulder Blades////
  if(input==5){
  sensorValue2 = analogRead(Pressure_sensor2);
  sensorValue3 = analogRead(Pressure_sensor3);
  Serial.print(sensorValue2);
  Serial.print(",");
  Serial.print(sensorValue3);
  Serial.println();
  }
  
  
  ///pressure sensors for shoulder top////
  else if(input==6){
  sensorValue4 = analogRead(Pressure_sensor4);
  sensorValue5 = analogRead(Pressure_sensor5);
  Serial.print(sensorValue4);
  Serial.print(",");
  Serial.print(sensorValue5);
  Serial.println();
  }
  
  
  ///pressure sensors for shoulder front///
  else if(input==4){
  sensorValue6 = analogRead(Pressure_sensor6);
  sensorValue7 = analogRead(Pressure_sensor7);
  Serial.print(sensorValue6);
  Serial.print(",");
  Serial.print(sensorValue7);
  Serial.println();
  }
  
}

