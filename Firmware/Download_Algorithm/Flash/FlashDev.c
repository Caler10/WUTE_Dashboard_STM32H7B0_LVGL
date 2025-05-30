/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2020 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashDev.c:  Device Description for ST STM32H7B3I-B0-DISCO Flash      */
/*                                                                     */
/***********************************************************************/

#include "FlashOS.H"       


#ifdef FLASH_MEM
struct FlashDevice const FlashDevice  =  {
    FLASH_DRV_VERS,                   	// Driver Version, do not modify!
    "FANKE_FK7B0M1_V1",   					// Device Name 
    EXTSPI,                            // Device Type
    0x90000000,                       	// Device Start Address
    8 * 1024 * 1024,                 	// Device Size in Bytes (8MB)
    8 * 1024,                         	// Programming Page Size 4096 Bytes
    0,                               	// Reserved, must be 0
    0xFF,                             	// Initial Content of Erased Memory
    1000,                             	// Program Page Timeout
    6000,                              // Erase Sector Timeout 
    64 * 1024, 0x000000,              	// Sector Size  64kB and Address of Sectors	
    SECTOR_END    
};
#endif // FLASH_MEM


