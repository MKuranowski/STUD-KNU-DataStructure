/*
 * Student: Mikolaj Kuranowski
 * Student ID: 2020427681
 * Date: 2022-12-05
 * Course: Data Structure
 */

#include "heap.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

static inline void swap_ints(int* restrict a, int* restrict b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

Heap* heapCreate(int maxSize) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->maxSize = maxSize;
    heap->heapArray = (int*)calloc(heap->maxSize, sizeof(int));
    return heap;
}

void heapInsert(Heap* heap, int new_element) {
    // Ensure heap capacity is not exceeded
    assert(heap->size < heap->maxSize);

    // Insert new element at the end
    heap->heapArray[heap->size++] = new_element;
    reheapUp(heap, heap->size - 1);
}

void reheapUp(Heap* heap, int index) {
    // Ensure index is within heap bounds
    assert(index < heap->size);

    // Calculate the parent index
    int parent = (index - 1) / 2;

    // Loop until heap order is restored
    while (index > 0 && heap->heapArray[parent] > heap->heapArray[index]) {
        // Parent is bigger - swap
        swap_ints(heap->heapArray + parent, heap->heapArray + index);

        // Continue checking on the higher level
        index = parent;
        parent = (index - 1) / 2;
    }
}

int heapDelete(Heap* heap) {
    // Ensure there's an element to delete
    assert(heap->size > 0);

    // Fast path for single-element heaps
    if (heap->size == 1) return heap->heapArray[heap->size--];

    // Swap the root with last element
    swap_ints(heap->heapArray, heap->heapArray + --heap->size);

    // Restore heap invariant
    reheapDown(heap, 0);

    // Return the element that was popped
    return heap->heapArray[heap->size];
}

void reheapDown(Heap* heap, int index) {
    // Loop until heap order is restored
    bool did_swap = false;
    do {
        // Ensure index is within heap bounds
        assert(index < heap->size);

        // Check whether `index` is smaller then its children
        int smallest = index;
        int left = 2*index + 1;
        int right = left + 1;

        // Check if left child exists and is smaller
        if (left < heap->size && heap->heapArray[left] < heap->heapArray[smallest])
            smallest = left;

        // Check if right child exists and is smaller
        if (right < heap->size && heap->heapArray[right] < heap->heapArray[smallest])
            smallest = right;

        // If `index` isn't smallest - swap and continue checking on the level below
        if (index != smallest) {
            swap_ints(heap->heapArray + index, heap->heapArray + smallest);
            index = smallest;
            did_swap = true;
        } else {
            // Index is smallest - heap order is restored; stop looping
            did_swap = false;
        }
    } while (did_swap);
}
