#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node* head, *newNode;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 45;
    head->prev = NULL;
    head->next = NULL;
    int value;

    printf("Enter value to insert at the start: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    head->prev = newNode;
    head = newNode;

    printf("List after insertion: ");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

/*
Steps of the Algorithm:
Step 1: Define a structure for the doubly linked list node, including data, and pointers to the previous and next nodes.
Step 2: Initialize the head of the doubly linked list
Step 3: Input the value to insert at the start of the list.
Step 4: Allocate memory for a new node using [malloc]
Step 5: Assign the input value to the new node's data field.
Step 6: Set the new node's prev pointer to NULL and next pointer to the current head of the list.
Step 7: Update the current head's prev pointer to point to the new node.
Step 8: Update the head to point to the new node.
Step 9: Traverse the doubly linked list starting from the head and print the data of each node.
Step 10: Exit the program.
*/
