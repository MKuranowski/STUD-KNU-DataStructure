#pragma once

typedef struct heapElement {
    int* heapArray;
    int size;
    int maxSize;
} Heap;

Heap* heapCreate(int maxSize);
void heapInsert(Heap* heap, int new_element);
int heapDelete(Heap* heap);
void reheapUp(Heap* heap, int index);
void reheapDown(Heap* heap, int index);
