#include <stdlib.h>

#include "logging/logger.h"
#include "memory/heap.h"
#include "vm/execution.h"

void print_exit() {
    log_info("Exiting");
}

int main() {
    log_info("Starting");
    atexit(print_exit);

    init_heap();

    execute();
    
    close_heap();

    return 0;
}
