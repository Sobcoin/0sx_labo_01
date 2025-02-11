int state=0;
int count=0;
int brightness=255;
int fadeAmount=2048/256;
const int ONOFFTIME= 2000;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}
void onLight(){
  if (state ==0){
    digitalWrite(LED_BUILTIN,HIGH);
    delay(ONOFFTIME);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    state=1;
  }  
  Serial.println("Allume - 2379367");
}
 void onOffLight(){
    if (state ==1){
      digitalWrite(LED_BUILTIN,HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN,LOW);
      delay(250);
      count++;
      if(count==4){
        state=2;
        count=0;
      }
    }
    Serial.println("Clignotement - 2379367");
 }  
void variationLight (){
  if(state== 2){
   analogWrite(LED_BUILTIN, brightness); 
   for( brightness;brightness >=0;brightness=brightness-fadeAmount){ 
    analogWrite(LED_BUILTIN,brightness);
    delay(50);
    }
    brightness=255;
    state=0;
  }
  Serial.println("Variation - 2379367");
}
void offLight () {
  if (state ==0){
    digitalWrite(LED_BUILTIN,LOW);
    delay(ONOFFTIME);
  }  
  Serial.println("Eteint - 2379367");
}
void loop() {
  // put your main code here, to run repeatedly:
 onLight();
 onOffLight();
 variationLight();
 offLight();
}
