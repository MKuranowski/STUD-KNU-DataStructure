#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void heapSort(int* arr, int size) {
    // 2) fill this part
    // pre : unordered array arr is delivered, and its length is size
    // post : array arr should have elements in increasing order
}

int main() {
    int arr[10] = {1, 3, 2, 5, 7, 10, 8, 4, 6, 9};
    heapSort(arr, 10);
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
}
