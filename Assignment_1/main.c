#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include "bst.h"
int main()
{
	//trees of 10000 nodes
	char s[100];
	FILE *fptr;
	fptr = fopen("plot.txt", "w");
	
	BT bt1;
	initBT(&bt1);
	insertFromFileBT(&bt1, "file1.txt", 10000);
	
	BST bst1;
	initBST(&bst1);
	insertFromFileBST(&bst1, "file1.txt", 10000);
	
	int countBT = searchFromFileBT(bt1, "file6.txt");
	int countBST = searchFromFileBST(bst1, "file6.txt");
	
	printf("count BT %d\n", countBT / 100);
	printf("count BST %d\n", countBST / 100 );
	sprintf(s, "10000 %d %d\n", countBST, countBT);
	fputs(s, fptr);
	
	//trees of 100000 nodes
	BT bt2;
	initBT(&bt2);
	insertFromFileBT(&bt2, "file2.txt", 100000);
	
	BST bst2;
	initBST(&bst2);
	insertFromFileBST(&bst2, "file2.txt", 100000);
	countBT = searchFromFileBT(bt2, "file6.txt");
	countBST = searchFromFileBST(bst2, "file6.txt");
	
	printf("count BT %d\n", countBT / 100 );
	printf("count BST %d\n", countBST / 100 );
	sprintf(s, "100000 %d %d\n", countBST, countBT);
	fputs(s, fptr);
	
	//trees of 1000000 nodes
	BT bt3;
	initBT(&bt3);
	insertFromFileBT(&bt3, "file3.txt", 1000000);
	BST bst3;
	
	initBST(&bst3);
	insertFromFileBST(&bst3, "file3.txt", 1000000);
	countBT = searchFromFileBT(bt3, "file6.txt");
	countBST = searchFromFileBST(bst3, "file6.txt");
	
	printf("count BT %d\n", countBT / 100 );
	printf("count BST %d\n", countBST / 100);
	sprintf(s, "1000000 %d %d\n", countBST, countBT);
	fputs(s, fptr);
	
	// //trees of 10000000 nodes
	// BT bt4;
	// initBT(&bt4);
	// insertFromFileBT(&bt4, "file4.txt", 10000000);
	// BST bst4;
	
	// initBST(&bst4);
	// insertFromFileBST(&bst4, "file4.txt", 10000000);
	// countBT = searchFromFileBT(bt4, "file6.txt");
	// countBST = searchFromFileBST(bst4, "file6.txt");
	
	// printf("count BT %d\n", countBT / 100);
	// printf("count BST %d\n", countBST / 100);
	// sprintf(s, "10000000 %d %d\n", countBST, countBT);
	// fputs(s, fptr);
	// fclose(fptr);
	
	printf("completed\n");
	return 0;
}
