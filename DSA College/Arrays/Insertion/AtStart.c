#include <stdio.h>

int main() {
    int arr[100], n, value, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to insert at the start: ");
    scanf("%d", &value);

    // Shift elements to the right
    for(i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;  // Insert value at the start
    n++;

    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Steps of the Algorithm:
Step 1: [Initialize counter] Input the number of elements, n.
Step 2: Input the array elements arr[0] to arr[n-1].
Step 3: Input the value to insert at the start.
Step 4: Shift elements to the right by one position.
    Step 4.1: Start from the last element and shift each element one position to the right.
    Step 4.2: Repeat until the first element is shifted.
Step 5: Insert the input value at the first position.
Step 6: Increment the number of elements by 1 (n = n + 1).
Step 7: Print the array after insertion.
Step 8: Exit the program.
*/