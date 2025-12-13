#include <stdio.h>
#include <stdlib.h>

#include "arquivos.h"

FILE* abrirArquivoSomenteLeitura( const char* caminho )
{
  FILE* fp = fopen( caminho, "r" );

  if (!fp)
  {
    perror("Abertura arquivo falhou. ABORTANDO");
    exit(1);
  }

  return fp;
}

long obterTamanhoArquivo( FILE* fp )
{
  long tamanho = 0;

  fseek(fp, 0, SEEK_END); //ir para fim
  tamanho = ftell(fp);     //posição relativa do fim = tamanho
  fseek(fp, 0, SEEK_SET); //tornar ao inicio.

  return tamanho;
}

// depende de fp OK
char* alocarBufferNaMemoria( long tamanho, FILE* fp )
{
  char* buffer;
  buffer = malloc( sizeof(char) * tamanho );
  if ( !buffer )
  {
    perror("Buffer não alocou !");
    fclose( fp );
    exit(1);
  }
  return buffer;
}

void jogarArquivoParaSTDOUT( char* buffer, long tamanho )
{
  for ( int i=0; i<tamanho; i++ )
  {
    putchar( *(buffer + i) );
  }
}

/* //DEMONSTRAÇÃO
int main(int argc, char *argv[])
{
  FILE* fp = abrirArquivoSomenteLeitura( "./public/index.html" );
  long tamanho = obterTamanhoArquivo( fp );
  char* buffer = alocarBufferNaMemoria( tamanho, fp );

  fread( buffer, 1, tamanho, fp );
  jogarArquivoParaSTDOUT( buffer, tamanho );

  fclose(fp);
  free(buffer);
	exit(0);
}
*/

