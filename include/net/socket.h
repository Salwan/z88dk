/*
 *	ZSock API
 *
 *	Socket orientated routines
 *
 *	djm 13/2/2000
 */

#ifndef __NET_SOCKET_H
#define __NET_SOCKET_H

#include <sys/types.h>
#include <net/inet.h>

/*
 * You don't wanna know what a SOCKET is..trust me!!
 */

#define SOCKET void

/*
 * Write data at dp of length len to socket s
 *
 * Returns length written
 */

extern size_t __LIB__ __SHARED__ sock_write(SOCKET *s,void *dp,size_t len);

/*
 * Write byte c to socket s
 *
 * Returns length written
 */

extern size_t __LIB__ __SHARED__  sock_putc(char c,SOCKET *s);

/* 
 * Write a null terminated string to socket s
 *
 * Returns length written
 */

extern size_t __LIB__ __SHARED__  sock_puts(SOCKET *s,char *dp);

/*
 * Flush the socket (Valid for TCP)
 */

extern void  __LIB__ __SHARED__ sock_flush(SOCKET *s);

/*
 * Read up to len bytes to address dp from socket s
 *
 * Return length read
 */

extern size_t __LIB__ __SHARED__  sock_read(SOCKET *s,u8_t *dp,size_t len);

/*
 * Close a socket
 */

extern void __LIB__ __SHARED__  sock_close(SOCKET *s);

/*
 * Abort a connection
 */

extern void __LIB__ __SHARED__  sock_abort(SOCKET *s);

/*
 * Shutdown a socket - finish with it completely
 */

extern void __LIB__ __SHARED__ sock_shutdown(SOCKET *s);

/*
 * Test to see if a socket has data ready, returns amount
 * of data available to read
 */

extern size_t __LIB__ __SHARED__  sock_dataready(SOCKET *s);

/*
 * Test whether a socket is open 
 * returns TRUE/FALSE
 */

extern bool_t __LIB__ __SHARED__ sock_opened(SOCKET *s);

/*
 * Test whether a socket is closed
 * returns TRUE/FALSE
 */

extern bool_t __LIB__ __SHARED__ sock_closed(SOCKET *s);

/*
 * Open a socket for either listen or active connection
 *
 * ipaddr	= network order ip address to listen/connect
 * lport/dport  = host order port to listen/connect to
 * datahandler  = supply as NULL
 * protocol	= prot_TCP or prot_UDP
 */

extern SOCKET __LIB__ __SHARED__ *sock_listen(ipaddr_t ipaddr,tcpport_t lport,void (*datahandler)(),char protocol);
extern SOCKET __LIB__ __SHARED__ *sock_pair_listen(ipaddr_t ipaddr,tcpport_t lport,tcpport_t dport,void (*datahandler)(),char protocol);
extern SOCKET __LIB__ __SHARED__ *sock_open(ipaddr_t ipaddr,tcpport_t dport,void (*datahandler)(),char protocol);

/*
 * Check and set timeouts on a socket (not used much)
 *
 * chk_timeout returns TRUE/FALSE for timedout/not
 */

extern void __LIB__ __SHARED__ sock_settimeout(SOCKET *s,int time);
extern int  __LIB__ __SHARED__ sock_chktimeout(SOCKET *s);

/*
 * Some routines suitable for daemons
 */

/* Read/write user pointer associated with socket */
extern int __LIB__ __SHARED__ sock_setptr(SOCKET *s, void *ptr);
extern void __LIB__ __SHARED__ *sock_getptr(SOCKET *s);

/* Resize the tcp input queue size - returns the size the buffer is now set to*/
extern int __LIB__ __SHARED__ sock_setrsize(SOCKET *s, int size);

/* Set the UDP socket mode to something */

extern int __LIB__ __SHARED__ sock_setmode(SOCKET *s, int mode);

/* Set the datahandler for a socket (handler is package call) */

extern int __LIB__ __SHARED__ sock_sethandler(SOCKET *s, int call);

/* Wait for a socket to become established, checks for ^C, returns 1
 * on successfull open or 0 on ^C detected 
 */

extern int __LIB__ __SHARED__ sock_waitopen(SOCKET *s);
extern int __LIB__ __SHARED__ sock_waitclose(SOCKET *s);

/*
 * Set the ttl and tos for a socket (defaults are 255 and 0 respectively)
 */

extern void __LIB__ __SHARED__ sock_settos(SOCKET *s,u8_t tos);
extern void __LIB__ __SHARED__ sock_setttl(SOCKET *s,u8_t ttl);


#endif /* _NET_SOCKET_H */
