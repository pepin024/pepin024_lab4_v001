#include <xc.h>
#include <p24Fxxxx.h>
#include "../pepin024_lab3_v001.X/pepin024_lab3_delay_v003.h"

#define CONVERSIONFACTOR 11.6  // 11.6 = (58 * 2)/10 to convert from us

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
    _RB8 = 0;
    
    T2CONbits.TON = 0;
    _ICM = 0;
    
    while(_ICBNE == 1){
        int garbage = IC1BUF;  //useless as ICBNE is set to 0 when ICM is set to 0
    }
    TMR2 = 0;
    
    
    T1CON = 0; //set up timer for ~100 us pulse
    TMR1 = 0;
    PR1 = 200;
    _T1IF = 0;
    
    
    T2CONbits.TON = 1;
    _ICM = 0x001;
    
    _RB8 = 1;
    T1CON = 0x8000;
    
    while(!_T1IF);
    _RB8 = 0;
    
    delay (100);
    
    unsigned int firstEdge, 
        secondEdge;
    
    firstEdge = IC1BUF;
    secondEdge = IC1BUF;
    
    unsigned int result = secondEdge - firstEdge;
    
    
    result = ((result*0.0089)-2.2967)*10;
    return result;
    
    
}