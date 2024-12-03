#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    // Assign data to new node and make it point to current top
    newNode->data = value;
    newNode->next = top;
    // Update top to new node
    top = newNode;
    printf("Pushed %d to stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    // Point to the current top node
    struct Node* temp = top;
    printf("Popped %d from stack\n", top->data);
    // Update top to the next node
    top = top->next;
    // Free the popped node
    free(temp);
}

// Function to get the top element of the stack (peek)
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

// Function to display all elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    // Traverse the linked list to print all nodes
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0; 
}
