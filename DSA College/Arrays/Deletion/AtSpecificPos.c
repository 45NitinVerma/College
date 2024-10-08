#include <stdio.h>

int main() {
    int arr[100], n, pos, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (human based index): ");
    scanf("%d", &pos);

    // Shift elements to the left
    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Steps of the Algorithm:
Step 1: Input the number of elements, n.
Step 2: Input the array elements arr[0] to arr[n-1].
Step 3: Input the position to delete (1-based index).
Step 4: Shift elements to the left starting from the position to delete.
    Step 4.1: Start from the given position and move each element one position to the left.
    Step 4.2: Repeat until the second-to-last element is shifted to the last position.
Step 5: Decrease the value of n by 1 (n = n - 1) to reflect the deletion.
Step 6: Print the array after deletion (arr[0] to arr[n-1]).
Step 7: Exit the program.
*/