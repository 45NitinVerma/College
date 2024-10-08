#include <stdio.h>

int main()
{
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    n--; // Just decrease the size to remove the last element

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Steps of the Algorithm:
Step 1: Input the number of elements, n.
Step 2: Input the array elements arr[0] to arr[n-1].
Step 3: Decrease the value of n by 1 (n = n - 1) to remove the last element.
Step 4: Print the array after deletion (arr[0] to arr[n-1]).
Step 5: Exit the program.
*/