#ifndef _SPECK_H
#define _SPECK_H

#include "../common/utils.h"

/**
* Generate round keys from given key
* @param K cipher key
* @param rk output array for round keys
*/
void SpeckKeySchedule(u64 K[], u64 rk[]);

/**
* Encrypts a block of plaintext given an array of round key words
* @param Pt plaintext blocks
* @param Ct output array for cipher blocks
* @param rk roundkeys
*/
void SpeckEncrypt(u64 Pt[], u64 Ct[], u64 rk[]);

/**
 * Decrypt a block of cipher text given an array of round key and words
 * @param Pt output array of plaintext
 * @param Ct cipher block
 * @param rk roundkeys
 */
void SpeckDecrypt(u64 Pt[], u64 Ct[], u64 rk[]);

#endif