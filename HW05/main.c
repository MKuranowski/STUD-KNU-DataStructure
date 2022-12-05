#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void reverseArray(int* arr, int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;

        ++left;
        --right;
    }
}

void heapSort(int* arr, int size) {
    // Create a heap over the provided array
    Heap heap = {
        .heapArray = arr,
        .size = 0,
        .maxSize = size,
    };

    // Initialize the heap
    for (int i = 0; i < size; ++i) heapInsert(&heap, arr[i]);

    // Move smallest elements from the heap to the right of the array
    while (heap.size) heapDelete(&heap);

    // Reverse the array to get increasing order.
    // Min-heap based heapsort reorders elements in decreasing order.
    reverseArray(arr, size);
}

int main(void) {
    int arr[10] = {1, 3, 2, 5, 7, 10, 8, 4, 6, 9};
    heapSort(arr, 10);
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
    putc('\n', stdout);
    return 0;
}
