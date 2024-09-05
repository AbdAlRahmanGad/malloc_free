#include <stdio.h>
#include <sys/mman.h>
//#include <sys/resource.h>
//#include <unistd.h>
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

//long page_size = sysconf(_SC_PAGE_SIZE);
//long y =  sysconf(_SC_PAGESIZE);
//printf(" %ui", (int)page_size);
//printf(" %ld", y);
////printf(" %ii", x);


         int ret = mem_init(4096 * 10, p_firstfit);
         if (ret == -1) {
             printf("Fail");
             return -1;
         }
         int *x = (int *) mem_alloc(sizeof (int));
         *x = 10;
         printf("%d ", *x);
         printf("\n%08x", x);

         int *t = (int *) mem_alloc(sizeof (int));
         *t = 10;

         printf("\n%d ", *t);

         printf("\n%08x", t);

         char *ptr = (char *) mem_alloc(sizeof (char));
            *ptr = 'a';
            printf("\n%c", *ptr);
            printf("\n%08x", ptr);

        return 0;
//    return mem_init(getpagesize()*2, 0);
}
