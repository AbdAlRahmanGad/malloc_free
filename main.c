#include <stdio.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <unistd.h>
#include "mem.h"
//void *
//mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

void *
malloc(size_t size){
    int *ptr;
 return ptr;
}
void
free(void *ptr){
    if (ptr == NULL) return;

};

//sbrk or mmap
int main(void) {
//    struct rlimit v;
//    v.rlim_cur = 2;
//    printf((char const *) v.rlim_max);
//    v.rlim_max = 4;
//    struct rlimit* b = &v;
//    printf("Hello, World!\n");
//    int *x = malloc(sizeof (int));
//    getrlimit(RLIMIT
    //    _DATA, &v);
//    printf ("\nStack Limit = %ld and %ld max\n", v.rlim_cur, v.rlim_max);

//    printf(" %i",getpagesize());
//
//    struct rlimit limit;
//
//    getrlimit (RLIMIT_STACK, &limit);
//    printf ("\nStack Limit = %ld and %ld max\n", limit.rlim_cur, limit.rlim_max);
    return mem_init(getpagesize()*2, 0);
}
