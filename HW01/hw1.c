/*
 * Student: Mikolaj Kuranowski
 * Student ID: 2020427681
 * Date: 2022-09-05
 * Course: Data Structure
 */

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Prints a vector of integers to stdout.
 */
void print_vector(int* vec, size_t vec_size) {
    printf("[ ");
    for (size_t i = 0; i < vec_size; ++i) {
        printf("%d ", vec[i]);
    }
    printf("]\n");
}

/*
 * Swaps 2 integers, so that b contains the value of a,
 * and b contains the value of a.
 *
 * a and b cannot be the same, as indicated
 * by the `restrict` qualifiers.
 */
void swap_ints(int* restrict a, int* restrict b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Sorts a vector of integers using a recursive quick sort implementation.
 */
void sort_integers(int* vec, size_t vec_size) {
    // Recursive implementation of the quick sort algorithm

    if (vec_size <= 1) {
        // Base case for recursion - no elements to compare, so do nothing
    } else if (vec_size == 2) {
        // Fast path for comparing just two elements
        if (vec[1] < vec[0]) swap_ints(vec, vec + 1);
    } else {
        // Actually perform the quick sort

        // Find a pivot element
        int pivot = vec[vec_size / 2];

        // Swap elements into 2 spans,
        // until the span from start to right contains elements <= pivot,
        // and the span from left to end contains elements >= pivot.
        int* start = vec;
        int* end = vec + vec_size - 1;
        int* left = start;
        int* right = end;

        while (left <= right) {
            // Find the leftmost element to swap
            while (left <= end && *left < pivot) ++left;

            // Find the rightmost element to swap
            while (right >= start && *right > pivot) --right;

            // Don't swap if the pointers have passed each other
            // (which means that no elements to swap were found)
            if (left > right) break;

            // Swap elements and advance pointers
            if (left != right) swap_ints(left, right);
            ++left;
            --right;
        }

        assert(left > right);
        assert(left <= end);
        assert(right >= start);

        // Recursively call quick sort on the sub-lists
        if (right > start) sort_integers(start, right - start + 1);

        if (left < end) sort_integers(left, end - left + 1);
    }
}

/*
 * Calculates the P-norm over a vector of integers.
 *
 * The P-norm is the p-th root of the sum of the
 * absolute values of elements raised to the p-th power.
 */
double calculate_p_norm(int* vec, size_t vec_size, int p) {
    // Accumulate the sum of absolute values of elements,
    // raised to the p-th power
    double sum = 0.0;
    for (size_t i = 0; i < vec_size; ++i) {
        // Accumulate |v[i]|^p
        sum += pow((double)abs(vec[i]), (double)p);
    }

    // Calculate the p-th root of the sum
    return pow(sum, 1.0 / (double)p);
}

/*
 * Takes a sorted vector of integers and returns the median.
 */
double find_median(int* vec, size_t vec_size) {
    // The index of the middle element
    size_t middle = vec_size / 2;

    // Return the middle element if vector size is odd,
    // or the average of the 2 middle values if vector size is even.
    return vec_size % 2 ? (double)vec[middle] : (double)(vec[middle] + vec[middle - 1]) * 0.5;
}

/*
 * The entry point to the program
 */
int main(void) {
    // Feed the random number generator
    srand(time(NULL));

    // Generate a vector of 10 random integers in range <-10, 10>
    int numbers[10];
    for (size_t i = 0; i < 10; ++i) {
        numbers[i] = (rand() % 21) - 10;
    }

    // Print the result of the 1st part
    puts("1-1) The vector with 10 random integers is:");
    print_vector(numbers, 10);

    // Sort the vector and print the result afterwards
    sort_integers(numbers, 10);
    puts("1-2) The vector after sorting is:");
    print_vector(numbers, 10);

    // Calculate the p-norm
    puts("1-3) Calculation of p-norm:");

    // Ask the user for the `p`
    printf("Enter an integer for p-norm: ");
    int p = 1;
    scanf("%d", &p);

    // Calculate and print the result
    printf("%d-norm of vector is: %f\n", p, calculate_p_norm(numbers, 10, p));

    // Calculate the median and print it
    puts("1-4) Calculation of median:");
    printf("median value is %f\n", find_median(numbers, 10));

    return 0;
}
