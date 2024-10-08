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
    int pos, i;

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return 1;
    }

    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    if (pos == 1) {
        // Deleting the first node
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    } else {
        // Traverse to find the node to delete
        temp = head;
        for(i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
            return 1;
        }

        // Delete the node
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }

    // Print the list after deletion
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
Step 2: Check if the list is empty. If so, print a message and exit.
Step 3: Input the position to delete (1-based index).
Step 4: If deleting the first node (pos == 1):
    Step 4.1: Save the head node in a temporary variable.
    Step 4.2: Move the head to the next node.
    Step 4.3: If the new head is not NULL, set its prev pointer to NULL.
    Step 4.4: Free the temporary node.
Step 5: If deleting any other node:
    Step 5.1: Traverse the list to find the node to delete.
    Step 5.2: If the position is invalid, print an error message and exit.
    Step 5.3: Update the previous node's next pointer to skip the node to be deleted.
    Step 5.4: If the node to be deleted is not the last node, update the next node's prev pointer.
    Step 5.5: Free the node to be deleted.
Step 6: Print the list after deletion.
Step 7: Exit the program.
*/
