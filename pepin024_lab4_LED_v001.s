


.equ __P24FJ64GA002,1 ;required "boiler-plate" (BP)
.include "p24Fxxxx.inc" ;BP
#include "xc.inc" ;BP

.text ;BP (put the following data in ROM(program memory))
   
.global _writeLowBit, _writeHighBit, _wait_50_us,
    
_writeHighBit:		; 2 cycles low
    BSET LATA, #0		; 1 cycles low
    REPEAT #8		; 1 cycle  high
    NOP			; 9 cycles high
    BCLR LATA, #0		; 1 cycle  high	    11 high cycles total
    NOP			; 1 cycle  low
    NOP			; 1 cycle  low
    NOP			; 1 cycle  low
    RETURN		; 3 cycles low	    9 low cycles total	20 cycles total


_writeLowBit:		; 2 cycles low
    BSET LATA, #0		; 1 cycle  low
    REPEAT #3		; 1 cycle  high
    NOP			; 4 cycles high
    BCLR LATA, #0		; 1 cycle  high	    6 high cycles total
    REPEAT #6		; 1 cycle  low
    NOP			; 7 cycles low
    RETURN		; 3 cycles low	    14 low cycles total	  20 cycles total
    
_wait_50_us:
    REPEAT #793
    NOP
    RETURN
    

    
    .end