#ifndef _UTIL_H // must be unique name in the project
#define _UTIL_H

#include <Arduino.h>
#include <AESLib.h>

#define BLOCK_LEN 16
#define SOFT_SERIAL_BAUDRATE 9600
#define DEBUG


void _xor(const uint8_t *a, const uint8_t *b, const uint16_t len, uint8_t *res);
void gen_random_block(uint8_t *a);
bool validate(uint8_t *a, uint8_t *b, uint16_t len);

void decrypt(char *msg, const uint8_t *key, const uint8_t *iv, char *res);
void encrypt(char *msg, const uint8_t *key, const uint8_t *iv, char *res);

void write_msg(uint8_t *msg);
void read_msg(char *res);

void print_uint8_arr(uint8_t* arr);

#endif 