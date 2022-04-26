
--define RFFT_ALIGNMENT=2048
MEMORY
{
PAGE 0 :
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */

   BEGIN           	: origin = 0x000000, length = 0x000002
   RAMM0           	: origin = 0x000123, length = 0x0002DD
   RAMD0           	: origin = 0x00B000, length = 0x000800
   RAMLS0          	: origin = 0x008000, length = 0x000800
   RAMLS12          	: origin = 0x008800, length = 0x001000
   RAMLS34      		: origin = 0x009800, length = 0x001000
   RESET           	: origin = 0x3FFFC0, length = 0x000002

PAGE 1 :

   BOOT_RSVD       : origin = 0x000002, length = 0x000121     /* Part of M0, BOOT rom will use this for stack */
   RAMM1           : origin = 0x000400, length = 0x0003F8     /* on-chip RAM block M1 */
//   RAMM1_RSVD      : origin = 0x0007F8, length = 0x000008     /* Reserve and do not use for code as per the errata advisory "Memory: Prefetching Beyond Valid Memory" */
   RAMD1           : origin = 0x00B800, length = 0x000800

   RAMLS5      : origin = 0x00A800, length = 0x000800

   RAMGS01     : origin = 0x00C000, length = 0x002000
   RAMGS23     : origin = 0x00E000, length = 0x002000
   RAMGS45     : origin = 0x010000, length = 0x002000
   RAMGS6789     : origin = 0x012000, length = 0x004000
   RAMGS1011   : origin = 0x016000, length = 0x002000
//   RAMGS11_RSVD : origin = 0x017FF8, length = 0x000008    /* Reserve and do not use for code as per the errata advisory "Memory: Prefetching Beyond Valid Memory" */

   CANA_MSG_RAM     : origin = 0x049000, length = 0x000800
   CANB_MSG_RAM     : origin = 0x04B000, length = 0x000800
}


SECTIONS
{
   codestart        : > BEGIN,     PAGE = 0
//   .text            : >> RAMD0 |  RAMLS0 | RAMLS12 | RAMLS34 | RAMM0 ,   PAGE = 0
   .text            : >> RAMD1 |  RAMGS6789 | RAMGS1011 | RAMM1 | RAMLS5 ,   PAGE = 1
   .cinit           : > RAMLS0,     PAGE = 0
   .switch          : > RAMLS0,     PAGE = 0
   .reset           : > RESET,     PAGE = 0, TYPE = DSECT /* not used, */

   .stack           : > RAMM1,     PAGE = 1

#if defined(__TI_EABI__)
   .bss             : > RAMLS5,    PAGE = 1
   .bss:output      : > RAMLS0,    PAGE = 0
   .init_array      : > RAMM0,     PAGE = 0
   .const           : > RAMGS1011,    PAGE = 1
   .data            : > RAMLS5,    PAGE = 1
   .sysmem          : > RAMLS5,    PAGE = 1
#else
   .pinit           : > RAMM0,     PAGE = 0
   .ebss            : > RAMLS5,    PAGE = 1
   .econst          : > RAMLS5,    PAGE = 1
   .esysmem         : > RAMLS5,    PAGE = 1
#endif

   ramgs0           : > RAMGS01,    PAGE = 1
   ramgs1           : > RAMGS01,    PAGE = 1

#ifdef __TI_COMPILER_VERSION__
   #if __TI_COMPILER_VERSION__ >= 15009000
    .TI.ramfunc : {} > RAMLS0,      PAGE = 0
   #else
   ramfuncs         : > RAMGS67      PAGE = 1
   #endif
#endif

	RFFTdata1		: > RAMGS23,	PAGE = 1, ALIGN = RFFT_ALIGNMENT
	RFFTdata2		: > RAMGS23,	PAGE = 1
	RFFTdata3		: > RAMGS23,	PAGE = 1
	RFFTdata4		: > RAMGS45,	PAGE = 1
	RFFTdata5		: > RAMGS23,	PAGE = 1
	adcAResultsdata : > RAMGS01,	PAGE = 1
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/
