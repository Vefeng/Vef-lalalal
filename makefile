CC=gcc
CFLAGS=-c -g -Wall
OBJS=1.o 2.o
test:$(OBJS)
	$(CC) $^ -o $@
%.o:%.c 
	$(CC) $(CFLAGS) $< -o $@ 

.PHONY:clean
clean:
	$(RM) *.o test
