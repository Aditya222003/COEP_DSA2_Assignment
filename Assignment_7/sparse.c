#include<stdio.h>
#include<stdlib.h>
#include "back.h"


int main()
{

	Sparse s,s1;
	initSparse(&s,"input.txt");
	rowDis(s);
	
	initSparse(&s1,"input1.txt");
	rowDis(s1);

	Sparse x1 ;
	initSparse(&x1,"test.txt");

	int ans = isSymmetric(x1);
	
	if(ans)
	{
		printf("\nSymmetric\n");
	}
	else
	{
		printf("\nNot Symmetric\n");
	}	
	
}

