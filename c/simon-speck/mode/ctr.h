#ifndef _CTR_MODE_H
#define _CTR_MODE_H

#include "../common/common.h"

/**
* Encryption in CTR mode
* @param cypher Algorithm
* @param nononce No random nonce
* @param plaintext Plaintext to be encrypted
* @param length Length of data bytes to be encrypted
* @param rk Round key
* @return The number of pad
 */
void ctrEncrypt64(cypher64 cypher, u8 *nonce, u8 *plaintext, u8 length, u32 *rk);

/**
* Decryption in CTR mode
* @param cypher Algorithm
* @param nononce No random nonce
* @param ciphertext Ciphertext to be decrypted
* @param length Length of data bytes to be decrypted
* @param rk Round key
* @return The size of plaintext without pad
 */
void ctrDecrypt64(cypher64 cypher, u8 *nonce, u8 *ciphertext, u8 length, u32 *rk);

/**
* Encryption in CTR mode
* @param cypher Algorithm
* @param nononce No random nonce
* @param plaintext Plaintext to be encrypted
* @param length Length of data bytes to be encrypted
* @param rk Round key
* @return The number of pad
 */
void ctrEncrypt128(cypher128 cypher, u8 *nonce, u8 *plaintext, u8 length, u64 *rk);

/**
* Decryption in CTR mode
* @param cypher Algorithm
* @param nononce No random nonce
* @param ciphertext Ciphertext to be decrypted
* @param length Length of data bytes to be decrypted
* @param rk Round key
* @return The size of plaintext without pad
 */
void ctrDecrypt128(cypher128 cypher, u8 *nonce, u8 *ciphertext, u8 length, u64 *rk);

#endif