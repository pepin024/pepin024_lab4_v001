#include <p24Fxxxx.h>
#include <xc.h>

void initServo(void){
    _IOLOCK = 0;
    RPOR3bits.RP6R = 18;
    _IOLOCK = 1;
    return;
}

void setServo(int val){
    OC1RS = val;
    return;
}