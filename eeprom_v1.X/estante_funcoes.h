#ifndef ESTANTE_FUNCOES
#define ESTANTE_FUNCOES

#include "lcd.h"
#include "eeprom.h"

extern char linha0[16]="TESTE - TESTE - ";
extern char linha1[16]="                ";

//                                            LCD
 struct
{
    void (* init)(void);
    void (* print)( const char * str );
    void (* printpos)( unsigned char lin, unsigned char col, const char * str );
    void (* printv)(  unsigned char lin, unsigned char col, int num, unsigned char tam );
    void (* clr)( void );
    unsigned char (* B0)( void );
    unsigned char (* B1)( void );
} lcd = { dispLCD_init, dispLCDstr, dispLCD, dispLCD_num, dispLCD_clr, dispLCD_B0, dispLCD_B1 };

//                                           EEPROM
 struct
{
    void  (* salvar) (char adrs,unsigned char *data );
    void  (* buscar) (char adrs,unsigned char *data );
    void  (* deletar) (char receita);
    void  (* livre) (unsigned char * rec);
    void  (* formatar) (void);
} receita = { salvar_receita, buscar_receita, deletar_receita, receita_livre, formatar_receitas };


#endif
