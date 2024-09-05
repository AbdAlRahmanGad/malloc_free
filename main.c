#include <stdio.h>
#include <sys/mman.h>
//#include <sys/resource.h>
//#include <unistd.h>
#include "mem.h"
//void *
//mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

//sbrk or mmap
int main(void) {

//long page_size = sysconf(_SC_PAGE_SIZE);
//long y =  sysconf(_SC_PAGESIZE);
//printf(" %ui", (int)page_size);
//printf(" %ld", y);
////printf(" %ii", x);

/// TODO add more tests

/// TODO format the code with clang-format

/// TODO clean the code

/// TODO add more checks for the code

         int ret = mem_init(4096, p_firstfit);
         if (ret == -1) {
             printf("Fail");
             return -1;
         }
         int *x = (int *) mem_alloc(sizeof (int));
         if (x == NULL) {
    printf("mem_alloc failed\n");
    return -1;
}
         *x = 10;


         printf("%d ", *x);
         printf("\n%p", (void*)x);

         mem_free(x);
         x = NULL;

//         printf("\n%d ", *x);
//         printf("\n%p", (void*)x);

//         char *rrr = (char *) mem_alloc(sizeof (char));
//         *rrr = 'f';
//         printf("\n%c", *rrr);
//         printf("\n%08x", rrr);

         int *t = (int *) mem_alloc(sizeof (int));
         if (t == NULL) {
    printf("mem_alloc failed\n");
    return -1;
}
         *t = 30;

//         printf("\n%d ", *t);

//         printf("\n%p", (void*)t);

         char *ptr = (char *) mem_alloc(sizeof (char));

         if (ptr == NULL) {
    printf("mem_alloc failed\n");
    return -1;
}

            *ptr = 'a';
           printf("\n%c", *ptr);
           printf("\n%p", (void*)ptr);


//           mem_free(x);


              mem_free(t);
           mem_free(ptr);
           t = NULL;
           ptr = NULL;

        return 0;
//    return mem_init(getpagesize()*2, 0);
}
