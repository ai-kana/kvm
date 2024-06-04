#include "logger.h"
#include <stdio.h>

#define red "\x1b[31m"
#define green "\x1b[32m"
#define reset "\x1b[0m"

void log_info(char* text) {
    printf("[" green "INFO" reset "] ~ %s\n", text);
}

void log_error(char* text) {
    printf("[" red "ERROR" reset "] ~ %s\n", text);
}
