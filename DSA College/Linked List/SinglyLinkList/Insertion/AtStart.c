#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head, *newNode;
    head = (struct Node*)malloc(sizeof(struct Node));
    head -> data = 45;
    head -> next = NULL;
    int value;

    printf("Enter value to insert at the start: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = head;

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
Step 1: Define a structure for the linked list node, including data and a pointer to the next node.
Step 2: Initialize the head of the linked list
Step 3: Input the value to insert at the start of the list.
Step 4: Allocate memory for a new node using malloc.
Step 5: Assign the input value to the new node's data field.
Step 6: Set the new node's next pointer to the current head of the list.
Step 7: Update the head to point to the new node.
Step 8: Traverse the linked list starting from the head and print the data of each node.
Step 9: Exit the program.
*/
