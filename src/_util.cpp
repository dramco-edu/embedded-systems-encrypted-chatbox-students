#include "_util.h"

/**
 * XOR two uint8_t arrays
 *
 * @param a pointer to an uint8_t array to be xor'ed with another array 
 * @param b pointer to an uint8_t array to be xor'ed with another array 
 * @param len length of arrays a and b, length of a and b must be equal
 * @param res pointer to the result buffer, which will be filled with a xor b
 * @return void
 */
void _xor(const uint8_t *a, const uint8_t *b, const uint16_t len, uint8_t *res)
{
  for (uint8_t i = 0; i < len; i++)
  {
    res[i] = a[i] ^ b[i];
  }
}

/**
 * Fill an uint8_t array with random numbers between 0 and 255
 * Note: length of array to be filled is supposed to be 16 bytes
 *
 * @param a pointer to an uint8_t array to be filled with random numbers
 * @return void
 */
void gen_random_block(uint8_t *a)
{
  for (uint8_t i = 0; i < BLOCK_LEN; i++)
  {
    a[i] = random(0, 256);
  }
}

/**
 * Validate whether two uint8_t arrays contain the same numbers
 *
 * @param a pointer to an uint8_t array to be compared with another array
 * @param b pointer to an uint8_t array to be compared with another array
 * @param len length of the arrays a and b, length of a and b must be equal
 * @return void
 */
bool validate(uint8_t *a, uint8_t *b, uint16_t len)
{
#ifdef DEBUG
  Serial.print("Comparing: ");
  print_uint8_arr(a);
  Serial.print(" to: ");
  print_uint8_arr(b);
#endif

  for (uint8_t i = 0; i < len; i++)
  {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

/**
 * Decrypt an encrypted message using an encryption key
 * Note: length of array to be decrypted is supposed to be 16 bytes
 *
 * @param msg pointer to a char array containing the message to be decrypted
 * @param key key used for decryption 
 * @param iv initialization vector used for decryption
 * @param res pointer to the char buffer to be filled with the decrypted message
 * @return void
 */
void decrypt(char *msg, const uint8_t *key, const uint8_t *iv, char *res)
{
  aes128_cbc_dec(key, iv, msg, BLOCK_LEN);
  strncpy(res, msg, BLOCK_LEN);
}

/**
 * Encrypt a plain text message using an encryption key
 * Note: length of array to be encrypted is supposed to be 16 bytes
 *
 * @param msg pointer to a char array containing the message to be encrypted
 * @param key key used for encryption 
 * @param iv initialization vector used for encryption
 * @param res pointer to the char buffer to be filled with the encryption message
 * @return void
 */
void encrypt(char *msg, const uint8_t *key, const uint8_t *iv, char *res)
{
  aes128_cbc_enc(key, iv, msg, BLOCK_LEN);
  strncpy(res, msg, BLOCK_LEN);
}
