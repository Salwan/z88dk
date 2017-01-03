
// automatically generated by m4 from headers in proto subdir


#ifndef _ALLOC_BALLOC_H
#define _ALLOC_BALLOC_H

#include <stddef.h>

extern void *balloc_addmem(int q,size_t num,size_t size,void *p);


extern void *balloc_alloc(int q);


extern size_t balloc_blockcount(int q);


extern void *balloc_firstfit(int q,int numq);


extern void balloc_free(void *p);



#endif