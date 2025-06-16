#include "aes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int hex_to_bytes(const char *hex, uint8_t *out, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        char byte_str[3] = { hex[2*i], hex[2*i+1], '\0' };
        char *end;
        long val = strtol(byte_str, &end, 16);
        if (*end != '\0') return -1;
        out[i] = (uint8_t)val;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <plaintext_hex> <key_hex>\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) != 32 || strlen(argv[2]) != 32) {
        printf("Both plaintext and key must be 32 hex characters (16 bytes)\n");
        return 1;
    }

    uint8_t plaintext[AES_BLOCK_SIZE];
    uint8_t key[AES_KEY_SIZE];

    if (hex_to_bytes(argv[1], plaintext, AES_BLOCK_SIZE) != 0 ||
        hex_to_bytes(argv[2], key, AES_KEY_SIZE) != 0) {
        printf("Invalid hex input\n");
        return 1;
    }

    uint8_t round_keys[(AES_ROUNDS+1)*AES_BLOCK_SIZE];
    aes_key_expansion(key, round_keys);

    uint8_t cipher[AES_BLOCK_SIZE];
    aes_encrypt_block(plaintext, cipher, round_keys);

    for (int i = 0; i < AES_BLOCK_SIZE; ++i)
        printf("%02x", cipher[i]);
    printf("\n");

    return 0;
}
