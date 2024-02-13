/*
** EPITECH PROJECT, 2021
** LibMy - memory module
** File description:
** Endian-related utilities
*/

/// @file
/// Endian-releated utilities.

#pragma once

#include <stdint.h>

typedef union {
    uint8_t data[2];
    uint16_t num;
} my_m16_t;

typedef union {
    uint8_t data[4];
    uint32_t num;
} my_m32_t;

typedef union {
    uint8_t data[8];
    uint64_t num;
} my_m64_t;

/// Big endian value.
#define MYTEAMS_BIG_ENDIAN (1234)
/// Little endian value.
#define MYTEAMS_LITTLE_ENDIAN (4321)

#if MYTEAMS_ENDIAN == MYTEAMS_LITTLE_ENDIAN
    #include "endian/little_endian_to_be.h"
    #include "endian/little_endian_to_le.h"
#elif MYTEAMS_ENDIAN == MYTEAMS_BIG_ENDIAN
    #include "endian/big_endian_to_be.h"
    #include "endian/big_endian_to_le.h"
#else
    #error \
        "LibMy memory module requires MYTEAMS_ENDIAN to be set to either \
        MYTEAMS_LITTLE_ENDIAN or MYTEAMS_BIG_ENDIAN to be defined"
#endif
