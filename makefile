main:
	cc main.c arquivos.c roteador.c -o main -I /usr/include -L /usr/lib -lmicrohttpd -I/usr/include -lcurl
clean:
	rm ./main
