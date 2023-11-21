typedef struct nodeBT
{
	int data;
	struct nodeBT *right, *left;
}nodeBT;

typedef nodeBT * BT;

void initBT(BT *);
int insertDataBT(BT *, int data);
void insertFromFileBT(BT *, char *, int);
void inorderTraversalBT(BT);
int searchDataBT(BT, int, int *);
int searchFromFileBT(BT, char *);
int noOfNodesBT(BT);
