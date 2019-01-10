// TICKER: A Ticker timer is used to interrupt the microprocessor
// at a recurring interval/time delay.
#include "mbed.h"
Ticker tictock;

DigitalOut led1(PG_13);   // GREEN LED
DigitalOut led2(PG_14);   // RED LED

void redLedToggle(){
  led2 = !led2;   
}

int main() {
  led2 = 1;

  // tictock.attach(&redLedToggle, 0.5);    // Interrupt every 0.5 second, and execute redLedToggle() function 
  tictock.attach_us(&redLedToggle, 50000);  // Interrupt every 50,000us = 50ms = 0.05sec
  
  // main loop, blink led1 continuously
  while(true){
    led1 = !led1;
    wait(0.25);
  }

}
