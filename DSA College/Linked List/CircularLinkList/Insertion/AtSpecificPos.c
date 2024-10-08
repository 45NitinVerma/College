#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* newNode, *temp, *last;
    int value, pos, i;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        last = head;
        while (last->next != head) {
            last = last->next;
        }

        if (pos == 1) {
            newNode->next = head;
            last->next = newNode;
            head = newNode;
        } else {
            temp = head;
            for(i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }

            if (temp->next == head && i != pos - 1) {
                printf("Invalid position\n");
                return 1;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
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
Step 3: Input the value to insert into the list.
Step 4: Input the position to insert (1-based index).
Step 5: Allocate memory for a new node using malloc and assign the input value to the new node's data field.
Step 6: Check if the list is empty:
    Step 6.1: If empty, set head to the new node and make it point to itself.
Step 7: If list is not empty, find the last node (the one pointing to head).
Step 8: Check if the position is 1:
    Step 8.1: If so, set the new node's next pointer to the current head, update last node's next to the new node, and update head to the new node.
Step 9: If position is greater than 1, traverse the list to find the node just before the desired position.
Step 10: Check if the position is valid:
    Step 10.1: If not valid, print an error message and exit the program.
Step 11: Set the new node's next pointer to temp's next and update temp's next pointer to the new node.
Step 12: Traverse the circular linked list starting from the head, print the data of each node, and stop when we reach the head again.
Step 13: Exit the program.
*/
