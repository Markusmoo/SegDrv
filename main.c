/* 
 * File:   main.c
 * Author: 300145948
 *
 * Created on November 15, 2017, 9:14 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <P18F4620.h>
#include <delays.h>
#include "segdrv.h"

/*
 * 
 */
void main(){
    setDisplayEnabled(0);
    dispChar(1,'O');
    //printf("NEW2 PORT %b %b %b\n",PORTD,TRISC,PORTC);
    
    TRISD = 0;
    TRISC = 0;
    PORTC = 1;
    //PORTD = 0b10101010;
    printf("NEW2 PORT %b %b %b\n",PORTD,TRISC,PORTC);
    while(1) Nop();
}

