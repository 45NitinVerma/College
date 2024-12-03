#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for each element in the queue
struct Node {
    int data;
    struct Node* next;
};

// Initialize global pointers for front and rear
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue function to add an element to the rear of the queue
void enqueue(int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    // If the queue is empty, make newNode the front and rear
    if (rear == NULL) {
        front = rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }
    // Link the new node at the end of the queue and update rear
    rear->next = newNode;
    rear = newNode;
    printf("Enqueued %d\n", value);
}

// Dequeue function to remove an element from the front of the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }
    // Store the front node in a temporary pointer
    struct Node* temp = front;
    printf("Dequeued %d\n", front->data);
    // Move the front pointer to the next node
    front = front->next;
    // If the queue becomes empty, update rear to NULL
    if (front == NULL) {
        rear = NULL;
    }
    // Free memory of the dequeued node
    free(temp);
}

// Peek function to get the front element of the queue
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", front->data);
    }
}

// Display function to show all elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu-driven code for queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linked List Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
