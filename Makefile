CC=i686-pc-linux-gnu-gcc
CFLAGS= -Wall -ansi -pedantic -fdump-rtl-expand -fdump-tree-cfg -fdump-tree-ssa
LDFLAGS=
EXEC=dijkstra 
SRC= $(wildcard *.c)  
OBJ= $(SRC:.c=.o)


all: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)
	rm $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~ $(EXEC)


