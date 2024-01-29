/*
 * Copyright 2017 Google, Inc
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __REGISTERS_H__
#define __REGISTERS_H__

#define LOW     0
#define HIGH    1
#define INPUT   0
#define OUTPUT  1
#define UART_LSR_THRE   0x20          /* Xmit holding register empty */
#define UART_LSR_DRY    0x1           /* data ready */

#define BOOTROM_BASE            0xff080000
#define SRAM_BASE               0xff090000

/* DMAC PL330 */
#define DMAC_BUS_DSR_NS             (volatile unsigned int *)0xff1f0000
#define DMAC_BUS_DSR                (volatile unsigned int *)0xff1f0000
#define DMAC_BUS_DPC                (volatile unsigned int *)0xff1f0004
#define DMAC_BUS_INTEN              (volatile unsigned int *)0xff1f0020
#define DMAC_BUS_INTCLR             (volatile unsigned int *)0xff1f002c
#define DMAC_BUS_FSRD               (volatile unsigned int *)0xff1f0030
#define DMAC_BUS_FSRC               (volatile unsigned int *)0xff1f0034
#define DMAC_BUS_FTRD               (volatile unsigned int *)0xff1f0038
#define DMAC_BUS_FTR0               (volatile unsigned int *)0xff1f0040
#define DMAC_BUS_CSR0               (volatile unsigned int *)0xff1f0100
#define DMAC_BUS_CPC0               (volatile unsigned int *)0xff1f0104
#define DMAC_BUS_SAR0               (volatile unsigned int *)0xff1f0400
#define DMAC_BUS_DAR0               (volatile unsigned int *)0xff1f0404
#define DMAC_BUS_CCR0               (volatile unsigned int *)0xff1f0408
#define DMAC_BUS_LC0_0              (volatile unsigned int *)0xff1f040c
#define DMAC_BUS_DBGST              (volatile unsigned int *)0xff1f0d00
#define DMAC_BUS_DBGCMD             (volatile unsigned int *)0xff1f0d04
#define DMAC_BUS_DBGINST0           (volatile unsigned int *)0xff1f0d08
#define DMAC_BUS_DBGINST1           (volatile unsigned int *)0xff1f0d0c
#define DMAC_BUS_CR0                (volatile unsigned int *)0xff1f0e00
#define DMAC_BUS_CR1                (volatile unsigned int *)0xff1f0e04
#define DMAC_BUS_CR2                (volatile unsigned int *)0xff1f0e08
#define DMAC_BUS_CR3                (volatile unsigned int *)0xff1f0e0c
#define DMAC_BUS_CR4                (volatile unsigned int *)0xff1f0e10
#define DMAC_BUS_CDRn               (volatile unsigned int *)0xff1f0e14

/* Distributor Registers */
#define GICD_CTLR               (volatile unsigned int *)0xff811000
#define GICD_TYPER              (volatile unsigned int *)0xff811004
#define GICD_IIDR               (volatile unsigned int *)0xff811008
#define GICD_IGROUPRn           (volatile unsigned int *)0xff811080
#define GICD_IGROUPRnx                                   0xff811080
#define GICD_ISENABLERn         (volatile unsigned int *)0xff811100
#define GICD_ISENABLERnx                                 0xff811100
#define GICD_ICENABLERn         (volatile unsigned int *)0xff811180
#define GICD_ICENABLERnx                                 0xff811180
#define GICD_ISPENDRn           (volatile unsigned int *)0xff811200
#define GICD_ICPENDRn           (volatile unsigned int *)0xff811280
#define GICD_ICACTIVERn         (volatile unsigned int *)0xff811380
#define GICD_IPRIORITYRn        (volatile unsigned int *)0xff811400
#define GICD_ITARGETSRn         (volatile unsigned int *)0xff811800
#define GICD_ITARGETSRnx                                 0xff811800
#define GICD_ICFGRn             (volatile unsigned int *)0xff811c00
#define GICD_ICFGRnx                                     0xff811c00
#define GICD_SGIR               (volatile unsigned int *)0xff811f00

/* Cpu Interface Memory Mapped Registers */
#define GICC_CTLR               (volatile unsigned int *)0xff812000
#define GICC_PMR                (volatile unsigned int *)0xff812004
#define GICC_BPR                (volatile unsigned int *)0xff812008
#define GICC_IAR                (volatile unsigned int *)0xff81200C
#define GICC_EOIR               (volatile unsigned int *)0xff812010
#define GICC_RPR                (volatile unsigned int *)0xff812014
#define GICC_HPPIR              (volatile unsigned int *)0xff812018
#define GICC_ABPR               (volatile unsigned int *)0xff81201c
#define GICC_IIDR               (volatile unsigned int *)0xff8120fc

