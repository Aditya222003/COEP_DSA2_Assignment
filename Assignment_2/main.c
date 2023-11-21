#include<stdio.h>
#include "ArrayBST.h"

int main(){
    Array_BST a_node;
    initArrayBST(&a_node);
    insert(&a_node,20);
    insert(&a_node,10);
    insert(&a_node,5);
    insert(&a_node,15);
    insert(&a_node,7);
    insert(&a_node,12);
    insert(&a_node,17);
    insert(&a_node,23);
    insert(&a_node,28);
    insert(&a_node,33);
    insert(&a_node,32);
  	 insert(&a_node,32);
  	 
    printf("\nInserted Array in inorder : ");
    inOrder(a_node,0);
    //printf("");
    printf("\nHeight of Array BST: %d ",HeightofTree(a_node));
    if( checkifComplete(a_node) == 0 )
    {
    	printf("\nArray BST is : Complete  \n");
    }
    else 
    {
    	printf("\nArray BST is : inComplete  \n");
    }
    printf("Count Leaf %d\n", LeafNodes(a_node));
    
    printf("Level order Traversal of the Tree is : ");
    levelOrder(a_node);
    printf("\n");
    return 0;
}
