#include "mbed.h"
#include "uLCD_4DGL.h"
DigitalIn b0(D10);
DigitalIn b1(D11);
DigitalIn b2(D12);
AnalogOut aout(PA_4);
AnalogIn ain(A0);
uLCD_4DGL uLCD(D1, D0, D2);
Thread t1;

void sampling(){
  float adcdata;
  int rate=800; 
  while(1){   
    adcdata=ain;
    printf("%f\r\n",adcdata);
    ThisThread::sleep_for(1000ms/rate);
  }
}

void generate_wave(int weight){ //100,200,300
  float i=0;
  while(1){
  while(i<=90){
    i+=0.01285*weight;
    aout=0.01*i;
    wait_us(50);
  }
  while(i>0){
    i-=0.03*weight;
    aout=0.01*i;
    wait_us(50);
  }
  }
} 

main()
{
  int weight=100;
  int freq=79;

  while(1){
    if(b0.read()){
      weight+=100;
      uLCD.cls();
      uLCD.printf("freq:%d",freq*(weight/100));
    }
    if(b1.read()){
      weight-=100;
      uLCD.cls();
      uLCD.printf("freq:%d",freq*(weight/100));
    }
    if(b2.read()){
      break;
    }
  }
  t1.start(sampling);
  generate_wave(weight);
}