#pragma once

enum opcodes {
    // Exits program
    op_exit = 0,

    //
    // Pop
    //

    // Removes 1 byte from the stack
    op_pop_byte = 1,

    // Removes 2 bytes from the stack
    op_pop_word = 2,
// Removes 4 bytes from the stack
    op_pop_dword = 3,

    // Removes 8 bytes from the stack
    op_pop_qword = 4,

    //
    // Constant push
    //

    // Push 1 byte constant to the stack
    op_push_byte = 5,

    // Push 2 byte constant to the stack
    op_push_word = 6,

    // Push 4 byte constant to the stack
    op_push_dword = 7,

    // Push 8 byte constant to the stack
    op_push_qword = 8,

    //
    // Pointer push
    //

    // Push 1 byte of the dword length pointer from the stack
    op_push_byte_ptr = 9,

    // Push 2 byte of the dword length pointer from the stack
    op_push_word_ptr = 10,

    // Push 4 byte of the dword length pointer from the stack
    op_push_dword_ptr = 11,

    // Push 8 byte of the dword length pointer from the stack
    op_push_qword_ptr = 12,

    // Push pointer of dword size to the stack
    op_push_ptr = 13,

    //
    // Addition
    //

    // Pops 2 of size from stack adds and pushs to stack
    op_add_byte = 14,
    op_add_word = 15,
    op_add_dword = 16,
    op_add_qword = 17,

    // Pops 2 of size from stack subtracts and pushs to stack
    op_sub_byte = 18,
    op_sub_word = 19,
    op_sub_dword = 20,
    op_sub_qword = 21,

    // Pops 2 of size from stack mulitplies and pushs to stack
    op_mul_byte = 22,
    op_mul_word = 23,
    op_mul_dword = 24,
    op_mul_qword = 25,

    // Pops 2 of size from stack mulitplies and pushs to stack
    op_div_byte = 26,
    op_div_word = 27,
    op_div_dword = 28,
    op_div_qword = 29,

    // Pops qword from stack and pushes qword pointer to stack
    op_alloc = 30,
    // Pops qword address and dword size from stack and deallocates size @ address
    op_dealloc = 31
};
