/* Tratador de URL
 * Adaptando libcurl
 * */

#include <stdio.h>
#include <stdlib.h>

#include <curl/curl.h>
#include <curl/urlapi.h>

#include "roteador.h"

/* análise detalhada da url */
URL_t* avaliarURL( const char* url )
{
  CURLU* curl = curl_url();
  URL_t* u = malloc( sizeof(URL_t) ); //client code defined.

  curl_url_set( curl, CURLUPART_URL, url, 0);

  curl_url_get( curl, CURLUPART_HOST,  &u->host,  0 );
  curl_url_get( curl, CURLUPART_PORT,  &u->porta, 0 );
  curl_url_get( curl, CURLUPART_PATH,  &u->path,  0 );
  curl_url_get( curl, CURLUPART_QUERY, &u->query, 0 );

  return u;
}


