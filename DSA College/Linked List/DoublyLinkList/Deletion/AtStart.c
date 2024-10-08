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

    // Store the head node in temp
    temp = head;
    // Move head to the next node
    head = head->next;
    
    // If the new head is not NULL, set its prev to NULL
    if (head != NULL) {
        head->prev = NULL;
    }
    
    // Free the memory of the first node
    free(temp);

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
Step 4: If the list is not empty, store the head node in a temporary pointer.
Step 5: Move the head to point to the second node (which becomes the new first node).
Step 6: If the new head is not NULL (i.e., the list had more than one node), set its prev pointer to NULL.
Step 7: Free the memory of the original first node.
Step 8: Traverse the list from the new head, printing each node's data.
Step 9: Exit the program.
*/
