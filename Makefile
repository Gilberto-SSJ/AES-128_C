CC=gcc
CFLAGS=-Wall -Wextra -std=c11
AES_SRC=src/aes.c

all: aes_test teste_da_cifra

aes_test: $(AES_SRC) src/main.c
	$(CC) $(CFLAGS) -o aes_test $(AES_SRC) src/main.c

teste_da_cifra: $(AES_SRC) src/teste_da_cifra.c
	$(CC) $(CFLAGS) -o teste_da_cifra $(AES_SRC) src/teste_da_cifra.c

clean:
	rm -f aes_test teste_da_cifra
