#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp;

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return 1;
    }

    temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // If there's only one node in the list
    if (temp->prev == NULL) {
        head = NULL; // List becomes empty
    } else {
        temp->prev->next = NULL; // Remove the last node from the list
    }
    free(temp); // Free the memory of the last node

    printf("List after deletion: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

/*
Steps of the Algorithm:
Step 1: Define a structure for the doubly linked list node, including data, and pointers to the previous and next nodes.
Step 2: Initialize the head of the linked list (assumed to be NULL in this case).
Step 3: Check if the list is empty (head is NULL). If so, print a message and exit.
Step 4: Traverse the list to find the last node.
Step 5: If there's only one node in the list (temp->prev is NULL), set head to NULL.
Step 6: Otherwise, set the next pointer of the second-to-last node to NULL.
Step 7: Free the memory of the last node.
Step 8: Traverse the list from the head, printing each node's data.
Step 9: Exit the program.
*/
