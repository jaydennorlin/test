#include "mbed.h"

DigitalOut led0(LED1);
DigitalOut led1(LED2);
DigitalOut led2(LED3);
DigitalOut led3(LED4);

void SetLED(int input){
    //This is a brutish way to do it, but knowledge limitations prevent us from doing anything else currently.

    //First Bit
    if((input + 1) % 2 == 0){
        led0 = 1;
    }
    else{
        led0 = 0;
    }
    //Second Bit
    if(((input / 2) + 1) % 2 == 0){
        led1 = 1;
    }
    else{
        led1 = 0;
    }
    //Third Bit
    if(((input / 4) + 1) % 2 == 0){
        led2 = 1;
    }
    else{
        led2 = 0;
    }
    //4th Bit
    if(((input / 8) + 1) % 2 == 0){
        led3 = 1;
    }
    else{
       led3 = 0;
    }
}

int main() {
    //Task 1
    /*int x = 15;

    while(1) {
        SetLED(x);

        wait(0.2);
        x--;
        if(x < 0){
            x = 15;
        }
    }*/

    //Task 2
    int x = 0;
    int maxX = 0;

    while(1) {
        SetLED(x);

        wait(1);
        
        x++;
        if(x > maxX){
            x = 0;

            maxX = ((maxX + 1) * 2) - 1;
            if(maxX > 15){
                maxX = 0;
            }
        }
    }
}
