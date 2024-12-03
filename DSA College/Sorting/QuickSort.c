#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function implementing Hoare's partition scheme
int partition(int arr[], int start, int end) {
    int pivot = arr[start]; // Selecting the pivot as the first element
    int i = start;          // Initialize pointer i at the start
    int j = end;            // Initialize pointer j at the end

    // Loop until i and j cross each other
    while (i < j) {
        // Move i to the right as long as elements are <= pivot
        while (arr[i] <= pivot && i < end) {
            i++;
        }
        // Move j to the left as long as elements are > pivot
        while (arr[j] > pivot && j > start) {
            j--;
        }
        // If i is still to the left of j, swap arr[i] and arr[j]
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    // Place pivot in its correct sorted position by swapping arr[start] with arr[j]
    swap(&arr[start], &arr[j]);
    return j; // Return the index where pivot is now placed
}

// Recursively sorts the array using the QuickSort algorithm
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        // Find the pivot index
        int pivotIndex = partition(arr, start, end);
        
        // Recursively sort the left and right subarrays
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3}; // Initialize unsorted array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print array before sorting
    printf("Before Using Quick Sort:\n");
    printArray(arr, n);

    // Sort the array
    quickSort(arr, 0, n - 1);

    // Print array after sorting
    printf("After Quick Sort:\n");
    printArray(arr, n);

    return 0;
}

