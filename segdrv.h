/* 
 * File:   segdrv.h
 * Author: Markus Tonsaker
 *
 * Created on November 15, 2017, 8:52 AM
 */

#include <stdio.h>
#include <P18F4620.h>

#ifndef SEGDRV_H
#define	SEGDRV_H

extern int usePortAB;

void setDisplayEnabled(int);
int dispChar(int,char);
int dispString(int,char[]);
int insert(char);

/*
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
*/

#endif	/* SEGDRV_H */

