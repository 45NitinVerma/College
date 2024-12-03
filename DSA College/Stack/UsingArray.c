#include <stdio.h>
#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1; // Initialize top to -1 to represent an empty stack

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow! No elements to pop.\n");
        return -1; // Return -1 to indicate that the stack is empty
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack.\n", value);
        return value;
    }
}

// Function to get the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty! No elements to peek.\n");
        return -1; // Return -1 to indicate that the stack is empty
    } else {
        return stack[top];
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty! Nothing to display.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
