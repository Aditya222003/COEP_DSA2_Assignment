#include<stdio.h>

typedef struct node {
	int i , j ;
	int data;
	struct node* next;
	struct node* down;
}node;
typedef struct Sparse{
	 int i , j ;
	node** rows ;
	node** cols;
}Sparse;

void colDis(Sparse s);
void rowDis(Sparse s);
void AddNode(int temp,Sparse **s,int i , int j);
void initSparse(Sparse *s,char filename[]);
void initMatrix(Sparse *s,int i,int j);
int isSymmetric(Sparse s1);
