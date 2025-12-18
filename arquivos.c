#include <stdio.h>
#include <stdlib.h>

#include "arquivos.h"

//------------------------------------------

/** garante arquivo para entrega. */
FILE* emitirNaoEncontrado( FILE* fp )
{
  if ( !fp )
  {
    fp = fopen( "./public/notfound.html", "r");
    if ( !fp )
    {
      perror("emitirNaoEncontrado() notfound.html não encontrado !\n");
      exit(1);
    }
  }
  return fp;
}

//------------------------------------------

long obterTamanhoArquivo( FILE* fp )
{
  long tamanho = 0;

  fseek(fp, 0, SEEK_END); //ir para fim
  tamanho = ftell(fp);     //posição relativa do fim = tamanho
  fseek(fp, 0, SEEK_SET); //tornar ao inicio.

  return tamanho;
}

void jogarArquivoParaSTDOUT( char* buffer, long tamanho )
{
  for ( int i=0; i<tamanho; i++ )
  {
    putchar( *(buffer + i) );
  }
}


