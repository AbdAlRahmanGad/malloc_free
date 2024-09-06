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
        mem_free(ptr);
    }
}

void test_coalesce() {
    int *x = (int *) mem_alloc(sizeof(int));
    *x = 10;
    printf("x:\n");
    print_pointer_int_value(x);
    print_pointer_address(x);

    int *y = (int *) mem_alloc(sizeof(int));
    *y = 20;
    printf("y:\n");
    print_pointer_int_value(y);
    print_pointer_address(y);

    mem_free(x);
    x = NULL;
    printf("Free x:\n");
    print_pointer_address(x);

    mem_free(y);
    y = NULL;
    printf("Free y:\n");
    print_pointer_address(y);

    int *z = (int *) mem_alloc(sizeof(int));
    *z = 30;
    printf("z:\n");
    print_pointer_int_value(z);
    print_pointer_address(z);
}

void test_coalesce2() {

    char *ptr1 = (char *) mem_alloc(sizeof(char));
    *ptr1 = 'a';
    printf("ptr1:\n");
    print_pointer_char_value(ptr1);
    print_pointer_address(ptr1);

    char *ptr2 = (char *) mem_alloc(sizeof(char));
    *ptr2 = 'b';
    printf("ptr2:\n");
    print_pointer_char_value(ptr2);
    print_pointer_address(ptr2);

    char *ptr3 = (char *) mem_alloc(sizeof(char));
    *ptr3 = 'c';
    printf("ptr3:\n");
    print_pointer_char_value(ptr3);
    print_pointer_address(ptr3);

    mem_free(ptr1);
    ptr1 = NULL;
    printf("Free ptr1:\n");
    print_pointer_address(ptr1);

    mem_free(ptr2);
    ptr2 = NULL;
    printf("Free ptr2:\n");
    print_pointer_address(ptr2);

    test_struct *struct_var = (test_struct *) mem_alloc(sizeof(test_struct));
    struct_var->a = 10;
    struct_var->b = 'a';
    printf("struct after two free of char:\n");
    print_pointer_int_value(&struct_var->a);
    print_pointer_char_value(&struct_var->b);
    print_pointer_address(struct_var);

    int *ptr4 = (int *) mem_alloc(sizeof(int));
    *ptr4 = 10;
    printf("ptr4:\n");
    print_pointer_int_value(ptr4);
    print_pointer_address(ptr4);

    int *ptr5 = (int *) mem_alloc(sizeof(int));
    *ptr5 = 20;
    printf("ptr5:\n");
    print_pointer_int_value(ptr5);
    print_pointer_address(ptr5);

    mem_free(ptr3);
    ptr3 = NULL;
    printf("Free ptr3:\n");
    print_pointer_address(ptr3);

    mem_free(ptr4);
    ptr4 = NULL;
    printf("Free ptr4:\n");
    print_pointer_address(ptr4);

    mem_free(ptr5);
    ptr5 = NULL;
    printf("Free ptr5:\n");
    print_pointer_address(ptr5);
}

int main(void) {

    long page_size = sysconf(_SC_PAGE_SIZE);

    /// TODO add more checks for the code

    int ret = mem_init((int) page_size * 10, p_firstfit);

    if (ret == -1) {
        printf("Fail");
        return -1;
    }
    test_coalesce();
    test_coalesce2();
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
