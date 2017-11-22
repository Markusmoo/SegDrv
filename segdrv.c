/* 
 * File:   segdrv.h
 * Author: Markus Tonsaker
 *
 * Created on November 15, 2017, 8:52 AM
 */

#include "segdrv.h"
#include <P18F4620.h>
#include <ctype.h>

#define ZERO    0xc0
#define ONE     0xf9
#define TWO     0xa4
#define THREE   0xb0
#define FOUR    0x99
#define FIVE    0xd2
#define SIX     0x93
#define SEVEN   0xf8
#define EIGHT   0x80
#define NINE    0x98

#define VK_A    0xc8
#define VK_B    0x83
#define VK_C    0xcb
#define VK_D    0xa1
#define VK_E    0x86
#define VK_F    0x8e
#define VK_G    0xb0
#define VK_H    0x8b
#define VK_I    0xf9
#define VK_J    0xf1
#define VK_K    0x8a
#define VK_L    0xc7
#define VK_M    0xea
#define VK_N    0xab
#define VK_O    0xa3
#define VK_P    0xcc
#define VK_Q    0x84
#define VK_R    0xaf
#define VK_S    0xd2
#define VK_T    0x87
#define VK_U    0x41
#define VK_V    0xae
#define VK_W    0xd5
#define VK_X    0x89
#define VK_Y    0x91
#define VK_Z    0xb4

int usePortAB = 0;

/**
 * Turns on the port(s) specified and prepares the PIC processor to
 * interface with the 7 Segment Display
 * 
 * @param portAB 1 to use port A&B, 0 to use port C&D
 */
void setDisplayEnabled(int portAB){
    if(portAB){
        TRISA = 0x00;
        TRISB = 0x00;
    }else{
        TRISC = 0x00;
        TRISD = 0x00;
    }
    usePortAB = portAB;
}

int dispChar(int pos, char c){
    switch(pos){
        case 0: if(usePortAB) PORTA = 0b00000001; else PORTC = 0b00000001; break;
        case 1: if(usePortAB) PORTA = 0b00000010; else PORTC = 0b00000010; break;
        case 2: if(usePortAB) PORTA = 0b00000100; else PORTC = 0b00000100; break;
        case 3: if(usePortAB) PORTA = 0b00001000; else PORTC = 0b00001000; break;
        default: if(usePortAB) PORTA = 0; else PORTC = 0; break;
    }
    
    if(usePortAB){
        PORTB = insert(c);
    }else{
        PORTD = insert(c);
    }
}

int dispString(char segTxt[]){
    if(segTxt == NULL){         //If text is empty; returns.
        return 0;
    }
}

int insert(char c){
    if(c >= 'A' && c <= 'Z') c+= 'a'-'A'; //Converts uppercase to lowercase
    switch(c){
        case '0': return ZERO;
        case '1': return ONE;
        case '2': return TWO;
        case '3': return THREE;
        case '4': return FOUR;
        case '5': return FIVE;
        case '6': return SIX;
        case '7': return SEVEN;
        case '8': return EIGHT;
        case '9': return NINE;
        case 'a': return VK_A;
        case 'b': return VK_B;
        case 'c': return VK_C;
        case 'd': return VK_D;
        case 'e': return VK_E;
        case 'f': return VK_F;
        case 'g': return VK_G;
        case 'h': return VK_H;
        case 'i': return VK_I;
        case 'j': return VK_J;
        case 'k': return VK_K;
        case 'l': return VK_L;
        case 'm': return VK_M;
        case 'n': return VK_N;
        case 'o': return VK_O;
        case 'p': return VK_P;
        case 'q': return VK_Q;
        case 'r': return VK_R;
        case 's': return VK_S;
        case 't': return VK_T;
        case 'u': return VK_U;
        case 'v': return VK_V;
        case 'w': return VK_W;
        case 'x': return VK_X;
        case 'y': return VK_Y;
        case 'z': return VK_Z;
        default: return 0;
    }
}