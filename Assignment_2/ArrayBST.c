#include "ArrayBST.h"
#include<stdlib.h>
#include<limits.h>
#include<stdio.h>
#include<math.h>


void initArrayBST(Array_BST* a_node){
    a_node -> A = NULL;          
    a_node -> size = 0 ;
}

int isEmpty(Array_BST a_node)
{        
    return (!a_node.A);         
}

void insert(Array_BST* a_node,int data){
    if(isEmpty(*a_node)){
        a_node -> A = (int*)malloc(sizeof(int));         
        
        if(!a_node -> A)                 
        return ;

        a_node -> size = 1 ;                   
        a_node -> A[0] = data;
        
        return ;
    }

    int index = 0;
    int size =  a_node -> size;
  
    while(index < size && a_node -> A[index] != INT_MIN)
    {    
        
        if(a_node -> A[index] == data)                       
        return ;
        
        else if(a_node -> A[index] > data)
        {
            index = 2 * index + 1;              
        }
        
        else{
            index = 2 * index + 2;              
        }
    }

    if( index < size &&  a_node -> A[index] == INT_MIN)
    {     
            a_node -> A[index] = data;
            return ;
    }

        a_node -> A = (int*) realloc(a_node -> A,sizeof(int) * (index+1)); 
        if(!a_node -> A)
        return ;

        for(int i = size ; i < index ; i++)             
        a_node -> A[i] = INT_MIN;

        a_node -> A[index] = data;
        a_node -> size = index+1;
        return ; 
}
void preOrder(Array_BST a_node,int i){
   if(i >= a_node.size || a_node.A[i] == INT_MIN){
    return ;
   }

   printf("%d ",a_node.A[i]);
   preOrder(a_node,2*i + 1);
   preOrder(a_node,2*i + 2);

}
void inOrder(Array_BST a_node,int i){
   if(i >= a_node.size || a_node.A[i] == INT_MIN){
    return ;
   }

   inOrder(a_node,2*i + 1);
   printf("%d ",a_node.A[i]);
   inOrder(a_node,2*i + 2);

}
int HeightofTree(Array_BST a_node){
    if(isEmpty(a_node))          
        return -1;
    int size = a_node.size;
    int count = 0 , decrement = 0;      
    if(size % 2 == 0){
        decrement = 1;             
    }
    else{
        decrement = 2;          
    }
    for(int i = size ; i >= 0 ; i = i/2-decrement)
    { 
        count++;
    }
    return count;
}

int LeafNodes(Array_BST a_node){
    int size = a_node.size;
    int count = 0 ;

     if(isEmpty(a_node)){        
            return 0;   
     }

    for(int i = 0 ; i < size ; i++){
        int left = 2*i + 1;
        int right = 2*i + 2;            
            if(a_node.A[i] == INT_MIN)       
                continue;
        
            if(left >= size && right >= size)  
                count++;
            else if(a_node.A[left] == INT_MIN &&  a_node.A[right] == INT_MIN) 
                count++;
        
    }
    return count;
}

int checkifComplete(Array_BST a_node){
 
    int size = a_node.size ;

    for(int i = 0 ; i < size ; i++)
    {
        
        if(a_node.A[i] == INT_MIN)           
            return 0;
    }
    return 1;
}
int power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}
void levelOrder(Array_BST a_node){
    
    if(isEmpty(a_node)){
        return ;
    }

    int lvl = 0 , count = 0;
    for(int i = 0 ; i < a_node.size ; i++){
        if(a_node.A[i] != INT_MIN)
            printf("%d ",a_node.A[i]);      
       
        if(i == 0){                    
            lvl++;
            //printf("\n");
        }

        else if(count == (int)power(2,lvl)){     
            count = 0;
             lvl++;
            //printf("\n");
        }
        count++;                   
    }
    printf("\n");
    return;
}
