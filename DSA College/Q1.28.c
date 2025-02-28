#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list with alternate elements
struct Node* createAlternateList(struct Node* head) {
    if (!head) return NULL;

    struct Node* newHead = NULL;
    struct Node* newTail = NULL;
    struct Node* current = head;
    int toggle = 1;

    while (current) {
        if (toggle) {
            struct Node* newNode = createNode(current->data);
            if (!newHead) {
                newHead = newTail = newNode;
            } else {
                newTail->next = newNode;
                newTail = newTail->next;
            }
        }
        toggle = !toggle;
        current = current->next;
    }
    return newHead;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the alternate list creation
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Original List: ");
    printList(head);

    struct Node* alternateHead = createAlternateList(head);
    printf("Alternate List: ");
    printList(alternateHead);

    // Free allocated memory
    freeList(head);
    freeList(alternateHead);

    return 0;
}