#define I2S_TXCR                (volatile unsigned int *)0xff890000
#define I2S_RXCR                (volatile unsigned int *)0xff890004
#define I2S_CKR                 (volatile unsigned int *)0xff890008
#define I2S_FIFOLR              (volatile unsigned int *)0xff89000c
#define I2S_DMACR               (volatile unsigned int *)0xff890010
#define I2S_INTCR               (volatile unsigned int *)0xff890014
#define I2S_INTSR               (volatile unsigned int *)0xff890018
#define I2S_XFER                (volatile unsigned int *)0xff89001c
#define I2S_CLR                 (volatile unsigned int *)0xff890020
#define I2S_TXDR                (volatile unsigned int *)0xff890024
#define I2S_RXDR                (volatile unsigned int *)0xff890028

#define DWMCI_CTRL              (volatile unsigned int *)0xff500000
#define DWMCI_PWREN             (volatile unsigned int *)0xff500004
#define DWMCI_CLKDIV            (volatile unsigned int *)0xff500008
#define DWMCI_CLKSRC            (volatile unsigned int *)0xff50000C
#define DWMCI_CLKENA            (volatile unsigned int *)0xff500010
#define DWMCI_TMOUT             (volatile unsigned int *)0xff500014
#define DWMCI_CTYPE             (volatile unsigned int *)0xff500018
#define DWMCI_BLKSIZ            (volatile unsigned int *)0xff50001C
#define DWMCI_BYTCNT            (volatile unsigned int *)0xff500020
#define DWMCI_INTMASK           (volatile unsigned int *)0xff500024
#define DWMCI_CMDARG            (volatile unsigned int *)0xff500028
#define DWMCI_CMD               (volatile unsigned int *)0xff50002C
#define DWMCI_RESP0             (volatile unsigned int *)0xff500030
#define DWMCI_RESP1             (volatile unsigned int *)0xff500034
#define DWMCI_RESP2             (volatile unsigned int *)0xff500038
#define DWMCI_RESP3             (volatile unsigned int *)0xff50003C
#define DWMCI_MINTSTS           (volatile unsigned int *)0xff500040
#define DWMCI_RINTSTS           (volatile unsigned int *)0xff500044
#define DWMCI_STATUS            (volatile unsigned int *)0xff500048
#define DWMCI_FIFOTH            (volatile unsigned int *)0xff50004C
#define DWMCI_CDETECT           (volatile unsigned int *)0xff500050
#define DWMCI_WRTPRT            (volatile unsigned int *)0xff500054
#define DWMCI_GPIO              (volatile unsigned int *)0xff500058
#define DWMCI_TCMCNT            (volatile unsigned int *)0xff50005C
#define DWMCI_TBBCNT            (volatile unsigned int *)0xff500060
#define DWMCI_DEBNCE            (volatile unsigned int *)0xff500064
#define DWMCI_USRID             (volatile unsigned int *)0xff500068
#define DWMCI_VERID             (volatile unsigned int *)0xff50006C
#define DWMCI_HCON              (volatile unsigned int *)0xff500070
#define DWMCI_UHS_REG           (volatile unsigned int *)0xff500074
#define DWMCI_BMOD              (volatile unsigned int *)0xff500080
#define DWMCI_PLDMND            (volatile unsigned int *)0xff500084
#define DWMCI_DBADDR            (volatile unsigned int *)0xff500088
#define DWMCI_IDSTS             (volatile unsigned int *)0xff50008C
#define DWMCI_IDINTEN           (volatile unsigned int *)0xff500090
#define DWMCI_DSCADDR           (volatile unsigned int *)0xff500094
#define DWMCI_BUFADDR           (volatile unsigned int *)0xff500098
#define DWMCI_DATA              (volatile unsigned int *)0xff500200

#define SPI_CTRLR0    (volatile unsigned int *)0xff190000
#define SPI_CTRLR1    (volatile unsigned int *)0xff190004
#define SPI_ENR       (volatile unsigned int *)0xff190008
#define SPI_SER       (volatile unsigned int *)0xff19000c
#define SPI_BAUDR     (volatile unsigned int *)0xff190010
#define SPI_TXFTLR    (volatile unsigned int *)0xff190014
#define SPI_RXFTLR    (volatile unsigned int *)0xff190018
#define SPI_TXFLR     (volatile unsigned int *)0xff19001c
#define SPI_RXFLR     (volatile unsigned int *)0xff190020
#define SPI_SR        (volatile unsigned int *)0xff190024
#define SPI_IPR       (volatile unsigned int *)0xff190028
#define SPI_IMR       (volatile unsigned int *)0xff19002c
#define SPI_ISR       (volatile unsigned int *)0xff190030
#define SPI_RISR      (volatile unsigned int *)0xff190034
#define SPI_ICR       (volatile unsigned int *)0xff190038
#define SPI_DMACR     (volatile unsigned int *)0xff19003c
#define SPI_DMATDLR   (volatile unsigned int *)0xff190040
#define SPI_DMARDLR   (volatile unsigned int *)0xff190044
#define SPI_TXDR      (volatile unsigned int *)0xff190400
#define SPI_RXDR      (volatile unsigned int *)0xff190800

