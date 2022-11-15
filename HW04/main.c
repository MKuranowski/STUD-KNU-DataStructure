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

// create_random_point allocates new Point and fills its coordinates
// with random values from rand_float_from_zero_to_ten.
Element create_random_point(void) {
    Element pt = malloc(sizeof(Point));
    *pt = (Point){.x = rand_float_from_zero_to_ten(), .y = rand_float_from_zero_to_ten()};
    return pt;
}

// initialize_list_with_10_points creates 10 random points
// and inserts them into the provided list with `insertionbyRule`.
// Solves parts 2 and 3.
void initialize_list_with_10_points(Lhead* list) {
    for (size_t i = 0; i < 10; ++i) {
        // Create a new point and insert it into the list, maintaining the order
        insertionbyRule(list, create_random_point());
    }
}

// print_list prints every element in the list to the provided file.
// Every entry is separated by a newline.
// Solves part 4.
void print_list(Lhead* list, FILE* sink) {
    Lnode* node = list->front->link;
    while (node) {
        fprintf(sink, "%f %f\n", node->data->x, node->data->y);
        node = node->link;
    }
}

int main() {
    Lhead* plist = createList();
    setSortRule(plist, sort_rule);

    initialize_list_with_10_points(plist);

    print_list(plist, stdout);

    destroyList(plist);
    return 0;
}
