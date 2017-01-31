/**
 * @file getstk.c
 * @provides getstk
 *
 * $Id: getstk.c 241 2007-07-13 22:24:20Z agember $
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <kernel.h>

extern char *maxheap;
extern void *end;

/**
 * Allocate stack memory, returning address of topmost word.
 * @param nbytes amount of memory to allocate, in bytes
 * @return address of the topmost word
 */
void *getstk(ulong nbytes)
{
  /* NOTE: This is a completely broken implementation of getstk(),      */
  /*  intended only for introductory assignments before implementing    */
  /*  proper dynamic heap allocation.                                   */

	ulong newstk;

	if (nbytes == 0) 
	{ return( (void *)SYSERR ); }
  
	nbytes = (nbytes + 15) & ~0x0F;

	if ((long)maxheap - nbytes < (int)&end)
	{ return( (void *)SYSERR ); }

	newstk = (ulong)maxheap - 4;
	maxheap = (char *)(((int)maxheap) - nbytes);

	return ((void *)newstk);
}
