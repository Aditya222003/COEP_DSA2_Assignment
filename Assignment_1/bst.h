typedef struct nodeBST{
	int data;
	struct nodeBST *left, *right;
}nodeBST;

typedef nodeBST * BST;

void initBST(BST *);
int insertDataBST(BST *, int data);
void insertFromFileBST(BST *, char *, int);
void inorderTraversalBST(BST);
int searchFromFileBST(BST, char *);
int searchDataBST(BST, int);
int noOfNodesBST(BST);
