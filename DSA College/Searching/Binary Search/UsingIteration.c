#include <stdio.h>

// Iterative binary search function
int binarySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1;

    // Loop until start index is greater than end index
    while (start <= end) {
        int mid = (start + end) / 2;  // Calculate the middle index

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is smaller, ignore the right half
        if (target < arr[mid]) {
            end = mid - 1;
        }
        // If target is larger, ignore the left half
        else {
            start = mid + 1;
        }
    }

    // If we exit the loop, the target is not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);              // Size of the array
    int target;
    
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Call the binarySearch function
    int result = binarySearch(arr, n, target);

    // Check and print the result
    if (result == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}
