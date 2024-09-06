#include "mem.h"
#include <fcntl.h>
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct __node {
    size_t size;
    size_t number;
    struct __node *next;
} node;

typedef struct __header {
    size_t size;
    size_t listNumber;
} header;

int POLICY;
node *head;

int mem_init(int region_size, int policy) {
    if (region_size < 1 || policy < 1 || policy > 3) {
        return -1;
    }
    POLICY = policy;

    int fd = open("/dev/zero", O_RDWR);

    head = mmap(NULL, region_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (head == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    head->size = region_size - sizeof(node);
    head->number = 1;
    head->next = NULL;

    close(fd);
    return 0;
}
void *mem_alloc(int size) {

    if (POLICY == p_firstfit) {
        node *tempNode = head;
        /// padding for performance
        if (size % 4 != 0) {
            size = size + (4 - size % 4);
        }

        uint32_t newNodeSize = size + sizeof(header);

        while (tempNode) {
            if (tempNode->size >= newNodeSize) {
                /// implement the new node

                char *pointer = ((char *) tempNode + sizeof(node));
                header *header1 = (header *) pointer;
                *header1 = (header){
                        .size = size,
                        .listNumber = tempNode->number,
                };
                pointer += sizeof(header);
                if (tempNode->size > newNodeSize + sizeof(node)) {
                    /// new free node
                    int newFreeSize = tempNode->size - newNodeSize - sizeof(node);
                    node *newNode = (node *) ((char *) tempNode + sizeof(node) + newNodeSize);

                    newNode->number = tempNode->number + 1;
                    newNode->next = tempNode->next;
                    newNode->size = newFreeSize;

                    tempNode->next = newNode;
                    tempNode->size = 0;
                } else {
                    tempNode->size = 0;
                }
                return pointer;
            }
            tempNode = tempNode->next;
            if (tempNode == NULL) {
                return NULL;
            }
        }
    }

    return NULL;
}
int mem_free(void *ptr) {
    if (ptr == NULL)
        return -1;

    char *pointer = ptr;
    pointer -= sizeof(header);
    header *header1 = (header *) pointer;
    int size_ = header1->size;

    /// increase the free space size from the free space header
    node *tempNode = head;

    while (tempNode) {
        if (tempNode->number == header1->listNumber) {
            tempNode->size += size_ + sizeof(header);
            break;
        }
        tempNode = tempNode->next;
    }

    /// Free the memory block pointed by ptr
    memset(pointer, 0, header1->size + sizeof(header));
    /// Coalesce the free space
    tempNode = head;
    node *nodeNext;
    while (tempNode) {
        if (tempNode->next != NULL) {
            nodeNext = tempNode->next;
            if (tempNode->size != 0 && nodeNext->size != 0) {
                tempNode->size += nodeNext->size + sizeof(node);
                tempNode->next = nodeNext->next;
                memset(nodeNext, 0, sizeof(node));
            } else {
                tempNode = tempNode->next;
            }
        } else {
            break;
        }
    }

    return 0;
}
