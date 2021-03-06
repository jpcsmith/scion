.PHONY: wrapper

CC = gcc
PP = g++
CFLAGS += -g
PFLAGS += $(CFLAGS) -std=c++11
LIB = -L..
INC = -I.. -I../../../lib/libscion
HDRS=$(wildcard ../*.h)
BINARIES = client server hash_client hash_server web_client web_server wrapper_client wrapper_server

all: $(BINARIES)

client: client.cpp $(HDRS)
	$(PP) -o client $(INC) $(LIB) $(PFLAGS) client.cpp -lssocket -Wl,-rpath,..

server: server.cpp $(HDRS)
	$(PP) -o server $(INC) $(LIB) $(PFLAGS) server.cpp -lssocket -Wl,-rpath,..

hash_client: hash_client.cpp $(HDRS)
	$(PP) -o hash_client $(INC) $(LIB) $(PFLAGS) hash_client.cpp SHA1.cpp -lssocket -Wl,-rpath,..

hash_server: hash_server.cpp $(HDRS)
	$(PP) -o hash_server $(INC) $(LIB) $(PFLAGS) hash_server.cpp SHA1.cpp -lssocket -Wl,-rpath,..

web_client: web_client.cpp $(HDRS)
	$(PP) -o web_client $(INC) $(LIB) $(PFLAGS) web_client.cpp -lssocket -lcurl -Wl,-rpath,..

web_server: web_server.cpp $(HDRS)
	$(PP) -o web_server $(INC) $(LIB) $(PFLAGS) web_server.cpp -lssocket -lcurl -Wl,-rpath,..

wrapper: wrapper_client wrapper_server

wrapper_client: wrapper_client.c $(HDRS)
	$(CC) $(INC) $(CFLAGS) -c wrapper_client.c
	$(PP) $(LIB) -o wrapper_client wrapper_client.o -lssocket -Wl,-rpath,..

wrapper_server: wrapper_server.c $(HDRS)
	$(CC) $(INC) $(CFLAGS) -c wrapper_server.c
	$(PP) $(LIB) -o wrapper_server wrapper_server.o -lssocket -Wl,-rpath,..

clean:
	rm -rf $(BINARIES) $(WRAPPED) *.o
