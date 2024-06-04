#include <stdio.h>

#include "logging/logger.h"
#include "memory/heap.h"
#include "vm/execution.h"

int main() {
    log_info("Starting");

    init_heap();

    execute();
    
    close_heap();

    log_info("Exiting");
    return 0;
}
