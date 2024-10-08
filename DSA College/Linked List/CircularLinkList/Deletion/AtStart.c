#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    struct Node* last;

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return 1;
    }

    // If there's only one node in the list
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        // Find the last node
        last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Store the head node in temp
        temp = head;
        // Move head to the next node
        head = head->next;
        // Update the last node to point to the new head
        last->next = head;
        // Free the memory of the first node
        free(temp);
    }

    printf("List after deletion: ");
    if (head != NULL) {
        temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}

/*
Steps of the Algorithm:
Step 1: Define a structure for the circular linked list node, including data and a pointer to the next node.
Step 2: Initialize the head of the linked list (assumed to be NULL in this case).
Step 3: Check if the list is empty (head is NULL). If so, print a message and exit.
Step 4: Check if there's only one node in the list (head->next == head). If so, free it and set head to NULL.
Step 5: If there's more than one node:
    Step 5.1: Find the last node (the one pointing back to head).
    Step 5.2: Store the head node in a temporary pointer.
    Step 5.3: Move the head to point to the second node (which becomes the new first node).
    Step 5.4: Update the last node to point to the new head.
    Step 5.5: Free the memory of the original first node.
Step 6: Traverse the list from the new head, printing each node's data, stopping when we reach the head again.
Step 7: Exit the program.
*/
