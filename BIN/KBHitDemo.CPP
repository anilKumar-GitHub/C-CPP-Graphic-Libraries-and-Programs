#include <stdio.h>                                            /* 1 */
#include <conio.h>  /* for kbhit */                           /* 2 */
#include <dos.h>                                              /* 3 */
							      /* 4 */
int getkey(void);                                             /* 5 */
							      /* 6 */
void main(void)                                               /* 7 */
{                                                             /* 8 */
   int i=0,key;                                                   /* 9 */
   clrscr();
   while(key != 27)                                                   /* 10 */
   {                                                          /* 11 */
      if (kbhit)                                              /* 12 */
      {                                                       /* 13 */
	 key=getkey();		                              /* 14 */
	 printf("\t%c\t\t D: %d\t\t H: %X\t\t O: %o\n", key,key,key,key);                  /* 15 */
      }                                                       /* 16 */
   }
							  /* 17 */
}                                                             /* 18 */
							      /* 19 */
int getkey(void)                                              /* 20 */
{                                                             /* 21 */
   union REGS in, out;                                        /* 22 */
   in.h.ah = 0x08;                                            /* 23 */
   int86(0x21, &in, &out);                                    /* 24 */
   if (out.h.al == 0)                                         /* 25 */
   {                                                          /* 26 */
      return(getkey()+0x100);                                 /* 27 */
   }                                                          /* 28 */
   else                                                       /* 29 */
   {                                                          /* 30 */
      return(out.h.al);                                       /* 31 */
   }                                                          /* 32 */
}
