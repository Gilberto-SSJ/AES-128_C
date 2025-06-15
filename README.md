# AES-128 in C

This repository provides a minimal implementation of the AES-128 algorithm following the NIST FIPS 197 specification. The implementation includes key expansion, block encryption and decryption, and a simple test using the known NIST test vector.

## Building

Use `make` to build the test program:

```sh
make
```

## Running the test

After building, run `./aes_test`. The program encrypts and decrypts the NIST example vector and prints `AES-128 test passed` when the output matches the expected ciphertext and plaintext.
