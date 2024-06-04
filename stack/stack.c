#include "../vm/execution.h"
#include <stdio.h>
#include "stack.h"

static inline void pop_stack(unsigned int size_bytes) {
    text_stack_ptr++;

    if (data_stack_ptr == 0)
        return;

    for (unsigned int i = 0; i < size_bytes && data_stack_ptr != 0; i++) {
        data_stack[data_stack_ptr] = 0;
        data_stack_ptr--;
    }

    return;
}

static inline void push_stack(unsigned int size_bytes) {
    text_stack_ptr++;

    data_stack_ptr++;
    for (unsigned int i = 0; i < size_bytes; i++) {
        data_stack[data_stack_ptr] = text_stack[text_stack_ptr];

        text_stack_ptr++;
        if (i != size_bytes - 1)
            data_stack_ptr++;
    }
} 

void push_top(unsigned char byte) {
    data_stack_ptr++;
    data_stack[data_stack_ptr] = byte;
}

unsigned char pop_top() {
    unsigned char out = data_stack[data_stack_ptr];
    data_stack_ptr--;
    return out;
}

// Used as pointers do not inline
void push_byte() {
    push_stack(sizeof(unsigned char));
}

void push_word() {
    push_stack(sizeof(unsigned short));
}

void push_dword() {
    push_stack(sizeof(unsigned int));
}

void push_qword() {
    push_stack(sizeof(unsigned long));
}

void pop_byte() {
    pop_stack(sizeof(unsigned char));
}

void pop_word() {
    pop_stack(sizeof(unsigned short));
}

void pop_dword() {
    pop_stack(sizeof(unsigned int));
}

void pop_qword() {
    pop_stack(sizeof(unsigned long));
}
