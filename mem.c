#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "mem.h"

typedef struct __node{
        size_t size;
        struct __node *next;
    } node;

    int POLICY;
    node* head;
//16384
int mem_init(int region_size, int policy){
        POLICY = policy;

        int fd = open("/dev/zero", O_RDWR);

        head = mmap(NULL, region_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
        if (head == MAP_FAILED){
            perror("mmap");
            return -1;
        }

        head->size = region_size - sizeof(node);
        head->next = NULL;

        close(fd);
        return 0;
}
void *mem_alloc(int size){
    // if p_bestfit         == or =>    equal or the smallest bigger than
    // 1 traverse all the whole list
    if (POLICY == p_bestfit){
        node* tempNode = head;
        while(tempNode->next != NULL ){

        }
    }

    // if p_first         first
    if (POLICY == p_firstfit){
        node* tempNode = head;
        while(tempNode->next != NULL ){
            if(tempNode->size >= size + sizeof (node)){
                printf("%p", tempNode); // & or &* do not remeber try it
                printf("%p", tempNode + sizeof(node)); // this is where we are going to place the new node
                u_int32_t newNodeSize = size + sizeof (node);
                node* newNode = tempNode + sizeof(node);
                newNode->size = tempNode->size - newNodeSize;
                if(tempNode->next == NULL)
                    newNode->next = NULL;
                else
                    newNode->next = tempNode->next;


                tempNode->size = newNodeSize;
                tempNode->next = newNode;

                return tempNode;
            }
        }
    }

    // if p_worstfit         the biggest
    // 1 traverse all the whole list
    if (POLICY == p_worstfit){
        node* tempNode = head;
        while(tempNode->next != NULL ){

        }
    }


}
int mem_free(void *ptr){

}
void mem_dump(){

}
