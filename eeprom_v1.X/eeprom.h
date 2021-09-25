#ifndef EEPROM_H
#define EEPROM_H

#define NULL    0

char EEPROM_read( unsigned char addr );
void EEPROM_write( unsigned char addr, unsigned char data );
void write (char adrs, unsigned char *data);
void read ( char  adrs , unsigned char * eep ); 
void salvar_receita (char adrs,unsigned char *data );
void buscar_receita (char adrs,unsigned char *data );
void deletar_receita (char receita);
void receita_livre ( unsigned char * rec);
void formatar_receitas (void);

#endif

