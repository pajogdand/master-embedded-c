#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifdef MSDOS				/* for MSC only at the moment... */
#include <fcntl.h>
#else /* MSDOS */
#include <sys/file.h>
#define HAVE_RANDOM			/* XXX: might have to change */
#endif /* MSDOS */

/* Note: This file contains all global definitions that are also available
 * to the Application
 */
typedef uint8_t   swi_uint8;   /* 8  bit integer unsigned  */
typedef uint16_t  swi_uint16;  /* 16 bit integer unsigned  */
typedef uint32_t  swi_ulong;  /* at least 32 bit integer unsigned  */
typedef uint32_t  swi_uint32; /* 32 bit integer unsigned  */
typedef uint64_t  swi_uint64;  /* 64 bit integer unsigned  */

typedef int8_t    swi_int8;    /* 8  bit integer signed    */
typedef int16_t   swi_int16;   /* 16 bit integer signed    */
typedef int32_t   swi_int32;   /* 32 bit integer signed    */
typedef int64_t   swi_int64;   /* 64 bit integer signed    */

typedef uintptr_t swi_uintptr;

typedef int swi_bool;    /* boolean type used for true/false. should only be
                          * tested for zero or non-zero
                          */
typedef char swi_char, *swi_charp;  /* char type */
/* FW download defines */
#define    IM_CHUNK_SIZE            1024*4
#define    IM_SIERRA_CWE_IMAGE      0x80
#define    IM_MAX_BUF_SIZE          256

/* Logging masks */
#define IMLOG_CLASSA        0x0001
#define IMLOG_CLASSB        0x0002
#define IMLOG_CLASSC        0x0004
/* IM task control block */

void dlLog(swi_ulong param1)
{
    printf("in dlLog1 :: value of param1 = %x \n" , param1);
}

void dlLog1(swi_ulong param1)
{
    printf("in dlLog1 :: value of param1 = %x \n" , param1);
    dlLog(param1);
}

int main()
{
    swi_char    fullpathfilename[IM_MAX_BUF_SIZE]={0};

    printf("in main :: value of fullpathfilename = %lx \n" , fullpathfilename);
    printf("in main :: value of (swi_uintptr)fullpathfilename = %lx \n" ,(swi_uintptr)fullpathfilename);
    dlLog1((swi_uintptr)fullpathfilename);

    exit(0);
}



