#include<stdio.h>
#include <stdlib.h>
#include"heap.h"

// Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare the left child with the root
    if (left < n && ((isMaxHeap && arr[left] > arr[largest]) ||
                     (!isMaxHeap && arr[left] < arr[largest])))
        largest = left;

    // Compare the right child with the largest so far
    if (right < n && ((isMaxHeap && arr[right] > arr[largest]) ||
                      (!isMaxHeap && arr[right] < arr[largest])))
        largest = right;

    // If the largest element is not the root, swap them
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, isMaxHeap);
    }
}

// Perform Heap Sort on the given array
void heapSort(int arr[], int n, int isMaxHeap) {
    // Build the initial heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest or smallest) to the end
        swap(&arr[0], &arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0, isMaxHeap);
    }
    printf("\n");
}
