#ifndef __mem_h__
#define __mem_h__

#define p_bestfit  (1)
#define p_worstfit (2)
#define p_firstfit (3)

int mem_init(int region_size, int policy);
void *mem_alloc(int size);
int mem_free(void *ptr);
void mem_dump();


#endif // __mem_h__

