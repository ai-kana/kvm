#pragma once

void init_heap();

void close_heap();

unsigned long allocate(unsigned int size);
void deallocate(unsigned long address, unsigned int size);
