CC=clang
CFLAGS=-lstdc++ -std=c++17 -Wall -pedantic -W

run:
	$(CC) $(CFLAGS) $(FILE) -o ./bin/pg && ./bin/pg

