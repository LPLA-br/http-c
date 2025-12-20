main:
	cc main.c arquivos.c -o main -I /usr/include -L /usr/lib -lmicrohttpd
clean:
	rm ./main
