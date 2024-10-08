#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp, *prev;

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return 1;
    }

    temp = head;
    prev = NULL;

    // Traverse to the last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // If there's only one node in the list
    if (prev == NULL) {
        head = NULL; // List becomes empty
    } else {
        prev->next = NULL; // Last node is removed from the list
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
Step 1: Define a structure for the singly linked list node, including data and a pointer to the next node.
Step 2: Initialize the head of the linked list (assumed to be NULL in this case).
Step 3: Check if the list is empty (head is NULL). If so, print a message and exit.
Step 4: Traverse the list to find the last node and keep track of the second-to-last node.
Step 5: If there's only one node in the list (prev is NULL), set head to NULL.
Step 6: Otherwise, set the next pointer of the second-to-last node to NULL.
Step 7: Free the memory of the last node.
Step 8: Traverse the list from the head, printing each node's data.
Step 9: Exit the program.
*/
