#include <stdlib.h>

#include "heap.h"
#include "../logging/logger.h"

struct free_block {
    unsigned int address;
    unsigned int size;

    struct free_block* next;
    struct free_block* last;
};

#define initial_size 512
static unsigned char* memory;
static unsigned long memory_size = initial_size;

static struct free_block* free_blocks;

static unsigned long resize_memory(unsigned int size) {
    memory = realloc(memory, size);
    memory_size += size;
    return memory_size - size;
}

static void merge_item(struct free_block* block) {
    struct free_block* current = free_blocks;
    unsigned long address_sum = block->address + block->size;
    while (current != NULL) {
        if (current == block) {
            current = current->next;
            continue;
        }

        if (address_sum >= current->address) {
            block->size = block->size + current->size;
            if (current->next != NULL)
                current->next->last = current->last;
            if (current->last != NULL)
                current->last->next = current->next;

            struct free_block* old = current;
            current = current->next;
            free(old);
            continue;
        }

        current = current->next;
    }
}

static void clean_list() {
    struct free_block* current = free_blocks;
    while (current != NULL) {
        merge_item(current);
        current = current->next;
    }
}

unsigned long allocate(unsigned int size) {
    if (free_blocks == NULL)
        return resize_memory(size);

    struct free_block* current = free_blocks;
    while (current != NULL) {
        if (current->size >= size)
            break;

        current = current->next;
    }

    if (current == NULL)
        return resize_memory(size);

    if (current->size == size) {
        if (current->next != NULL)
            current->next->last = current->last;
        if (current->last != NULL)
            current->last->next = current->next;

        unsigned int address = current->address;
        free(current);
        return address;
    }

    if (current->size > size) {
        unsigned int address = current->address;
        current->address = address + size;
        current->size = current->size - size;
        return address;
    }

    return 0;
}

void deallocate(unsigned long address, unsigned int size) {
    struct free_block* new_block = (struct free_block*)malloc(sizeof(struct free_block));
    new_block->address = address;
    new_block->size = size;

    struct free_block* current = free_blocks;
    while (current != NULL && (current = current->next) != NULL);

    new_block->next = NULL;
    new_block->last = current;

    clean_list();
}

void init_heap() {
    memory = (unsigned char*)malloc(initial_size);
    free_blocks = (struct free_block*)malloc(sizeof(struct free_block));
    free_blocks->last = NULL;
    free_blocks->next = NULL;
    free_blocks->address = 0;
    free_blocks->size = initial_size;
}

void close_heap() {
    free(memory);
    free(free_blocks);
}
