#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*left,*right;
}node;

node* root=NULL,*temp,*rightl,*leftl;

node* insert()
    {
        int x;
        printf("Enter data ,-1 for no data ");
        scanf("%d",&x);
        if(x==-1)
            return NULL;
        node* new=(node*)malloc(sizeof(node));
        new->data=x;
        printf("Enter the left child of %d\n",x);
        new->left=insert();
        printf("Enter the right child of %d\n",x);
        new->right=insert();
        return new;
    }

void inorder( node*ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
}
node* findleaf(node* node)
    {
        if(node==NULL)
            return NULL;
        else if(node->left==NULL && node->right==NULL)
            return node;
        else{
            leftl=findleaf(node->left);
            rightl=findleaf(node->right);
            return (leftl!=NULL?leftl:rightl);
        }
    }
node* delete(node* node,int data)
    {
        if(node==NULL)
            return NULL;
        else if(node->data!=data)
            {
                node->left=delete(node->left,data);
                node->right=delete(node->right,data);
            }
        else{
            if(node->left==NULL && node->right==NULL)
                {
                    free(node);
                    return NULL;
                }
            else if(node->left==NULL)
                {
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
                temp=findleaf(node->right);
                node->data=temp->data;
                node->right=delete(node->right,temp->data);
            }
        }
    }
int main() {
    printf("1:Insert\n2:Inorder\n3:deletion\n4:exit");
    int choice,data;
    do{
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                root=insert();
                break;
            case 2:
                printf("inorder\n");
                inorder(root);
                break;
            case 3:
                printf("enter data to be deleted : ");
                scanf("%d",&data);
                delete(root,data);
                printf("element deleted!!");
                break;
            case 4:
                printf("exit");
                break;
        }
    }while(choice!=4);
    

    return 0;
}

