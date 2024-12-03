#include <stdio.h>
#define SIZE 5 // Define the maximum size of the queue

// Define the Circular Queue cQueue array
int cQueue[SIZE];
int front = -1; // Initialize front globally
int rear = -1;  // Initialize rear globally

// Check if the queue is full
int isFull()
{
    return (rear + 1) % SIZE == front;
}

// Check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Enqueue function to insert an element at the rear
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty())
    {
        front = 0; // Set front to 0 for the first element
    }
    rear = (rear + 1) % SIZE; // Circular increment of rear
    cQueue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue function to remove an element from the front
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued %d\n", cQueue[front]);
    if (front == rear)
    {
        // Reset queue if this is the last element
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE; // Circular increment of front
    }
}

// Peek function to get the front element of the queue
void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is %d\n", cQueue[front]);
    }
}

// Display function to show all elements in the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front;; i = (i + 1) % SIZE)
    {
        printf("%d ", cQueue[i]);
        if (i == rear)
            break;
    }
    printf("\n");
}

// Main function with menu-driven interface for queue operations
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
