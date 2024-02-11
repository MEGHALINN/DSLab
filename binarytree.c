#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary tree
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct Node* insert(struct Node* root, char data, char child) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (child == 'l' || child == 'L')
            root->left = insert(root->left, data, child);
        else
            root->right = insert(root->right, data, child);
        return root;
    }
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to find the node with minimum value in a tree. 
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, char data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice;
    char data, child;

    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &data);
                printf("Enter 'L' to insert as left child or 'R' to insert as right child: ");
                scanf(" %c", &child);
                root = insert(root, data, child);
                break;
            case 2:
                printf("Enter character to delete: ");
                scanf(" %c", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
