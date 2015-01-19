CC=gcc
CFLAGS+=-D_DEBUG
#CFLAGS+=
RM=rm -rf

all: 
	$(CC) $(CFLAGS) slist.c -o slist  
	$(CC) $(CFLAGS) sslist.c -o sslist  
	$(CC) $(CFLAGS) dlist.c -o dlist  
	$(CC) $(CFLAGS) tqueue.c -o tqueue 

clean:
	$(RM) slist sslist dlist tqueue

