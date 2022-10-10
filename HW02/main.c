#include <stddef.h>
#include <stdio.h>

#include "stack_HW.h"

char* tests[] = {
    "324*+",
    "24*3+",
    "842-+",
    "814*/",
    NULL,
};

int main(void) {
    for (char** str = tests; *str; ++str) {
        double result = evalPostfix(*str);
        printf("%s -> %f\n", *str, result);
    }
    return 0;
}
