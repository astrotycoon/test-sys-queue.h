CC=gcc
CFLAGS+=-D_DEBUG
#CFLAGS+=
RM=rm -rf

all: 
	$(CC) $(CFLAGS) ddlist.c -o ddlist  
	$(CC) $(CFLAGS) dlist.c -o dlist  
	$(CC) $(CFLAGS) simpleq.c -o simpleq  
	$(CC) $(CFLAGS) slist.c -o slist  
	$(CC) $(CFLAGS) sslist.c -o sslist  
	$(CC) $(CFLAGS) stqueue.c -o stqueue 
	$(CC) $(CFLAGS) tqueue.c -o tqueue 
	$(CC) $(CFLAGS) tailq.c -o tailq

clean:
	$(RM) ddlist dlist simpleq slist sslist stqueue tqueue tailq

