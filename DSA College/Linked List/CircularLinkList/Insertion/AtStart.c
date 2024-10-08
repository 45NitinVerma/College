#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head, *newNode, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 45;
    head->next = head;  // Points to itself to make it circular
    last = head;  // Keep track of the last node
    int value;

    printf("Enter value to insert at the start: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    
    last->next = newNode;  // Update the last node to point to the new node
    head = newNode;  // Update head to the new node

    printf("List after insertion: ");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}

/*
Steps of the Algorithm:
Step 1: Define a structure for the circular linked list node, including data and a pointer to the next node.
Step 2: Initialize the head of the circular linked list, making it point to itself.
Step 3: Initialize a 'last' pointer to keep track of the last node.
Step 4: Input the value to insert at the start of the list.
Step 5: Allocate memory for a new node using [malloc]
Step 6: Assign the input value to the new node's data field.
Step 7: Set the new node's next pointer to the current head of the list.
Step 8: Update the last node's next pointer to point to the new node.
Step 9: Update the head to point to the new node.
Step 10: Traverse the circular linked list starting from the head, print the data of each node, and stop when we reach the head again.
Step 11: Exit the program.
*/
