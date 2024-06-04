#include "sub.h"
#include "../stack/stack.h"
#include "../vm/execution.h"

void sub_byte() {
    unsigned char result = pop_top() - pop_top();

    push_top(result);

    text_stack_ptr++;
}

void sub_word() {
    unsigned short word = (pop_top() | (pop_top() << 8)) - (pop_top() | (pop_top() << 8));

    push_top((word >> 8));
    push_top(word);

    text_stack_ptr++;
}

void sub_dword() {
    unsigned int dword = (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24)) - (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24));

    push_top(dword >> 24);
    push_top(dword >> 16);
    push_top(dword >> 8);
    push_top(dword);

    text_stack_ptr++;
}

void sub_qword() {
    unsigned long qword = 
        (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24) 
        | ((unsigned long)pop_top() << 32) | ((unsigned long)pop_top() << 40) | ((unsigned long)pop_top() << 48) | ((unsigned long)pop_top() << 56))
        - 
        (pop_top() | (pop_top() << 8) | (pop_top() << 16) | (pop_top() << 24) 
        | ((unsigned long)pop_top() << 32) | ((unsigned long)pop_top() << 40) | ((unsigned long)pop_top() << 48) | ((unsigned long)pop_top() << 56));

    push_top(qword >> 56);
    push_top(qword >> 48);
    push_top(qword >> 40);
    push_top(qword >> 32);

    push_top(qword >> 24);
    push_top(qword >> 16);
    push_top(qword >> 8);
    push_top(qword);

    text_stack_ptr++;
}