#define I2C0_CON       (volatile unsigned int *)0xff150000
#define I2C0_CLKDIV    (volatile unsigned int *)0xff150004
#define I2C0_MRXADDR   (volatile unsigned int *)0xff150008
#define I2C0_MRXRADDR  (volatile unsigned int *)0xff15000c
#define I2C0_MTXCNT    (volatile unsigned int *)0xff150010
#define I2C0_MRXCNT    (volatile unsigned int *)0xff150014
#define I2C0_IEN       (volatile unsigned int *)0xff150018
#define I2C0_IPD       (volatile unsigned int *)0xff15001c
#define I2C0_FCNT      (volatile unsigned int *)0xff150020
#define I2C0_TXDATA    (volatile unsigned int *)0xff150100
#define I2C0_RXDATA    (volatile unsigned int *)0xff150200
#define I2C0_TXDATA_BASE (volatile unsigned int *)0xff150100
#define I2C0_RXDATA_BASE (volatile unsigned int *)0xff150200

#define UART0_THR (volatile unsigned int *)0xff110000
#define UART0_DR  (volatile unsigned int *)0xff110000
#define UART0_DLL (volatile unsigned int *)0xff110000
#define UART0_DLM (volatile unsigned int *)0xff110004
#define UART0_IER (volatile unsigned int *)0xff110004
#define UART0_FCR (volatile unsigned int *)0xff110008
#define UART0_IIR (volatile unsigned int *)0xff110008
#define UART0_LCR (volatile unsigned int *)0xff11000c
#define UART0_MCR (volatile unsigned int *)0xff110010
#define UART0_LSR (volatile unsigned int *)0xff110014
#define UART0_MSR (volatile unsigned int *)0xff110018
#define UART0_USR (volatile unsigned int *)0xff11007c
#define UART1_THR (volatile unsigned int *)0xff120000
#define UART1_DR  (volatile unsigned int *)0xff120000
#define UART1_DLL (volatile unsigned int *)0xff120000
#define UART1_DLM (volatile unsigned int *)0xff120004
#define UART1_IER (volatile unsigned int *)0xff120004
#define UART1_FCR (volatile unsigned int *)0xff120008
#define UART1_IIR (volatile unsigned int *)0xff120008
#define UART1_LCR (volatile unsigned int *)0xff12000c
#define UART1_MCR (volatile unsigned int *)0xff120010
#define UART1_LSR (volatile unsigned int *)0xff120014
#define UART1_MSR (volatile unsigned int *)0xff120018
#define UART1_USR (volatile unsigned int *)0xff12007c
#define UART2_THR (volatile unsigned int *)0xff130000
#define UART2_DR  (volatile unsigned int *)0xff130000
#define UART2_DLL (volatile unsigned int *)0xff130000
#define UART2_DLM (volatile unsigned int *)0xff130004
#define UART2_IER (volatile unsigned int *)0xff130004
#define UART2_FCR (volatile unsigned int *)0xff130008
#define UART2_IIR (volatile unsigned int *)0xff130008
#define UART2_LCR (volatile unsigned int *)0xff13000c
#define UART2_MCR (volatile unsigned int *)0xff130010
#define UART2_LSR (volatile unsigned int *)0xff130014
#define UART2_MSR (volatile unsigned int *)0xff130018
#define UART2_USR (volatile unsigned int *)0xff13007c

#define TIMER5_LOAD_COUNT0 (volatile unsigned int *)0xff1c00a0
#define TIMER5_LOAD_COUNT1 (volatile unsigned int *)0xff1c00a4
#define TIMER5_CURR_VALUE0 (volatile unsigned int *)0xff1c00a8
#define TIMER5_CURR_VALUE1 (volatile unsigned int *)0xff1c00ac
#define TIMER5_CTRL_REG    (volatile unsigned int *)0xff1c00b0
#define TIMER5_INT_STATUS  (volatile unsigned int *)0xff1c00b8

