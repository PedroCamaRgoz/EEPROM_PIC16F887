/*
 * File:   main.c
 * Author: 20187263
 * 
 * Created on 22 de Setembro de 2021, 13:29
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "estante_funcoes.h"
 

void main(void) 
{
    
    lcd.init();
    receita.salvar(1,linha0);
    receita.buscar(1,linha0);
    lcd.print(linha0);
    receita.livre(linha1);
    lcd.printpos(1,0,linha1);
 
    while(1);
}
