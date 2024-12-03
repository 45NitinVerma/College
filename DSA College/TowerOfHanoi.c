#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Base case: If only 1 disk, move it directly from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary using destination as buffer
    towerOfHanoi(n - 1, source, destination, auxiliary);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination using source as buffer
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    
    // Input: Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Solve the Tower of Hanoi problem for n disks
    printf("Solution for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    
    return 0;
}
