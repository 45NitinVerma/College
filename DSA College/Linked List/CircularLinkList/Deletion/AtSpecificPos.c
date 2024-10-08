#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp, *prev, *last;
    int pos, i;

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return 1;
    }

    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    // Find the last node
    last = head;
    while (last->next != head) {
        last = last->next;
    }

    if (pos == 1) {
        temp = head;
        if (head->next == head) {
            // Only one node in the list
            head = NULL;
        } else {
            head = head->next;
            last->next = head;
        }
        free(temp);
    } else {
        temp = head;
        prev = NULL;
        for(i = 1; i < pos && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == head && i != pos) {
            printf("Invalid position\n");
            return 1;
        }

        prev->next = temp->next;
        free(temp);
    }

    // Print the list after deletion
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
Step 2: Check if the list is empty. If so, print a message and exit.
Step 3: Input the position to delete (1-based index).
Step 4: Find the last node of the circular list.
Step 5: If deleting the first node (pos == 1):
    Step 5.1: Save the head node in a temporary variable.
    Step 5.2: If it's the only node, set head to NULL.
    Step 5.3: Otherwise, move head to the next node and update last node's next to the new head.
    Step 5.4: Free the temporary node.
Step 6: If deleting any other node:
    Step 6.1: Traverse the list to find the node to delete and keep track of the previous node.
    Step 6.2: If the position is invalid, print an error message and exit.
    Step 6.3: Update the previous node's next pointer to skip the node to be deleted.
    Step 6.4: Free the node to be deleted.
Step 7: Print the list after deletion, handling the circular nature of the list.
Step 8: Exit the program.
*/
