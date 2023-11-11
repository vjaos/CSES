CC=clang
CFLAGS=-Wall -pedantic -lstdc++ -std=c++17

run:
	$(CC) $(CFLAGS) $(FILE) -o pg && ./pg

