#include "bt.h"
#include <stdio.h>
#include <stdlib.h>

void initBT(BT *bt)
{
	*bt = NULL;
	return;
}

int insertDataBT(BT *bt, int data){
	if(*bt == NULL){
		nodeBT *nn = malloc(sizeof(nodeBT));
		if(!nn)
		{
			return 0;
		}
		nn->data = data;
		nn->right = NULL;
		nn->left = NULL;
		*bt = nn;
		return 1;
	}

	nodeBT **cur = bt;
	while (*cur != NULL) 
	{
		if (rand() % 2) 
		{
			cur = &((*cur)->right);
		}
		 else 
		{
			cur = &((*cur)->left);
		}
	}

	nodeBT *nn = malloc(sizeof(nodeBT));
	if (!nn) 
	{
		return 0;
	}
	nn->data = data;
	nn->right = NULL;
	nn->left = NULL;
	*cur = nn;
	return 1;
}

void insertFromFileBT(BT *bt, char *f, int n)
{
	FILE *fptr = fopen(f, "r");
	int count = 0;
	int num;
	while(!feof(fptr) && count < n)
	{
		fscanf(fptr, "%d", &num);
		if(insertDataBT(bt, num))
		{
			count++;
		}
	}
	fclose(fptr);
}

void inorderTraversalBT(BT bt)
{
	if(!bt)
	{
		return;
	}

	nodeBT *stack[10000];
	int top = -1;
	nodeBT *cur = bt;

	while (top >= 0 || cur != NULL) 
	{
		while (cur != NULL) 
		{
			stack[++top] = cur;
			cur = cur->left;
		}

		cur = stack[top--];
		printf("%d ", cur->data);
		cur = cur->right;
	}
}

int searchDataBT(BT bt, int data, int *found)
{
	if(!bt)
	{
		return 0;
	}

	nodeBT *cur = bt;
	int count = 0;

	while (cur != NULL) 
	{
		count++;

		if (cur->data == data) 
		{
			*found = 1;
			return count;
		}

		if (cur->data > data) 
		{
			cur = cur->left;
		} 
		else 
		{
			cur = cur->right;
		}
	}

	return count;
}

int searchFromFileBT(BT bt, char *f)
{
	FILE *fptr = fopen(f, "r");
	int count = 0;
	int data;
	int found;

	while(!feof(fptr))
	{
		fscanf(fptr, "%d", &data);
		found = 0;
		count += searchDataBT(bt, data, &found);
	}

	fclose(fptr);
	return count;
}

int noOfNodesBT(BT bt)
{
	if(!bt)
		return 0;

	nodeBT *stack[10000];
	int top = -1;
	nodeBT *cur = bt;
	int count = 0;

	while (top >= 0 || cur != NULL) 
	{
		while (cur != NULL) 
		{
			stack[++top] = cur;
			cur = cur->left;
		}

		cur = stack[top--];
		count++;
		cur = cur->right;
	}

	return count;
}
