#include "BiWheel.h"\
#define maxLight 123 //надо измерить
biWheel chassis = biWheel(11, 3, 9, 10);
void setup()
{
	pinMode(4, INPUT);

}
void loop()
{
	int power;
	int leftLight = analogRead(A0);
	int rightLight = analogRead(A1);
	if(digitalRead(4)==0){
		chassis.drive(0,0);	    //если видит чет ближе чем 20 см, останавливается
	}
	if(leftLight>rightLight){
		power=map(leftLight-rightLight,0,maxLight,0,100);
		chassis.drive(100,100-power);						//тут и в следующем условии я использую примерную логику движения по линии, там ее еще надо стабилизировать
	}
	if(rightLight>leftLight){
		power=map(rightLight-leftLight,0,maxLight,0,100);
		chassis.drive(100-power,100);
	}

}