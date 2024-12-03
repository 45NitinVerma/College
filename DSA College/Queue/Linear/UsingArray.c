#include <stdio.h>
#define MAX 5 // Maximum size of the queue

// Queue variables
int queue[MAX];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue function to add an element at the rear of the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 for the first element
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue function to remove an element from the front of the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front++;
    if (front > rear) { // Reset queue if it becomes empty
        front = rear = -1;
    }
}

// Peek function to get the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", queue[front]);
    }
}

// Display function to show all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function with menu-driven code for queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
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
