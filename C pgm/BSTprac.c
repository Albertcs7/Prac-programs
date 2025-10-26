#include <stdio.h>
#include <stdlib.h>

// Define BST node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Recursive function to insert a value into BST
node* insert(node* root, int val) {
    // Base case: empty spot found
    if (root == NULL) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    // Traverse left or right subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    // Ignore duplicate values

    return root; // return the unchanged root
}

// Inorder traversal to display BST (sorted order)
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function with menu
int main() {
    node* root = NULL; // start with empty tree
    int ch, val;

    while (1) {
        printf("\n1. Insert\n2. Display (Inorder)\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                root = insert(root, val); // update root
                break;

            case 2:
                printf("BST in inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

