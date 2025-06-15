CC=gcc
CFLAGS=-Wall -Wextra -std=c11
SRC=src/aes.c src/main.c

all: aes_test

aes_test: $(SRC)
	$(CC) $(CFLAGS) -o aes_test $(SRC)

clean:
	rm -f aes_test
