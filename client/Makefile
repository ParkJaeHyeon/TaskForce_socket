all:	client

client:	client.o
	gcc -o client client.o
client.o:
	gcc -c -o client.o socket.c

clean:
	rm -f client
	rm -r *.o

