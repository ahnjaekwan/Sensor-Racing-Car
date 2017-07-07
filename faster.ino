//Name: Jaekwan Ahn, Jeffery Yang
//Team: Ronaldo



//left motor

int lpinA1 = 5;
int lpinD2 = 2;
int lpinD3 = 3;

//right motor

int rpinA1 = 9;
int rpinD2 = 6;
int rpinD3 = 7;

//left sensor
int lsensor = A5;

//right sensor
int rsensor = A4;

//flag to detect car presence
int flag = 1; //1 for left side, 2 for right side

void setup() {
  //left motor
  pinMode(lpinA1,OUTPUT);
  pinMode(lpinD2,OUTPUT);
  pinMode(lpinD3,OUTPUT);

  //right motor
  pinMode(rpinA1,OUTPUT);
  pinMode(rpinD2,OUTPUT);
  pinMode(rpinD3,OUTPUT);
  
  delay(100);
  analogWrite(lpinA1,110); analogWrite(rpinA1,100);
  digitalWrite(lpinD2,HIGH); digitalWrite(lpinD3,LOW);
  digitalWrite(rpinD2,HIGH); digitalWrite(rpinD3,LOW);
  analogWrite(lpinA1,80); analogWrite(rpinA1,65);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lread = analogRead(lsensor);
  int rread = analogRead(rsensor);
  if (lread < 73 && rread >= 70){    //left turn, right wheel moves faster
    analogWrite(lpinA1, 85); analogWrite(rpinA1,255); 
    flag = 2;
  }
  else if (rread < 70 && lread >= 73) { //right turn
    analogWrite(lpinA1,255); analogWrite(rpinA1,85);
    flag = 1;
  }
  else if (rread < 70 && lread < 73) {
    if(flag == 1){ //right turn
      analogWrite(lpinA1,255); analogWrite(rpinA1,85);
    } else{ //flag=2, left turn
      analogWrite(lpinA1,85); analogWrite(rpinA1,255);
    }
  } 
  else{
    analogWrite(lpinA1,255); analogWrite(rpinA1,255);
  }
  
}
