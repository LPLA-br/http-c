# SERVIDOR HTTP EM C

testando biblioteca gnu libmicrohttpd que
permite criar um servidor http em C.

Útil para situações onde o servidor deve
ser performático, procedimental e simples.

para detalhes leia o header:
- /usr/include/microhttpd.h

# Backend em C ? Sim é o que estás a pensar !

```
EVENTOS E ASSINCRONISMO
    libevent
    libuv
    libev

PROTOCOLO CAMADA 7 HTTP
    libmicrohttp
    mongoose
        suporta Websockets,
        http e https.
        Possui TLS embutido
    civetweb
        fork do mongoose

HTTP PARSING (baixo nível)
    llhttp
    http-parser
        usado pelo Node.js legacy

PROTOCOLOS E DADOS
    libcurl (cliente de rede)
        HTTP[S], [S]FTP, SMTP, POP3
        TELNET, GOPHER, FILE (arquivos locais)
        ...

JSON
    jansson
        JSON parsing/encoding
    cJSON
        pequenos payloads json
    protobuf-c
        Protocol Buffers para C
        Tipagem forte e eficiente.

BANCO DE DADOS
    libpq (postgres)
    SQlite3
    MySQL Connector
    
    NOSQL---------
    hiredis (Redis)
    libmemcached
    --------------

TLS E CRIPTOGRAFIA
    openssl
    libressl
    mbedtsl (solução leve)

AUTENTICAÇÃO E SEGURANÇA
    libsodium (criptografia moderna)
    JWT-C
    liboauth2

CONCORRÊNCIA E PARALELISMO
    pthreads <pthread.h>
    OpenMP
    spdlog

LOGGIN UNIX E LINUX
    zlog
    syslog (rsyslog, syslog-ng)

```

# CARACTERISTICAS DO BACKEND C

0. servidor pobre de recursos.
1. baixa tolerância a latências.
2. controle total sobre memória do servidor.
3. máxima integração com o sistema operacional.
4. trabalho de infraestrutura (proxy,gateway,broker).


