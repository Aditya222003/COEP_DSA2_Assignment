#include"AVL.h"
#include<stdio.h>
#include<stdlib.h>


void main()
{
    node *root=NULL;
    int x,n,i,op;
    do
        {
            printf("\n");
            printf("\n1) Create the AVL Tree");
            printf("\n2) Insert Element into the AVL Tree");
            printf("\n3) Delete Element from the AVL Tree ");
            printf("\n4) Print the AVL Tree");
            printf("\n5) Quit");
            printf("\nEnter Your Choice: ");
            scanf("%d",&op);
            switch(op)
                {
                case 1:printf("\nEnter Total Number of Elements in the AVL Tree: ");
                       scanf("%d",&n);
                       printf("\n Enter AVL Tree Elements: ");
                       root=NULL;
                       for(i=0;i<n;i++)
                       {
                        scanf("%d",&x);
                        root=insert(root,x);
                       }
                       break;
                case 2:printf("\nEnter a Element to Insert in the AVL Tree: ");
                       scanf("%d",&x);
                       root=insert(root,x);
                       break;
                case 3:printf("\nEnter a Element to Delete from the AVL Tree: ");
                       scanf("%d",&x);
                       root=Delete(root,x);
                       break;
                case 4:    printf("\nPreorder Sequence of the AVL Tree:\n");
                    preorder(root);
                    printf("\nInorder sequence of the AVL Tree:\n");
                    inorder(root);
                    break;
                 }
    }while(op!=5);
}
