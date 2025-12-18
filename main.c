/* LPLA-br © BSD 3-clause
 * Servidor http performático em C */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <sys/types.h>
#include <sys/select.h> //fd_set (-lc)
#include <sys/socket.h> //socklen

#include <microhttpd.h>

#include "arquivos.h"
#include "roteador.h"

#define PORT 8080

// função callback de resposta.
enum MHD_Result responder_conexao(
      void* cls,
      struct MHD_Connection* conexao,
      const char* url_path,
      const char* metodo, const char* versao,
      const char* uploadData,
      long unsigned int* uploadDataSize, void** req_cls
    )
{
  char* caminho = malloc( sizeof(char) * (strlen(url_path)+1) );
  sprintf( caminho, "%s%s", ".", url_path );

  FILE* fp = fopen( caminho, "r" );
  free(caminho);
  fp = emitirNaoEncontrado( fp );

  long tam = obterTamanhoArquivo( fp );
  char* pagina = malloc( sizeof(char) * tam );

  struct MHD_Response* resposta;
  int ret;

  printf( "%s %s %s\n", url_path, metodo, versao );

  fread( pagina, 1, tam, fp );
  fclose(fp);

  resposta = MHD_create_response_from_buffer( tam, (void*) pagina, MHD_RESPMEM_PERSISTENT );
  ret = MHD_queue_response( conexao, MHD_HTTP_OK, resposta );
  return ret;
}

int main(int argc, char *argv[])
{
  struct MHD_Daemon *daemon;

	printf("SERVIDOR libmicrohttpd \n");

  daemon = MHD_start_daemon(
      MHD_USE_INTERNAL_POLLING_THREAD,
      PORT,
      NULL,
      NULL,
      &responder_conexao,
      NULL,
      MHD_OPTION_END
  );

  if ( NULL == daemon )
  {
    perror("daemon falhou ao subir pois retornou NULO");
    exit(1);
  }

  printf( "pressione ENTER para encerrar o servidor.\n>" );
  getchar();
  MHD_stop_daemon( daemon );
	exit(0);
}
