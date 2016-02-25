
#define MOTOR_B_DIR 12
#define MOTOR_B_PWM 11   //пусть мотор B - левый, а A - правый
#define MOTOR_A_PWM 3 
#define MOTOR_A_DIR 5 
#define maxLight 123 //надо измерить



 
void setup()
{
  Serial.begin( 9600 );
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );
  pinMode(4, INPUT);
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );
}
 
void loop()
{

  int power;
  int leftLight = analogRead(A0);
  int rightLight = analogRead(A1);
  if(digitalRead(4)==0){
    digitalWrite( MOTOR_B_DIR, LOW );
    digitalWrite( MOTOR_B_PWM, LOW); 
    digitalWrite(MOTOR_A_DIR,LOW);
    digitalWrite(MOTOR_A_PWM, LOW);     //если видит чет ближе чем 20 см, останавливается
  }
  if(leftLight>rightLight){
    power=map(leftLight-rightLight,0,maxLight,0,100);
    digitalWrite( MOTOR_B_DIR, HIGH );
    analogWrite( MOTOR_B_PWM, map(100-power, 0, 100, 0, 255)); 
    digitalWrite(MOTOR_A_DIR,HIGH);
    analogWrite(MOTOR_A_PWM, 255);         //тут и в следующем условии я использую примерную логику движения по линии, там ее еще надо стабилизировать
  }
  if(rightLight>leftLight){
    power=map(rightLight-leftLight,0,maxLight,0,100);
    digitalWrite( MOTOR_A_DIR, HIGH );
    analogWrite( MOTOR_A_PWM, map(100-power, 0, 100, 0, 255)); 
    digitalWrite(MOTOR_B_DIR,HIGH);
    analogWrite(MOTOR_B_PWM, 255); 
  }
    


        // always stop motors briefly before abrupt changes
/*        digitalWrite( MOTOR_B_DIR, LOW );
        digitalWrite( MOTOR_B_PWM, LOW );
        delay( DIR_DELAY );
        // set the motor speed and direction
        digitalWrite( MOTOR_B_DIR, HIGH ); // direction = forward
        analogWrite( MOTOR_B_PWM, 255-PWM_FAST ); // PWM speed = fast
        isValidInput = true;
        break;      
         

  // repeat the main loop and redraw the menu...*/
}