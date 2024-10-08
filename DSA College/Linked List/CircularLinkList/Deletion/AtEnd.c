#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp, *last;

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
        temp = head;
        // Find the last and second-to-last nodes
        do {
            last = temp;
            temp = temp->next;
        } while (temp->next != head);

        // Remove the last node from the list
        last->next = head;
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
    Step 5.1: Traverse the list to find the last and second-to-last nodes.
    Step 5.2: Update the second-to-last node to point to the head (removing the last node from the circle).
    Step 5.3: Free the memory of the last node.
Step 6: Traverse the list from the head, printing each node's data, stopping when we reach the head again.
Step 7: Exit the program.
*/
