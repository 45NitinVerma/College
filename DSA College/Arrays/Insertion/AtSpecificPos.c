#include <stdio.h>

int main() {
    int arr[100], n, value, pos, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    // Shift elements to the right
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;  // Insert value at the specified position
    n++;

    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Steps of the Algorithm:
Step 1: Input the number of elements, n.
Step 2: Input the array elements arr[0] to arr[n-1].
Step 3: Input the value to insert.
Step 4: Input the position (1-based index) where the value should be inserted.
Step 5: Shift elements to the right.
    Step 5.1: Start from the last element and shift each element one position to the right.
    Step 5.2: Repeat the process until the element at the position is shifted.
Step 6: Insert the input value at the specified position (arr[pos - 1]).
Step 7: Increment the number of elements by 1 (n = n + 1).
Step 8: Print the array after insertion.
Step 9: Exit the program.
*/