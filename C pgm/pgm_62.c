#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node* root = NULL;

// Insert a node into BST recursively
node* insert(node* root, int value) {
    if (root == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Preorder traversal without recursion
void preorder(node* root) {
    if (root == NULL) return;

    node* stack[50];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        node* curr = stack[top--];
        printf("%d ", curr->data);

        // Push right child first so that left is processed first
        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}

// Menu function
int menu() {
    int choice;
    printf("1. Insert\n2. Display Preorder\n3. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    int choice, value;
    for (choice = menu(); choice != 3; choice = menu()) {
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

