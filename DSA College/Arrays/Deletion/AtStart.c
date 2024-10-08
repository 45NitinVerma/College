#include <stdio.h>

int main() {
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Shift elements to the left
    for(i = 0; i < n - 1; i++) {
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
Step 3: Shift elements to the left by one position.
    Step 3.1: Start from the first element and move each element one position to the left.
    Step 3.2: Repeat until the second-to-last element is shifted to the last position.
Step 4: Decrease the value of n by 1 (n = n - 1) to reflect the deletion.
Step 5: Print the array after deletion (arr[0] to arr[n-1]).
Step 6: Exit the program.
*/
