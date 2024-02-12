#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coeff;
    int exp;
    struct node* next;
}node;

node* poly1=NULL,*poly2=NULL,*head=NULL,*temp=NULL,*result=NULL,*result1=NULL;

node* createnode(int coeff,int exp)
    {
        node* new=(node*)malloc(sizeof(node));
        new->coeff=coeff;
        new->exp=exp;
        new->next=NULL;
        return new;
    }
void insert(node** poly,int coeff,int exp)
    {
        node* new=createnode(coeff,exp);
        if(*poly==NULL)
            *poly=new;
        else{
            temp=*poly;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new;
        }
    }
void displaypoly(node* poly)
    {
        printf("\n");
        while(poly!=NULL)
            {
                printf("%dx^%d\t",poly->coeff,poly->exp);
                poly=poly->next;
                if(poly!=NULL)
                    printf("+");
            }
    }
void insertOrAdd(node** poly, int coeff, int exp)
{
    node* temp = *poly;
    while(temp != NULL)
    {
        if(temp->exp == exp)
        {
            temp->coeff += coeff;
            return;
        }
        temp = temp->next;
    }
    insert(poly, coeff, exp);
}

void multipoly(node* poly1, node* poly2)
{
    node* temp = poly2;
    while(poly1 != NULL)
    {
        poly2 = temp;
        while(poly2 != NULL)
        {
            insertOrAdd(&result1, poly1->coeff * poly2->coeff, poly1->exp + poly2->exp);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
    }
}
void addpoly(node* poly1,node* poly2)
    {
        while(poly1!=NULL&&poly2!=NULL){
            if(poly1->exp==poly2->exp){
                insert(&result,poly1->coeff+poly2->coeff,poly1->exp);
                poly1=poly1->next;
                poly2=poly2->next;
            }
            else if(poly1->exp>poly2->exp){
                insert(&result,poly1->coeff,poly1->exp);
                poly1=poly1->next;

            }
            else{
                insert(&result,poly2->coeff,poly2->exp);
                poly2=poly2->next;
            }
        }
        while(poly1!=NULL){
            insert(&result,poly1->coeff,poly1->exp);
            poly1=poly1->next;
        }
        while(poly2!=NULL){
            insert(&result,poly2->coeff,poly2->exp);
            poly2=poly2->next;
        }
    }

void main()
    {
        int i,m,n,coeff,exp;
        printf("Enter the no of terms in polynomial 1");
        scanf("%d",&m);
        for(i=0;i<m;i++)
            {
                printf("Enter the coefficient and exponent");
                scanf("%d %d",&coeff,&exp);
                insert(&poly1,coeff,exp);
            }
        displaypoly(poly1);
        printf("Enter the no of terms in polynomial 2");
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {
                printf("Enter the coefficient and exponent");
                scanf("%d %d",&coeff,&exp);
                insert(&poly2,coeff,exp);
            }
        displaypoly(poly2);
        addpoly(poly1,poly2);
        displaypoly(result);
        multipoly(poly1,poly2);
        displaypoly(result1);
    }
