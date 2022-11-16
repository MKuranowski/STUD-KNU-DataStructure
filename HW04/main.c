/*
 * Student: Mikolaj Kuranowski
 * Student ID: 2020427681
 * Date: 2022-11-16
 * Course: Data Structure
 */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generalList2.h"

// sort_rule, as given on the slides. Solves part 1.
int sort_rule(Element a, Element b) {
    // PLEASE USE STANDARD NOTATION FOR "SORT" FUNCTIONS!
    // The convention in C for comparison functions is to return
    // - zero if `a == b`
    // - any negative number if `a < b`
    // - any positive number if `a > b`
    //
    // See:
    // - https://en.cppreference.com/w/c/algorithm/qsort
    // - https://en.cppreference.com/w/c/string/byte/strcmp
    // - https://en.cppreference.com/w/c/string/byte/memcmp
    //
    // The usage of this function doesn't follow the convention.
    // It makes the code unreadable and hard to write.

    // NOTE: according to `insertionbyRule` this function:
    // - must return non-zero if `a > b`
    // - must return zero if `a <= b`
    return a->x == b->x ? a->y > b->y : a->x > b->x;
}

// rand_float returns a random float in the range [0, 10] with (roughly) 1 digit precision
float rand_float_from_zero_to_ten(void) { return (float)(rand() % 100) / 10.0f; }

// print_list prints every element in the list to the provided file.
// Every entry is separated by a newline.
void print_list(Lhead* list, FILE* sink) {
    Lnode* node = list->front->link;
    while (node) {
        fprintf(sink, "%f %f\n", node->data->x, node->data->y);
        node = node->link;
    }
}

int main() {
    // Create the list and set its sorting function
    Lhead* plist = createList();
    setSortRule(plist, sort_rule);

    // Create 10 random points and insert them into the list
    Point pts[10];
    for (size_t i = 0; i < 10; ++i) {
        // (2) Initialize the point
        pts[i] = (Point){.x = rand_float_from_zero_to_ten(), .y = rand_float_from_zero_to_ten()};

        // (3) Insert it into the list
        insertionbyRule(plist, pts + i);
    }

    // (4) Print the list
    print_list(plist, stdout);

    // Deallocate the list and exit the program
    destroyList(plist);
    return 0;
}
