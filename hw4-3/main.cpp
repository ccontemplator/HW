#include "mbed.h"
#include "stdlib.h"
#include "bbcar.h"
#include "bbcar_rpc.h"


Ticker servo_ticker;
DigitalOut led1(LED1);
DigitalInOut pin12(D12);

PwmOut pin10(D10), pin11(D11);
BBCar car(pin10, pin11, servo_ticker);
BufferedSerial pc(USBTX,USBRX); //tx,rx
BufferedSerial uart(D1,D0); //tx,rx


int main(){
   parallax_ping  ping1(pin12);
   char buf[10];
   uart.set_baud(9600);
   int i=0;
   float x=0;
   bool flag=true;

   

   while(flag){
      if(uart.readable()){
           /* car.goStraight(40);
            ThisThread::sleep_for(2000ms);*/
            char recv[1];
            uart.read(recv, sizeof(recv));
            buf[i++]=recv[0];

            if(recv[0] == '\n'){
                x = atof(buf);
                printf("%f\n",x);
                i=0;

                if(x<-0.8){//left
                    //car.goStraight(20);
                    //ThisThread::sleep_for(300ms);
                    car.turn(20,-0.6); //turn right
                    ThisThread::sleep_for(320ms);
                }

                if(x>0.8){//right
                   // car.goStraight(20);
                    //ThisThread::sleep_for(300ms);
                    car.turn(20,0.6); //turn left
                    ThisThread::sleep_for(200ms);
                }
                if(x<0.8&&x>-0.8){
                    car.goStraight(20);
                    
                    while(1) {
                        if((float)ping1<10){
                            car.stop();
                            flag=false;
                            break;
                        }
                        ThisThread::sleep_for(200ms);
                    }

                }

            }

            
            
      }
   }
}

/*
   parallax_ping  ping1(pin12);
   while(1) {
      if((float)ping1>10) led1 = 1;
      else {
         led1 = 0;
         car.stop();
         break;
      }
      ThisThread::sleep_for(10ms);
   }
*/