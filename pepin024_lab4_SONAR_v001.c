#include <xc.h>
#include <p24Fxxxx.h>
#include "../pepin024_lab3_v001.X/pepin024_lab3_delay_v003.h"

void initPing(void){
    TRISBbits.TRISB8 = 0;
    TRISBbits.TRISB9 = 1;
    
    _IOLOCK = 0;
    RPINR7bits.IC1R = 9;
    _IOLOCK = 1;
    
    _ICTMR = 1;
    _ICM = 0x001;
    
    
    
    T2CON = 0;
    PR2 = 65535;
    T2CONbits.TCKPS = 0b01; //Set prescaler to 1:8
    return;        
}

unsigned int measRangeFinder(void){
    T2CONbits.TON = 0;
    _ICM = 0;
    
    while(_ICBNE == 1){
        int garbage = IC1BUF;
    }
    TMR2 = 0;
    T2CONbits.TON = 1;
    _ICM = 0x001;
    
    //tbd
    
    
}