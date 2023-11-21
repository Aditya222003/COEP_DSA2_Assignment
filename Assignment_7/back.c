#include<stdio.h>
#include "back.h"
#include<stdlib.h>



void colDis(Sparse s){

printf("\n");
node* cols;
	for(int i = 0 ; i < s.j; i++)
	{

	cols = s.cols[i];
	while(cols){
	printf("%d\t",cols -> data);
	
	cols = cols -> down;
	}
	printf("\n");
	}
}


void rowDis(Sparse s)
{

printf("\n");
node* rows;
	for(int i = 0 ; i < s.i; i++)
	{
		
		rows = s.rows[i];
		while(rows)
		{
			printf("%d\t",rows -> data);
			rows = rows -> next;
		}
	printf("\n");
	}
}
void AddNode(int temp,Sparse **s,int i , int j)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode -> i = i;
	newnode -> j = j;
	newnode -> data = temp;
	newnode -> next = NULL;
	newnode -> down = NULL;
	
	node* p;
	if(!(*s) -> rows[i])
	{
		(*s) -> rows[i] = newnode;
	}
	else
	{
		p = (*s) -> rows[i];
		
		while(p -> next)
		{
			p = p -> next;
		}
		p -> next = newnode;
	}
	
	i = j;
	if(!(*s) -> cols[i])
	{
		(*s) -> cols[i] = newnode;
	}
	else
	{
		node* q;
		q = (*s) -> cols[i];
		while(q -> down)
		{
			q  = q -> down;
		}
		q -> down = newnode;
	}	
}
void initSparse(Sparse *s,char filename[]){

	FILE *fp = fopen(filename,"r");
	int rows;
	int cols;
	fscanf(fp,"%d\n",&rows);
	fscanf(fp,"%d\n",&cols);
	printf("Rows : %d and Cols : %d",rows,cols);
	
	s -> rows =  (node**)malloc(sizeof(node*)*rows);
	s -> cols = (node**)malloc(sizeof(node*)*cols);
	
	s -> i = rows;
	s -> j = cols;
	for(int i = 0 ; i < rows; i++)
	{
	int temp ;
		for(int j = 0 ; j < cols; j++)
		{
			fscanf(fp,"%d\n",&temp);
			if(temp)
			{
				AddNode(temp,&s,i,j);
			}
	 	}
	}

	return ;
}
void initMatrix(Sparse *s,int i,int j)
{
	s -> rows =  (node**)malloc(sizeof(node*)*i);
	s -> cols = (node**)malloc(sizeof(node*)*j);
	node* ab = s -> rows[0];
	
	s -> i = i;
	s -> j = j;
}


int isSymmetric(Sparse s){
	if(s.i != s.j){
		return 0;
	}

	for(int i = 0 ; i < s.i ; i++){
		node* p = s.rows[i];
		node* q = s.cols[i];
	
		while(p && q){
			
			if(p -> i != q -> i && q -> j != p -> j)
				
		    if( p -> i == q -> j && q -> i == p -> j  && p -> data != q -> data)
			{
					return 0;
			}
			
			p = p -> next;
			q = q -> down;
		}
		if(p || q)
		return 0;
	}
	return 1;
}
