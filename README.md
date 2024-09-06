# Custom Memory Allocator

This project implements a custom memory allocator in C, providing functions for memory initialization, allocation, and deallocation.

## Files

- `main.c`: Contains the main function and test cases for the memory allocator.
- `mem.c`: Implements the memory allocation functions.
- `mem.h`: Header file for the memory allocator.

## Features

- Custom memory initialization with configurable region size.
- Memory allocation using first-fit algorithm.
- Memory deallocation with automatic coalescing of free blocks to prevent fragmentation.

## Function Descriptions

- `mem_init(int region_size, int policy)`: Initialize the memory region.
- `mem_alloc(int size)`: Allocate memory of specified size.
- `mem_free(void *ptr)`: Free allocated memory.