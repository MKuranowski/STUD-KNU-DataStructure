#pragma once

typedef struct heapElement {
    int* heapArray;
    int last;
    int size;
    int maxSize;
} Heap;

Heap* heapCreate(int maxSize);
void heapInsert(Heap* heap, int D1);
int heapDelete(Heap* heap);
void reheapUp(Heap* heap, int targetIndex);
void reheapDown(Heap* heap, int targetIndex);
