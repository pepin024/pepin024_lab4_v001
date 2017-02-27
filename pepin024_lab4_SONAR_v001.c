#include <xc.h>
#include <p24Fxxxx.h>

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
