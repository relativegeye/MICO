/**
******************************************************************************
* @file    platform_common_config.h
* @author  William Xu
* @version V1.0.0
* @date    05-May-2014
* @brief   This file provides common configuration for current platform.
******************************************************************************
*
*  The MIT License
*  Copyright (c) 2014 MXCHIP Inc.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy 
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights 
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is furnished
*  to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
*  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************
*/ 
#ifndef __PLATFORM_COMMON_CONFIG_H__
#define __PLATFORM_COMMON_CONFIG_H__
#pragma once

/******************************************************
*                      Macros
******************************************************/

/******************************************************
*                    Constants
******************************************************/

/* MICO RTOS tick rate in Hz */
#define MICO_DEFAULT_TICK_RATE_HZ                   (1000) 

/************************************************************************
 * Uncomment to disable watchdog. For debugging only */
//#define MICO_DISABLE_WATCHDOG

/************************************************************************
 * Uncomment to disable standard IO, i.e. printf(), etc. */
//#define MICO_DISABLE_STDIO

/************************************************************************
 * Uncomment to disable MCU powersave API functions */
#define MICO_DISABLE_MCU_POWERSAVE

/************************************************************************
 * Uncomment to enable MCU real time clock */
//#define MICO_ENABLE_MCU_RTC

/************************************************************************
 * Uncomment to enable SDIO 1bit mode */
#define SDIO_1_BIT

/* Memory mapping */

#define USE_MICO_SPI_FLASH

#define INTERNAL_FLASH_START_ADDRESS   (uint32_t)0x00000000
#define INTERNAL_FLASH_END_ADDRESS     (uint32_t)0x00000000
#define INTERNAL_FLASH_SIZE            (INTERNAL_FLASH_END_ADDRESS - INTERNAL_FLASH_START_ADDRESS + 1)

#define SPI_FLASH_START_ADDRESS         (uint32_t)0x00000000
#define SPI_FLASH_END_ADDRESS           (uint32_t)0x001FFFFF
#define SPI_FLASH_SIZE                  (SPI_FLASH_END_ADDRESS - SPI_FLASH_START_ADDRESS + 1) /* 2M bytes*/

#define MICO_FLASH_FOR_BOOT         MICO_SPI_FLASH
#define BOOT_START_ADDRESS          (uint32_t)0x00000000 
#define BOOT_END_ADDRESS            (uint32_t)0x00009FFF 
#define BOOT_FLASH_SIZE             (BOOT_END_ADDRESS - BOOT_START_ADDRESS + 1)   /* 36k bytes */

#define MICO_FLASH_FOR_PARA         MICO_SPI_FLASH
#define PARA_START_ADDRESS          (uint32_t)0x0000B000 //Need 1 kbytes free space before papa in MX1101
#define PARA_END_ADDRESS            (uint32_t)0x0000BFFF
#define PARA_FLASH_SIZE             (PARA_END_ADDRESS - PARA_START_ADDRESS + 1)  /* 4k bytes */

#define MICO_FLASH_FOR_EX_PARA      MICO_SPI_FLASH
#define EX_PARA_START_ADDRESS       (uint32_t)0x0000C000
#define EX_PARA_END_ADDRESS         (uint32_t)0x0000CFFF
#define EX_PARA_FLASH_SIZE          (EX_PARA_END_ADDRESS - EX_PARA_START_ADDRESS + 1)   /* 4k bytes */

#define MICO_FLASH_FOR_DRIVER       MICO_SPI_FLASH
#define DRIVER_START_ADDRESS        (uint32_t)0x0000D000 
#define DRIVER_END_ADDRESS          (uint32_t)0x0005AFFF
#define DRIVER_FLASH_SIZE           (DRIVER_END_ADDRESS - DRIVER_START_ADDRESS + 1)  /* 312k bytes */

#ifdef MICO_FLASH_FOR_DRIVER /* Has a predefined RF driver location */
#define MICO_FLASH_FOR_APPLICATION  MICO_SPI_FLASH
#define APPLICATION_START_ADDRESS   (uint32_t)0x0005B000
#define APPLICATION_END_ADDRESS     (uint32_t)0x000DAFFF
#define APPLICATION_FLASH_SIZE      (APPLICATION_END_ADDRESS - APPLICATION_START_ADDRESS + 1) /* 512k bytes */

#define MICO_FLASH_FOR_UPDATE       MICO_SPI_FLASH /* Optional */
#define UPDATE_START_ADDRESS        (uint32_t)0x000DB000  /* Optional */
#define UPDATE_END_ADDRESS          (uint32_t)0x0015AFFF  /* Optional */
#define UPDATE_FLASH_SIZE           (UPDATE_END_ADDRESS - UPDATE_START_ADDRESS + 1) /* 512k bytes, optional*/
#else /* RF driver is build in application */
#define MICO_FLASH_FOR_APPLICATION  MICO_SPI_FLASH
#define APPLICATION_START_ADDRESS   (uint32_t)0x0000D000
#define APPLICATION_END_ADDRESS     (uint32_t)0x000CCFFF
#define APPLICATION_FLASH_SIZE      (APPLICATION_END_ADDRESS - APPLICATION_START_ADDRESS + 1) /* 768k bytes */

#define MICO_FLASH_FOR_UPDATE       MICO_SPI_FLASH /* Optional */
#define UPDATE_START_ADDRESS        (uint32_t)0x000CD000  /* Optional */
#define UPDATE_END_ADDRESS          (uint32_t)0x0018CFFF  /* Optional */
#define UPDATE_FLASH_SIZE           (UPDATE_END_ADDRESS - UPDATE_START_ADDRESS + 1) /* 768k bytes, optional*/
#endif

/******************************************************
*                   Enumerations
******************************************************/

/******************************************************
*                 Type Definitions
******************************************************/

/******************************************************
*                    Structures
******************************************************/

/******************************************************
*                 Global Variables
******************************************************/

/******************************************************
*               Function Declarations
******************************************************/
#endif

