/** LPLA-br c BSD-3clause
 * Possui funções para análise
 * e direcionamento.
 * */

#ifndef ROTEADOR_H_INCLUDED
#define ROTEADOR_H_INCLUDED

typedef struct
{
  char* host;
  char* porta;
  char* path;
  char* query;
} URL_t;

URL_t* avaliarURL( const char* url );

#endif
