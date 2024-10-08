#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* newNode, *temp;
    int value;

    printf("Enter value to insert at the end: ");
    scanf("%d", &value);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Point to itself to make it circular
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  // Make it circular
    }

    printf("List after insertion: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}

/*
Steps of the Algorithm:
Step 1: Define a structure for the circular linked list node, including data and a pointer to the next node.
Step 2: Initialize the head of the circular linked list as NULL (empty list).
Step 3: Input the value to insert at the end of the list.
Step 4: Allocate memory for a new node using malloc.
Step 5: Assign the input value to the new node's data field.
Step 6: Check if the head is NULL (list is empty):
    Step 6.1: If empty, set head to the new node and make it point to itself.
    Step 6.2: If not empty, traverse the list to find the last node (the one pointing to head).
Step 7: Link the last node's next pointer to the new node and the new node's next pointer to the head.
Step 8: Traverse the circular linked list starting from the head, print the data of each node, and stop when we reach the head again.
Step 9: Exit the program.
*/
