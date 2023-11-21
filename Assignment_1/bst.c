#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void initBST(BST *bst)
{
    *bst = NULL;
}

int insertDataBST(BST *bst, int data)
{
    nodeBST *nn = malloc(sizeof(nodeBST));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;

    if(*bst == NULL){
        *bst = nn;
        return 1;
    }

    nodeBST *current = *bst;
    nodeBST *prev = NULL;
    int direction = 0;

    while(current != NULL)
    {
        prev = current;
        if(current->data == data)
        {
            free(nn);
            return 0;
        }
        else if(current->data > data)
        {
            current = current->left;
            direction = -1;
        }
        else
        {
            current = current->right;
            direction = 1;
        }
    }

    if(direction == -1)
        prev->left = nn;
    else
        prev->right = nn;

    return 1;
}

void insertFromFileBST(BST *bst, char *f, int n)
{
    FILE *fptr = fopen(f, "r");
    int count = 0;
    int num;
    while(!feof(fptr) && count < n)
    {
        fscanf(fptr, "%d", &num);
        if(insertDataBST(bst, num))
            count++;
    }
    fclose(fptr);
}

void inorderTraversalBST(BST bst)
{
    if(!bst)
        return;

    nodeBST *stack[10000];
    int top = -1;
    nodeBST *current = bst;

    while(current != NULL || top != -1)
    {
        while(current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

int searchDataBST(BST bst, int data)
{
    int count = 0;
    nodeBST *current = bst;

    while(current != NULL)
    {
        count++;
        if(current->data == data)
            return count;
        else if(current->data > data)
            current = current->left;
        else
            current = current->right;
    }

    return 0;
}

int searchFromFileBST(BST bst, char *f)
{
    FILE *fptr = fopen(f, "r");
    int count = 0;
    int data;
    while(!feof(fptr))
    {
        fscanf(fptr, "%d", &data);
        count += searchDataBST(bst, data);
    }
    fclose(fptr);
    return count;
}

int noOfNodesBST(BST bst)
{
    int count = 0;
    nodeBST *stack[10000];
    int top = -1;
    nodeBST *current = bst;

    while(current != NULL || top != -1)
    {
        while(current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        count++;
        current = current->right;
    }

    return count;
}
