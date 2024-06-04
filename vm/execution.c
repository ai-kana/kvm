#include <stdio.h>
#include <stdlib.h>

#include "execution.h"
#include "interupts.h"

#include "../stack/stack.h"
#include "../arithmetic/add.h"
#include "../arithmetic/sub.h"
#include "../arithmetic/div.h"
#include "../arithmetic/mul.h"

#include "../memory/allocation.h"
#include "opcodes.h"

#define data_stack_size 512
#define text_stack_size 512

unsigned char* data_stack;
unsigned int data_stack_ptr = 0;

unsigned char* text_stack;
unsigned int text_stack_ptr = 0;

unsigned int interupt = 0;

void exit_op() {
    interupt = int_exit;
}

int exit_handler() {
    exit(0);
}

int abort_handler() {
    abort();
}

// Needs to align with 'enum opcodes'
// Array because of O(1) time lookup
// Instructions need to be handled as void(void) using global state
void (*opcode_handler[])(void) = {
    exit_op, // 0

    //
    // Pop ops
    //
    pop_byte, // 1
    pop_word, // 2
    pop_dword, // 3
    pop_qword, // 4

    //
    // Push ops
    //
    push_byte, // 5
    push_word, // 6
    push_dword, // 7
    push_qword, // 8

    // Reserved for Pointer ops
    NULL, // 9
    NULL, // 10
    NULL, // 11
    NULL, // 12
    NULL, // 13
          
    add_byte, // 14
    add_word, // 15
    add_dword, // 16
    add_qword, // 17
    
    sub_byte, // 18
    sub_word, // 19
    sub_dword, // 20
    sub_qword, // 21
    
    mul_byte, // 22
    mul_word, // 23
    mul_dword, // 24
    mul_qword, // 25

    div_byte, // 26
    div_word, // 27
    div_dword, // 28
    div_qword, // 29
    
    alloc, // 30
    dealloc, // 31
};

int (*interupt_handler[])(void) = {
    NULL,
    abort_handler,
    exit_handler,
};

int execute() {
    // Following sections create dangling pointers
    // on purpose to ensure stack allocated memory

    // section .data
    // Holds stack allocated variables
    unsigned char private_data_stack[data_stack_size];
    data_stack = private_data_stack;

    // section .text
    // Holds current code segment
    unsigned char private_text_stack[text_stack_size] = {op_exit};
    text_stack = private_text_stack;

    while (1) {
        interupt != 0 && interupt_handler[interupt]() ;
        opcode_handler[text_stack[text_stack_ptr]]();
    }
}
