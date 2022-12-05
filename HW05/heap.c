#include "heap.h"

#include <stdlib.h>

Heap* heapCreate(int maxSize) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->last = -1;
    heap->size = 0;
    heap->maxSize = maxSize;
    heap->heapArray = (int*)calloc(heap->maxSize, sizeof(int));
    return heap;
}

void heapInsert(Heap* heap, int D1) {
    // 1) fill this part
}

void reheapUp(Heap* heap, int targetIdx) {
    // 1) fill this part
}

int heapDelete(Heap* heap) {
    // 1) fill this part
}

void reheapDown(Heap* heap, int root) {
    // 1) fill this part
}
