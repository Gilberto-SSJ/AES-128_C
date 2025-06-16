# AES-128 in C

This repository provides a minimal implementation of the AES-128 algorithm following the NIST FIPS 197 specification. The implementation includes key expansion, block encryption and decryption, and a simple test using the known NIST test vector.

## Building

Use `make` to build the test programs:

```sh
make
```

## Running the test

After building, run `./aes_test`. The program encrypts and decrypts the NIST example vector and prints `AES-128 test passed` when the output matches the expected ciphertext and plaintext.

You can also encrypt a custom 16-byte block using `teste_da_cifra`:

```sh
./teste_da_cifra <plaintext_hex> <key_hex>
```

Both parameters must be provided as 32 hexadecimal characters each. The program prints the resulting ciphertext in hexadecimal form.
