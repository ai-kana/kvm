#pragma once

// Pops qword off of stack and allocates amount
void alloc();

// Pops qword - address
//
// Pops dword - size
void dealloc();
