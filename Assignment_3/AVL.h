typedef struct node
{  int data;
   struct node *left,*right;
   int ht;
}node;

  node *insert(node*,int);
  node *Delete(node*,int);
  void  preorder(node *);
  void  inorder(node *);
  int   height( node *);
  node *rotateright(node *);
  node *rotateleft(node *);
  node *RR(node *);
  node *LL(node *);
  node *LR(node *);
  node *RL(node *);
  int BF(node *);
