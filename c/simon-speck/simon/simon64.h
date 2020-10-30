#ifndef _SIMON_H
#define _SIMON_H

#include "../common/utils.h"

/**
* Generate round keys from given key
* @param K cipher key
* @param rk output array for round keys
*/
void SimonKeySchedule(u32 K[], u32 rk[]);

/**
* Encrypts a block of plaintext given an array of round key words
* @param Pt plaintext blocks
* @param Ct output array for cipher blocks
* @param rk roundkeys
*/
void SimonEncrypt(u32 Pt[], u32 Ct[], u32 rk[]);

/**
 * Decrypt a block of cipher text given an array of round key and words
 * @param Pt output array of plaintext
 * @param Ct cipher block
 * @param rk roundkeys
 */
void SimonDecrypt(u32 Pt[], u32 Ct[], u32 rk[]);

#endif