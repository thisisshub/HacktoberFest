#ifndef _UTILS_H
#define _UTILS_H

#include "common.h"
#include <stdint.h>
#include <stdio.h>

/**
* Convert  give words in bytes
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes

*  @param words  the input word
*  @param bytes  the output bytes
*  @param numwords  the lenght of word
*/
void Words32ToBytes(u32 words[], u8 bytes[], int numwords)
{
    int i, j = 0;
    for (i = 0; i < numwords; i++)
    {
        bytes[j] = (u8)words[i];
        bytes[j + 1] = (u8)(words[i] >> 8);
        bytes[j + 2] = (u8)(words[i] >> 16);
        bytes[j + 3] = (u8)(words[i] >> 24);
        j += 4;
    }
}

/**
* Convert  give the bytes in words
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes

*  @param bytes  the input bytes
*  @param word  the output word
*  @param numbytes  the lenght of bytes
*/
void BytesToWords32(u8 bytes[], u32 words[], int numbytes)
{
    int i, j = 0;
    for (i = 0; i < numbytes / 4; i++)
    {
        words[i] = (u32)bytes[j] | ((u32)bytes[j + 1] << 8) | ((u32)bytes[j + 2] << 16) | ((u32)bytes[j + 3] << 24);
        j += 4;
    }
}

/**
* Convert  give words in bytes
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes
*  @param bytes  the input bytes
*  @param word  the output word
*  @param numbytes  the lenght of bytes
*/
void Words64ToBytes(u64 words[], u8 bytes[], int numwords)
{
    int i, j = 0;
    for (i = 0; i < numwords; i++)
    {
        bytes[j] = (u8)words[i];
        bytes[j + 1] = (u8)(words[i] >> 8);
        bytes[j + 2] = (u8)(words[i] >> 16);
        bytes[j + 3] = (u8)(words[i] >> 24);
        bytes[j + 4] = (u8)(words[i] >> 32);
        bytes[j + 5] = (u8)(words[i] >> 40);
        bytes[j + 6] = (u8)(words[i] >> 48);
        bytes[j + 7] = (u8)(words[i] >> 56);
        j += 8;
    }
}

/**
* Convert  give the bytes in words
* words is a multiple of block size in words
* bytes is a multiple of block size in bytes
*
*  @param bytes  the input bytes
*  @param words  the output words
*  @param numbytes  the lenght of bytes
*/
void BytesToWords64(u8 bytes[], u64 words[], int numbytes)
{
    int i, j = 0;
    for (i = 0; i < numbytes / 8; i++)
    {
        words[i] = (u64)bytes[j] | ((u64)bytes[j + 1] << 8) | ((u64)bytes[j + 2] << 16) |
                   ((u64)bytes[j + 3] << 24) | ((u64)bytes[j + 4] << 32) | ((u64)bytes[j + 5] << 40) |
                   ((u64)bytes[j + 6] << 48) | ((u64)bytes[j + 7] << 56);
        j += 8;
    }
}

static void hex_print(uint8_t *pv, uint16_t s, uint16_t len)
{
    uint8_t *p = pv;
    if (NULL == pv)
        printf("NULL");
    else
    {
        unsigned int i;
        for (i = s; i < len; ++i)
            printf("%02x ", p[i]);
    }
    printf("\n\n");
}
#endif
