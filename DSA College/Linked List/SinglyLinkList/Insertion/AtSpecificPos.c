#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* newNode, *temp;
    int value, pos, i;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        for(i = 0; i <= pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
            return 1;
        }

        newNode->next = temp->next;
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
Step 3: Input the value to insert into the list.
Step 4: Input the position to insert (1-based index).
Step 5: Allocate memory for a new node using malloc and assign the input value to the new node's data field.
Step 6: Check if the position is 1:
    Step 6.1: If so, set the new node's next pointer to the current head and update head to the new node.
Step 7: If position is greater than 1, traverse the list to find the node just before the desired position.
Step 8: Check if the position is valid (temp should not be NULL):
    Step 8.1: If not valid, print an error message and exit the program.
Step 9: Set the new node's next pointer to temp's next and update temp's next pointer to the new node.
Step 10: Traverse the linked list starting from the head and print the data of each node.
Step 11: Exit the program.
*/