#define CRU_APLL_CON0     (volatile unsigned int *)0xff440000
#define CRU_APLL_CON1     (volatile unsigned int *)0xff440004
#define CRU_APLL_CON2     (volatile unsigned int *)0xff440008
#define CRU_APLL_CON3     (volatile unsigned int *)0xff44000c
#define CRU_APLL_CON4     (volatile unsigned int *)0xff440010
#define CRU_DPLL_CON0     (volatile unsigned int *)0xff440020
#define CRU_DPLL_CON1     (volatile unsigned int *)0xff440024
#define CRU_DPLL_CON2     (volatile unsigned int *)0xff440028
#define CRU_DPLL_CON3     (volatile unsigned int *)0xff44002c
#define CRU_DPLL_CON4     (volatile unsigned int *)0xff440030
#define CRU_CPLL_CON0     (volatile unsigned int *)0xff440040
#define CRU_CPLL_CON1     (volatile unsigned int *)0xff440044
#define CRU_CPLL_CON2     (volatile unsigned int *)0xff440048
#define CRU_CPLL_CON3     (volatile unsigned int *)0xff44004c
#define CRU_CPLL_CON4     (volatile unsigned int *)0xff440050
#define CRU_GPLL_CON0     (volatile unsigned int *)0xff440060
#define CRU_GPLL_CON1     (volatile unsigned int *)0xff440064
#define CRU_GPLL_CON2     (volatile unsigned int *)0xff440068
#define CRU_GPLL_CON3     (volatile unsigned int *)0xff44006c
#define CRU_GPLL_CON4     (volatile unsigned int *)0xff440070
#define CRU_NPLL_CON0     (volatile unsigned int *)0xff4400a0
#define CRU_NPLL_CON1     (volatile unsigned int *)0xff4400a4
#define CRU_NPLL_CON2     (volatile unsigned int *)0xff4400a8
#define CRU_NPLL_CON3     (volatile unsigned int *)0xff4400ac
#define CRU_NPLL_CON4     (volatile unsigned int *)0xff4400b0
#define CRU_SDMMC_CON0    (volatile unsigned int *)0xff440380
#define CRU_SDMMC_CON1    (volatile unsigned int *)0xff440384

#define CRU_MODE_CON      (volatile unsigned int *)0xff440080
#define CRU_CLKSEL_CON16  (volatile unsigned int *)0xff440140
#define CRU_CLKSEL_CON18  (volatile unsigned int *)0xff440148
#define CRU_CLKSEL_CON24  (volatile unsigned int *)0xff440160
#define CRU_CLKSEL_CON28  (volatile unsigned int *)0xff440170
#define CRU_CLKSEL_CON29  (volatile unsigned int *)0xff440174
#define CRU_CLKSEL_CON30  (volatile unsigned int *)0xff440178
#define GPIO0_SWPORTA_DR       (volatile unsigned int *)0xFF210000
#define GPIO0_SWPORTA_DDR      (volatile unsigned int *)0xFF210004
#define GPIO3_SWPORTA_DR       (volatile unsigned int *)0xFF240000
#define GPIO3_SWPORTA_DDR      (volatile unsigned int *)0xFF240004
#define GPIO3_EXT_PORTA        (volatile unsigned int *)0xFF240050
#define GPIO0A                 (volatile unsigned int *)0xFF100000
#define GPIO1A                 (volatile unsigned int *)0xFF100010
#define GPIO1B                 (volatile unsigned int *)0xFF100014
#define GPIO1C                 (volatile unsigned int *)0xFF100018
#define GPIO2A                 (volatile unsigned int *)0xFF100020
#define GPIO2BL                (volatile unsigned int *)0xFF100024
#define GPIO2D                 (volatile unsigned int *)0xFF100034
#define GPIO3AL                (volatile unsigned int *)0xFF100038
#define GPIO3AH                (volatile unsigned int *)0xFF10003c
#define GPIO3BL                (volatile unsigned int *)0xFF100040
#define GPIO_COM_IOMUX         (volatile unsigned int *)0xFF100050
#define GPIO4C                 (volatile unsigned int *)0xFF100044
#define GPIO5B                 (volatile unsigned int *)0xFF100050
#define GPIO5C                 (volatile unsigned int *)0xFF100054
#define GPIO6A                 (volatile unsigned int *)0xFF10005C
#define GPIO7A                 (volatile unsigned int *)0xFF10006C
#define GPIO7B                 (volatile unsigned int *)0xFF100070
#define GPIO7CL                (volatile unsigned int *)0xFF100074
#define GPIO7CH                (volatile unsigned int *)0xFF100078
#define GPIO8A                 (volatile unsigned int *)0xFF100080
#define GPIO8B                 (volatile unsigned int *)0xFF100084

#define PWM2_CTRL              (volatile unsigned int *)0xFF1b002c
#define PWM2_DUTY              (volatile unsigned int *)0xFF1b0028
#define PWM2_PERIOD            (volatile unsigned int *)0xFF1b0024

void printf(const char *fmt, ...);

#endif
