/*
 *      Small C+ Library
 *
 *  conio.h - old apps compatibility
 * 
 *	This helps expecially with the kbhit() instruction
 *	it exists on many old compilers; the mingw port has it
 *	on "conio.h", so here it is !
 *
 *      stefano - 18/3/2004
 *
 *	$Id: conio.h,v 1.10 2013-06-20 08:25:45 stefano Exp $
 */

#ifndef __CONIO_H__
#define __CONIO_H__

// this is used by getch, putch and ungetch.
#include <sys/compiler.h>
#include <stdio.h>
#include <stdlib.h>
//#include <graphics.h>
#include <dos.h>
#include <X11/Xz88dk.h>


/*
// Old crap gotoxy() stuff

#if defined __SVI__ || defined __MSX__
#define gotoxy(a,b)     printf("\033Y%c%c",b+31,a+31)
#define delline()	printf("\033M")
#define clrscr() printf("\033E")
#define clreol() printf("\033K")
#endif


#if __SC3000__
extern unsigned char *sc_cursor_pos;
#define gotoxy(a,b)     sc_cursor_pos[0]=a; sc_cursor_pos[1]=b
#define clrscr() printf("\014")
#endif

#if __M5__
extern unsigned char *sc_cursor_pos;
#define gotoxy(a,b)     sc_cursor_pos[1]=a-1; sc_cursor_pos[0]=b-1
#define clrscr() printf("\014")
#endif
*/

/* Fallback to ANSI VT escape sequences */
#ifndef gotoxy

#define MAXCOLORS       15
enum colors { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
              LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE };

// Color translation table
static int PCDOS_COLORS[]={0,4,2,6,1,5,1,7,4,6,2,6,1,5,3,7};

// Much faster shortcut passing the colors in vt-ansi mode (equivalent to a "set text rendition" ESC sequence)
extern void   __LIB__      vtrendition(unsigned int attribute) __z88dk_fastcall;

// QUICK C syntax
#define settextcolor(a)    vtrendition(PCDOS_COLORS[a]+30)

// TURBO C syntax
#define textcolor(a)       vtrendition(PCDOS_COLORS[a]+30)
#define textbackground(a)  vtrendition(PCDOS_COLORS[a]+40)

#define textattr(a)		   vtrendition(PCDOS_COLORS[a&0xF]+30); vtrendition(PCDOS_COLORS[a>>4]+40)

#define highvideo()        vtrendition(1)
#define lowvideo()         vtrendition(2)
#define normvideo()        vtrendition(0)

// Useless, DL is not fully implemented in the VT-ansi engine
//#define delline()	       printf("\033[M")

#define clrscr()           fputc_cons(12)
#define clreol()           printf("\033[K")

extern int     __LIB__     wherex (void);
extern int     __LIB__     wherey (void);
extern void    __LIB__     gotoxy(unsigned int x, unsigned int y) __smallc;
extern void    __LIB__     gotoxy_callee(unsigned int x, unsigned int y) __smallc __z88dk_callee;

extern void    __LIB__     screensize(unsigned int *x, unsigned int *y) __smallc;
extern void    __LIB__     screensize_callee(unsigned char *x, unsigned char *y) __smallc __z88dk_callee;

#define gotoxy(a,b) gotoxy_callee(a,b)
#define screensize(a,b) screensize_callee(a,b)


#endif

/* The leading underscores are for compatibility with the 
 * Digital Mars library */

extern int __LIB__ cprintf(const char *fmt,...) __vasmallc;
#define _cprintf cprintf
extern void __LIB__ cputs(const char *message);
#define _cputs cputs
extern void __LIB__ cgets(char *dest);
#define _cgets cgets

#define cscanf scanf
#define _cscanf scanf

/* Reads a character directly from the console, (with echo ?) */
#define getche() getch()               // not sure about this one...
#define _getche() getch()                // not sure about this one...
// Direct output to console
#define putch(a) fputc_cons(a)
#define _putch(a) fputc_cons(a)

// can't be fixed easily.. i.e. the simplified gets won't work
//#define ungetch(bp)  ungetc(bp,stdin)  // this one doesn't work
//#define _ungetch(bp)  ungetc(bp,stdin)  // this one doesn't work

#define random(a) rand()%a

extern int __LIB__ kbhit(void);
extern int __LIB__ getch(void);

// Missing functions, not implemented
//extern int  __LIB__ movetext (int _left, int _top, int _right, int _bottom, int _destleft, int _desttop);
//extern int  __LIB__ gettext (int left, int top, int right, int bottom, void *destin);


#endif /* _CONIO_H */
