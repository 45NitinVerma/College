#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Main function
int main() {
    struct node* root = NULL;
    int choice, value;
    
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a new node\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node %d inserted successfully.\n", value);
                break;
            
            case 2:
                printf("Exiting...\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}