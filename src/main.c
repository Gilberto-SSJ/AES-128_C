#include "aes.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    uint8_t key[AES_KEY_SIZE] = {
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
        0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
    };
    uint8_t plaintext[AES_BLOCK_SIZE] = {
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,
        0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff
    };
    uint8_t expected_cipher[AES_BLOCK_SIZE] = {
        0x69,0xc4,0xe0,0xd8,0x6a,0x7b,0x04,0x30,
        0xd8,0xcd,0xb7,0x80,0x70,0xb4,0xc5,0x5a
    };

    uint8_t round_keys[(AES_ROUNDS+1)*AES_BLOCK_SIZE];
    aes_key_expansion(key, round_keys);

    uint8_t cipher[AES_BLOCK_SIZE];
    aes_encrypt_block(plaintext, cipher, round_keys);

    if (memcmp(cipher, expected_cipher, AES_BLOCK_SIZE) != 0) {
        printf("Encryption failed\n");
        return 1;
    }

    uint8_t decrypted[AES_BLOCK_SIZE];
    aes_decrypt_block(cipher, decrypted, round_keys);

    if (memcmp(decrypted, plaintext, AES_BLOCK_SIZE) != 0) {
        printf("Decryption failed\n");
        return 1;
    }

    printf("AES-128 test passed\n");
    return 0;
}
