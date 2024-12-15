#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a node with user input
struct node* createNode() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    
    if (x == -1) {
        return NULL;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = x;
    printf("Enter left child of %d:\n", x);
    newNode->left = createNode();

    printf("Enter right child of %d:\n", x);
    newNode->right = createNode();

    return newNode;
}

// Main function
int main() {
    struct node* root = createNode();
    printf("Binary tree created successfully.\n");
    return 0;
}
