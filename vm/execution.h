#pragma once

extern unsigned char* data_stack;
extern unsigned int data_stack_ptr;

extern unsigned char* text_stack;
extern unsigned int text_stack_ptr;

extern unsigned int interupt;

int execute();
