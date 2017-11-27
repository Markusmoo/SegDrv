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

//char str[] = {'c','h','a','r'};
char ch[] = {'c','o','d','y'};
/*
 * 
 */
void main(){
    setDisplayEnabled(0);
    while(1){
        /*while(ch <= 'z'){
            dispChar(0,ch++);
            Delay10KTCYx(11);
        }
        ch = 'a';*/
        dispString(4,ch);
    }
    while(1) Nop();
    //while(1) dispString(4, str);
}

