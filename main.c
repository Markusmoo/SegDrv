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
    dispChar(3,'r');
    //PORTD = 0b10101010;
    //dispChar(1,'h');
    printf("NEW2 PORT %b %b %b\n",PORTD,TRISC,PORTC);
    while(1) Nop();
}

