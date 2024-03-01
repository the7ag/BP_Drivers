#include <Arduino_FreeRTOS.h>

int dist=0;
int minDistance=25,Kp=(8),Ki=(1),Kd=(0),T=50,prevErr=0,newSpeed=0;
unsigned long last_time=0;
int trig=30,echo=28;
int M1F=3,M1B=4,M1S=2,M2F=5,M2B=6,M2S=7;
//int IN1=3,IN2=4,IN3=5,IN4=6,EN1=2,EN2=7;
double error;
double p,i,d;

void Task_ACC(void *param);
void Task_CollisionWarning(void *param);
void Task_readUS(void *param);

TaskHandle_t Task_ACC_Handler;
TaskHandle_t Task_CollisionWarning_Handler;
TaskHandle_t Task_ReadUS_Handler;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(M1F,OUTPUT);
  pinMode(M1B,OUTPUT);
  pinMode(M1S,OUTPUT);
  pinMode(M2F,OUTPUT);
  pinMode(M2B,OUTPUT);
  pinMode(M2S,OUTPUT);
  Serial.begin(9600);
  //the highest priority will run first, the highest number is the highest priority
  xTaskCreate(Task_ACC,"ACC",1000,NULL,1,&Task_ACC_Handler);
  xTaskCreate(Task_readUS,"readUS",1000,NULL,1,&Task_ReadUS_Handler);
  xTaskCreate(Task_CollisionWarning,"Collision_warning",1000,NULL,1,&Task_CollisionWarning_Handler);
}

void loop() {}

void Task_ACC(void *param)
{
  (void) param;
  while(1){

    Serial.println("ACC");
    if(dist!=0)
    {
      pidAlgo(dist);
      if(dist <= minDistance)
      {
        AEB();
      }
    }
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void Task_readUS(void *param)
{
  (void) param;
  while(1){
    Serial.println("US");
    dist = 0;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    dist = pulseIn(echo, HIGH);
    dist = dist * 0.034 / 2;
    Serial.print("distance: ");
    Serial.println(dist);
     vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}
void Task_CollisionWarning(void *param){
  (void) param;
  while(1){
    // Prints the Warning messages
    Serial.println("collision");
    if(dist <= 50 && dist > 25){
      Serial.println("Need to pay attention!");
    } 
    else if(dist > 50){
      Serial.println("safe, No warning needed");
    }
    else if(dist <= 25){
      Serial.println("RED FLAG");
    }
    else{
      Serial.println("Error!");
    }
   vTaskDelay(1000/portTICK_PERIOD_MS);

  }
}
void AEB()
{
  digitalWrite(M1S,LOW);
  digitalWrite(M2S,LOW);
}
void pidAlgo(int position)
{
  if(millis() - last_time >= T)
  {
    last_time=millis();
    error=position-minDistance;
    p=error;
    i=error+i;
    if(i <= -255) i=-255;
    if (i>=0) i=0;
    d=error-prevErr;
    newSpeed=(Kp*p)+(Ki*i*T)+((Kd/T)*d);
    prevErr=error;
    motorControl(newSpeed);
  }
}
void motorControl(int newSpeed)
{
  digitalWrite(M1F,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2F,HIGH);
  digitalWrite(M2B,LOW);
  if (newSpeed <=255 & newSpeed >=0){
    analogWrite(M1S, newSpeed);  //set motor speed 
    analogWrite(M2S, newSpeed);  //set motor speed 
  }
  else{
    if (newSpeed >=255){
      analogWrite(M1S, 255);  //set motor speed 
      analogWrite(M2S, 255);  //set motor speed 
    }
    else{
      AEB();
    }
  }
}
