#include <stdio.h>

int main() {
    int arr[100], n, value, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to insert at the end: ");
    scanf("%d", &value);

    arr[n] = value;  // Insert value at the end
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
Step 4: Insert the value at the end of the array (arr[n]).
Step 5: Increment the number of elements by 1 (n = n + 1).
Step 6: Print the array after insertion.
Step 7: Exit the program.
*/