#include "mbed.h"
#include "stdlib.h"
#include "bbcar.h"
#include "bbcar_rpc.h"


Ticker servo_ticker;
PwmOut pin5(D10), pin6(D11);
BBCar car(pin5, pin6, servo_ticker);
BufferedSerial pc(USBTX,USBRX); //tx,rx
BufferedSerial uart(D1,D0); //tx,rx


int main(){
   char buf[10];
   uart.set_baud(9600);
   int i=0;
   float angle=0;

   car.goStraight(20);

   while(1){
      if(uart.readable()){
            char recv[1];
            uart.read(recv, sizeof(recv));
            buf[i++]=recv[0];

            if(recv[0] == '\n'){
                angle = atof(buf);
                i=0;
                //printf("%f\n",angle);
                
                double shift=angle-180; 
                
                if(shift>2){
                    car.turn(20+(shift/2),-0.3);
                    ThisThread::sleep_for(200ms);
                }
                
                else if(shift<-2){
                    car.turn(20-(shift/2),0.3);
                    ThisThread::sleep_for(200ms);
                }
                else {
                    car.goStraight(20);
                    ThisThread::sleep_for(200ms);

                }


            }

            //pc.write(recv, sizeof(recv));
            
      }
   }
}