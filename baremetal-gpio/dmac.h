/*
 * Copyright 2017 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef _DMAC_H
#define _DMAC_H

#include "registers.h"

#define CMD_DMAADDH             0x54
#define CMD_DMAEND              0x00
#define CMD_DMAFLUSHP           0x35
#define CMD_DMAGO               0xa0
#define CMD_DMALD               0x04
#define CMD_DMALDP              0x25
#define CMD_DMALP               0x20
#define CMD_DMALPEND            0x28
#define CMD_DMAKILL             0x01
#define CMD_DMAMOV              0xbc
#define CMD_DMANOP              0x18
#define CMD_DMARMB              0x12
#define CMD_DMASEV              0x34
#define CMD_DMAST               0x08
#define CMD_DMASTP              0x29
#define CMD_DMASTZ              0x0c
#define CMD_DMAWFE              0x36
#define CMD_DMAWFP              0x30
#define CMD_DMAWMB              0x13

#define SZ_DMAADDH              3
#define SZ_DMAEND               1
#define SZ_DMAFLUSHP            2
#define SZ_DMALD                1
#define SZ_DMALDP               2
#define SZ_DMALP                2
#define SZ_DMALPEND             2
#define SZ_DMAKILL              1
#define SZ_DMAMOV               6
#define SZ_DMANOP               1
#define SZ_DMARMB               1
#define SZ_DMASEV               2
#define SZ_DMAST                1
#define SZ_DMASTP               2
#define SZ_DMASTZ               1
#define SZ_DMAWFE               2
#define SZ_DMAWFP               2
#define SZ_DMAWMB               1
#define SZ_DMAGO                6

#endif
