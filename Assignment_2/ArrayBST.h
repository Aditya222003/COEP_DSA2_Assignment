typedef struct Array_BST{
    int *A;
    int size;
}Array_BST;

void initArrayBST(Array_BST*);
void insert(Array_BST*,int);
void preOrder(Array_BST,int);
void inOrder(Array_BST a_node,int i);
int HeightofTree(Array_BST);
void levelOrder(Array_BST a_node);
int power(int base, int exponent);
int checkifComplete(Array_BST a_node);
int LeafNodes(Array_BST a_node);
