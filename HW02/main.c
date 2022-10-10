#include <stddef.h>
#include <stdio.h>

#include "stack_HW.h"

char* tests[] = {
    "324*+",  // 11
    "24*3+",  // 11
    "842-+",  // 10
    "814*/",  // 2
    "468182++-*+", // -14
    NULL,
};

int main(void) {
    for (char** str = tests; *str; ++str) {
        double result = evalPostfix(*str);
        printf("%s\t%f\n", *str, result);
    }
    return 0;
}
