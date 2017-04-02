char command;
String string;
int led = 6;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(led, OUTPUT);

}//end of setup--------------------------------------------------------------

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0){
    string = "";
    }    
   while(Serial.available() > 0){
     command = ((byte)Serial.read());
     if(command == ':'){
        break;
     }else{
        string += command;
     }
      delay(1);
   }// end of while---------------------
    if(string == "A"){
      LEDOn();
    }else if(string =="B"){
      LEDOff();
    }
}// end of loop----------------------------------------------------

    void LEDOn(){ 
          digitalWrite(led, HIGH);
          Serial.println(string);
    }

    void LEDOff(){
          digitalWrite(led, LOW);
          Serial.println(string);
    }
