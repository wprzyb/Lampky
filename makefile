CC= gcc
CFLAGS = 
OBJS = draw.o brakujace.o main.o tablice.o files.o matrix.o
lights_out:$(OBJS)
	$(CC) $(CFLAGS) -o lights_out main.o draw.o brakujace.o tablice.o files.o matrix.o
main.o:main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
draw.o:draw.c
	$(CC) $(CFLAGS) -c draw.c -o draw.o
brakujace.o:brakujace.c
	$(CC) $(CFLAGS) -c brakujace.c -o brakujace.o
tablice.o:tablice.c
	$(CC) $(CFLAGS) -c tablice.c -o tablice.o
files.o:files.c
	$(CC) $(CFLAGS) -c files.c -o files.o
matrix.o:matrix.c
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o
clean:
	rm -rf *.o lights_out
