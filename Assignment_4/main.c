#include <stdio.h>
#include <stdlib.h>
#include"heap.h"


int main() {
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int maxNumbers = 1000; // Maximum number of numbers to read
    int numbers[maxNumbers];
    int count = 0;

    // Read numbers from the file
    while (fscanf(file, "%d", &numbers[count]) == 1 && count < maxNumbers)
        count++;

    fclose(file);

    // Sort the numbers in ascending order using Heap Sort
    heapSort(numbers, count, 0);

    printf("Ascending order:\n");
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);

    // Sort the numbers in descending order using Heap Sort
    heapSort(numbers, count, 1);

    printf("\nDescending order:\n");
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);

    printf("\n");
    return 0;
}
