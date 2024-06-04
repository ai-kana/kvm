#include "allocation.h"
#include "../stack/stack.h"
#include "../vm/execution.h"
#include "heap.h"

void alloc() {
    unsigned long size = 
        (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24) 
        | ((unsigned long)pop_top() << 32) | ((unsigned long)pop_top() << 40) | ((unsigned long)pop_top() << 48) | ((unsigned long)pop_top() << 56));

    unsigned long address = allocate(size);

    push_top(size >> 56);
    push_top(size >> 48);
    push_top(size >> 40);
    push_top(size >> 32);

    push_top(size >> 24);
    push_top(size >> 16);
    push_top(size >> 8);
    push_top(size);

    text_stack_ptr++;
}

void dealloc() {
    unsigned long address = 
        (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24) 
        | ((unsigned long)pop_top() << 32) | ((unsigned long)pop_top() << 40) | ((unsigned long)pop_top() << 48) | ((unsigned long)pop_top() << 56));

    unsigned int size = (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24)) - (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24));

    deallocate(address, size);
}
