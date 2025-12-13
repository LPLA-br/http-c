/** LPLA-br c BSD-3clause
 * Adaptando/Abstraindo chamadas de baixo nível
 * do stdlib para servidor http.
 * */

#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

FILE* abrirArquivoSomenteLeitura( const char* caminho );
long obterTamanhoArquivo( FILE* fp );
char* alocarBufferNaMemoria( long tamanho, FILE* fp );
void jogarArquivoParaSTDOUT( char* buffer, long tamanho );

#endif
