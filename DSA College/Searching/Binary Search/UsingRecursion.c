#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int start, int end, int target) {
    // Base case: If start index exceeds end, target is not in array
    if (start > end) {
        return -1;
    }
    
    int mid = (start + end) / 2;  // Calculate the middle index

    // Check if the middle element is the target
    if (arr[mid] == target) {
        return mid;
    }
    
    // If target is smaller, search the left half
    if (target < arr[mid]) {
        return binarySearch(arr, start, mid - 1, target);
    }
    
    // If target is larger, search the right half
    return binarySearch(arr, mid + 1, end, target);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);              // Size of the array
    int target;
    
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Call the binarySearch function
    int result = binarySearch(arr, 0, n - 1, target);

    // Check and print the result
    if (result == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}
