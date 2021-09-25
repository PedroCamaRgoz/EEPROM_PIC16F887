/*
 * File:   eeprom.c
 * Author: curtaeletronica
 *
 * Created on 10 de Janeiro de 2020, 16:34
 * Vers�o de biblioteca : eeprom 1
 */

#include <xc.h>
#include "eeprom.h"
#include "delay.h"


char EEPROM_read( unsigned char addr )
{
    EEADRH = 0;           // habilita EEDAT
    EEADR = addr;         // endere�o 
    EECON1bits.EEPGD = 0;      // acessa memoria de dado
    EECON1bits.RD = 1;         // inicia leitura de memoria
    return( EEDAT );           // retorna 
  
}

void EEPROM_write( unsigned char addr, unsigned char data )
{
    INTCONbits.GIE = 0;
    EEADR = addr;               // endere�o 
    EEDAT = data;               // dados
    EECON1bits.EEPGD = 0;       // acessa memoria de dado
    EECON1bits.WREN = 1;        // habilita grava��o
    EECON2 = 0x55;              // 
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    
    while( EECON1bits.WR );  // enquanto ciclo de grava��o 
    
    EECON1bits.WREN = 0; // desabilita grava��o
    INTCONbits.GIE = 1; // desabilita todas as interrup��es 
}

int end_receita (int x)
{
    return(x*16);                            // retorna o endere�o da primeira posi��o das receitas 0 a 16
}

void salvar_receita (char adrs, unsigned char *data )
{
    int  aux;
    aux = end_receita(adrs);
    for( char i=0 ; i<16; i++)
         EEPROM_write( (aux+i), *(data+i) );  // aux + i nos d� a posi��o da primeira coluna de cada receita, 
                                              // *data + i nos d� as posi��es do  endere�o da vetor atrelado ao ponteiro *data 
}

void buscar_receita (char adrs, unsigned char * data )  // adrs = busca receitas 0 a 16, * data = recebe receita buscada e aponta para o vetor
{
    int aux;
    aux = end_receita(adrs);
    for( char i=0; i<16; i++ )
       *(data+i) = EEPROM_read(aux+i);       // *data+i recebe o endere�o de eeprom nas posi��es aux+i 
}

void deletar_receita (char receita)
{
   int  aux;
   aux = end_receita(receita);
   for( char i=0 ; i<16; i++)
        EEPROM_write((aux+i),NULL);        //
}

void receita_livre ( unsigned char * rec)
{
   int aux;
   for(int i=0;i<16;i++)
   {
       aux = end_receita(i);
       if(EEPROM_read(aux) == NULL)            // testa se a primeira posi��o de cada receita � igual a 0
          if(i<10)                             // separa os caracteres '0' a '9' dos caracteres 'A' a 'F' 
              *(rec + i) = '0'+i;              // '0' + i retorna as strings numericas de '0' a '9'    
          else                                 // separa os caracteres 'A' a 'F' dos '0' a '9'
              *(rec + i) = 'A'-10+i;           // 'A'-10 + i retorna a string alfabetica de 'A' a 'F'
   }
             
}

void formatar_receitas (void)
{
    for( char i = 0;i<256;i++)                 // Faz toda memoria eeprom igual a 0
           EEPROM_write(i,NULL);
        
}

