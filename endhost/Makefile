CC=gcc
CFLAGS +=-Wall -g
LIBDIR=../lib/libscion
ZLOGDIR=$(HOME)/.local/lib/zlog/src
INC += -I./ssp -I../lib/libscion -I$(ZLOGDIR)
LDFLAGS += -Wl,-Bstatic -L$(LIBDIR) -lscion -L$(ZLOGDIR) -lzlog -Wl,-Bdynamic -lpthread
LIBHSRC=$(LIBDIR)/*.c $(LIBDIR)/*.h
SRCS=dispatcher.c

HDRS=$(wildcard *.h)

all: dispatcher

dispatcher: dispatcher.c $(LIBHSRC)
	$(MAKE) -C $(LIBDIR)
	$(CC) $(CFLAGS) $(INC) $(SRCS) -o $@ $(LDFLAGS)

install:
	cp dispatcher ../bin

clean:
	-rm -f dispatcher
