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
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("List after insertion: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
/*
Steps of the Algorithm:
Step 1: Define a structure for the linked list node, including data and a pointer to the next node.
Step 2: Initialize the head of the linked list as NULL (empty list).
Step 3: Input the value to insert at the end of the list.
Step 4: Allocate memory for a new node using malloc.
Step 5: Assign the input value to the new node's data field and set its next pointer to NULL.
Step 6: Check if the head is NULL (list is empty):
    Step 6.1: If empty, set head to the new node.
    Step 6.2: If not empty, traverse the list to find the last node.
Step 7: Link the last node's next pointer to the new node.
Step 8: Traverse the linked list starting from the head and print the data of each node.
Step 9: Exit the program.
*/