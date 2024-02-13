#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node*left,*right;
}node;

node* root=NULL,*temp;
node* createnode(int key)
    {
        node* new=(node*)malloc(sizeof(node));
        new->data=key;
        new->right=NULL;
        new->left=NULL;
        return new;
    }

node* insert(node* node,int key)
    {
        if(node==NULL)
           return createnode(key);
        else if(key<node->data)
            node->left=insert(node->left,key);
        else
            node->right=insert(node->right,key);
        return node; 
    }

void inorder(node* node){
    if(node!=NULL)
        {
            inorder(node->left);
            printf("%d",node->data);
            inorder(node->right);
        }
}

void preorder(node* node){
    if(node!=NULL)
        {
            printf("%d",node->data);
            preorder(node->left);
            preorder(node->right);
        }
}

void postorder(node* node){
    if(node!=NULL)
        {
            postorder(node->left);
            postorder(node->right);
            printf("%d",node->data);
        }
}

node* search(node* node,int key)
    {
        if(root==NULL)
            return NULL;
        else if(key<node->data)
            return search(node->left,key);
        else
            return search(node->right,key);
    }

node* minnode(node* node)
    {
        while(node->left!=NULL)
            node=node->left;
        return node;
    }

node* delete(node* node,int key)
    {
        if(node==NULL)
            return NULL;
        else if(key<node->data)
            node->left=delete(node->left,key);
        else if(key>node->data)
            node->right=delete(node->right,key);                                                                                                                                              else{
            if(node==NULL){
                free(node);
                return NULL;
                }
            else if(node->left==NULL){
                temp=node;
                node=node->right;
                free(temp);
                return node;
            }
            else if(node->right==NULL){
                temp=node;
                node=node->left;
                free(temp);
                return node;
            }
            else{
                temp=minnode(node);
                node->data=temp->data;
                node->right=delete(root->right,key);
            }

        }
    return node;
    }
int main() {
    node* root = NULL; // Initialize the root of the binary search tree
    int choice, key;
    
    do {
        // Display the menu
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operation based on user's choice
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key %d found in the tree.\n", key);
                else
                    printf("Key %d not found in the tree.\n", key);
                break;
            case 6:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = delete(root, key);
                printf("Node with key %d deleted from the tree.\n", key);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while (choice != 7); // Continue until the user chooses to exit

    return 0;
}