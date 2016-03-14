.PHONY: all clean dispatcher install

CC=gcc
CFLAGS +=-Wall -g
LIB_DIR=lib/libscion
DISPATCHER_DIR=endhost
DISPATCHER=$(DISPATCHER_DIR)/dispatcher
SOCKET_DIR=endhost/ssp

all:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(DISPATCHER_DIR)
	$(MAKE) -C $(SOCKET_DIR)

dispatcher:
	$(MAKE) -C $(DISPATCHER_DIR)

install:
	cp $(DISPATCHER) bin/

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(DISPATCHER_DIR)
	$(MAKE) clean -C $(SOCKET_DIR)
	rm -f bin/dispatcher
