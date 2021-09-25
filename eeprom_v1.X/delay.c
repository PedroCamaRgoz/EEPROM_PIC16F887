/*
 * File:   delay.c
 * Author: josewrpereira
 *
 * Created on 28 de Maio de 2021, 08:57
 */


#include <xc.h>
#include "delay.h"

void delay( unsigned int t )
{
    while( t )
    {
        __delay_ms(1);
        --t;
    }
}
