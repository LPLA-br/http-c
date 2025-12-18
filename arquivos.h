/** LPLA-br c BSD-3clause
 * Possui funções que abstraem operações
 * compostas de stdout.h
 * */

#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//handling
FILE* emitirNaoEncontrado( FILE* fp );
//func
long obterTamanhoArquivo( FILE* fp );
void jogarArquivoParaSTDOUT( char* buffer, long tamanho );

#endif
