#include "mem.h"
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct __test_struct {
        int a;
        char b;
    } test_struct;

void print_pointer_address(void *ptr) {
    printf("address: \t%08x", (unsigned int) ptr);
    printf("\n");
}

void print_pointer_int_value(void *ptr) {
    int *p = (int *) ptr;
    printf("value: \t\t%d", *p);
    printf("\n");
}

void print_pointer_char_value(void *ptr) {
    char *p = (char *) ptr;
    printf("value: \t\t%c", *p);
    printf("\n");
}

void test_for_loop() {
    char *ptr = (char *) mem_alloc(sizeof(char));
    for (int i = 0; i < 200; ++i) {
        ptr = (char *) mem_alloc(sizeof(char));
        *ptr = 'a';
        printf("ptr:\n");
        print_pointer_char_value(ptr);
        print_pointer_address(ptr);
        mem_free(ptr); /// comment for different test
    }
}
int main(void) {

    long page_size = sysconf(_SC_PAGE_SIZE);

    /// TODO add more tests

    /// TODO clean the code

    /// TODO add more checks for the code

    int ret = mem_init((int) page_size * 10, p_firstfit);

    if (ret == -1) {
        printf("Fail");
        return -1;
    }
    int *x = (int *) mem_alloc(sizeof(int));
    if (x == NULL) {
        printf("mem_alloc failed\n");
        return -1;
    }
    *x = 10;
    printf("x:\n");
    print_pointer_int_value(x);
    print_pointer_address(x);

    mem_free(x);
    x = NULL;

    printf("Free x:\n");
    print_pointer_address(x);

    char *rrr = (char *) mem_alloc(sizeof(char));
    *rrr = 'f';
    printf("rrr:\n");
    print_pointer_address(rrr);
    print_pointer_char_value(rrr);
    int *t = (int *) mem_alloc(sizeof(int));
    if (t == NULL) {
        printf("mem_alloc failed\n");
        return -1;
    }
    *t = 30;

    printf("t:\n");
    print_pointer_int_value(t);
    print_pointer_address(t);

    test_for_loop();

    test_struct* struct_var = (test_struct *) mem_alloc(sizeof(test_struct));
    if (struct_var == NULL) {
        printf("mem_alloc failed\n");
        return -1;
    }
    struct_var->a = 10;
    struct_var->b = 'a';
    printf("x:\n");
    print_pointer_int_value(&struct_var->a);
    print_pointer_char_value(&struct_var->b);
    print_pointer_address(struct_var);

    return 0;
}
