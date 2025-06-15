#ifndef AES_H
#define AES_H

#include <stdint.h>

#define AES_BLOCK_SIZE 16
#define AES_KEY_SIZE 16
#define AES_ROUNDS 10

void aes_key_expansion(const uint8_t *key, uint8_t round_keys[(AES_ROUNDS+1)*AES_BLOCK_SIZE]);
void aes_encrypt_block(const uint8_t *input, uint8_t *output, const uint8_t round_keys[(AES_ROUNDS+1)*AES_BLOCK_SIZE]);
void aes_decrypt_block(const uint8_t *input, uint8_t *output, const uint8_t round_keys[(AES_ROUNDS+1)*AES_BLOCK_SIZE]);

#endif // AES_H
