#include "./tree-1.h"

// 求先序遍历二叉树中第k 的节点的值
int n1 = 1;
ElemType PreOrderVal (BiTree T, int k)
{
  ElemType ch;
  if (!T) return ' ';
  if (k == n1) return T->data;
  n1++;
  ch = PreOrderVal(T->lchild, k);
  if (ch == ' ') {
    ch = PreOrderVal(T->rchild, k);
  }
  return ch;
}
ElemType PreOrderVal2 (BiTree T, int k);
void test_PreOrderVal ()
{
  printf("test ProOrderVal started...");
  char *s = "ABC  DE G  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  char x = PreOrderVal(Tree, 3);
  char y = PreOrderVal2(Tree, 3);
  printf("Tree[3]=%c\n", x);
}

// 上述题目的非递归算法
ElemType PreOrderVal2 (BiTree T, int k)
{
  BiTree Stack[100], p;
  int top = -1, n = 0;
  Stack[++top] = T; // 根节点进栈
  while(top >= 0) {
    p = Stack[top--]; // 退栈并访问节点
    n++;
    if (n == k) {
      return p->data;
    }
    if (p->rchild != NULL)  // 右孩子先进栈
      Stack[++top] = p->rchild;
    if (p->lchild != NULL)  // 左孩子进栈，后进先出
      Stack[++top] = p->lchild; 
  }
}

// 求二叉树中序序列中第 k 的节点的值
int n2 = 1;
ElemType InOrderVal(BiTree T, int k)
{
  ElemType ch;
  if (T == NULL) return ' ';
  ch = InOrderVal(T->lchild, k);
  if (ch != ' ') return ch;
  if (k == n2) return T->data;
  n2++;
  return InOrderVal(T->rchild, k);
}
// 非递归算法
ElemType InOrderVal2(BiTree T, int k)
{
  BiTree Stack[100], p;
  int top = -1, n = 1;
  int flag = 1; // 是否是新节点
  Stack[++top] = T; // 根节点进栈
  while(top > -1) {

    p = Stack[top]; //
    // 先让所有左子树进栈
    while(flag && p->lchild) {
      p = p->lchild;
      Stack[++top] = p;
    }
    if (k == n) {
      return p->data;
    }
    top--;  // 出栈
    n++;
    flag = 0;
    if (p->rchild) {
      Stack[++top] = p->rchild; // 右子树进栈
      flag = 1;
    }
  }
}
void test_InOrderVal ()
{
  printf("test InOrderVal started...");
  char *s = "ABC  DE G  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  char x = InOrderVal(Tree, 3);
  char y = InOrderVal2(Tree, 3);
  printf("Tree[3]=%c\n", x);
}

// 计算二叉树的叶子节点个数
int BiTreeLeaf (BiTree T)
{
  int n = 0;
  if (!T->lchild && !T->rchild) {
    return 1;
  }
  if (T->lchild) {
    n += BiTreeLeaf(T->lchild);
  }
  if (T->rchild) {
    n += BiTreeLeaf(T->rchild);
  }
  return n;
}
void test_BiTreeLeaf ()
{
  printf("test BiTreeLeaf started...\n");
  char *s = "ABC  DE G  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  int leaf = BiTreeLeaf(Tree);
  printf("leaf=%d\n", leaf);
}
// 求二叉树最小节点的值
ElemType MinNode (BiTree T)
{
  ElemType min, n;
  min = T->data;
  if (T->lchild && (n = MinNode(T->lchild)) < min) {
    min = n;
  }
  if (T->rchild && (n = MinNode(T->rchild)) < min)
    min = n;
  return min;
}
void test_MinNode ()
{
  printf("test BiTreeLeaf started...\n");
  char *s = "ABC  1E G  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  char min = MinNode(Tree);
  printf("min=%c\n", min);
}

// 求二叉树所有节点的和  (例7-3-36 p263)
int FindSum (BiTree T)
{
  if (T==NULL)
    return 0;
  else
    return T->data + FindSum(T->lchild) + FindSum(T->rchild);
}
// 求值为 x 的节点个数
int FindX (BiTree T, ElemType x)
{
  if (T == NULL)
    return 0;
  else
    return (T->data == x) + FindX(T->lchild, x) + FindX(T->rchild, x);
}
void test_FindX ()
{
  printf("test FindX started...\n");
  char *s = "ABC  DA B  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  int n = FindX(Tree, 'B');
  printf("count of x is %d\n", n);
}

// 按层次顺序遍历二叉树 （例7-3-42, p266）
void FloorOrder (BiTree T, void f(ElemType e))
{
  // 使用队列, 构造一个循环队列
  int MaxSize = 50;
  BiTree Qu[50];
  BiTree current;
  int front = -1, tear = -1;
  //根节点进队
  tear = 0; front = 0;
  Qu[tear++] = T;
  // 当队列不为空
  while(front != tear) {
    current = Qu[front];
    front = (front + 1) % MaxSize;
    (*f)(current->data);
    if (current->lchild) {
      Qu[tear] = current->lchild;
      tear = (tear + 1) % MaxSize;
      if ((tear + 1) % MaxSize == front) exit(0);
    }
    if (current->rchild) {
      Qu[tear] = current->rchild;
      tear = (tear + 1) % MaxSize;
      if ((tear + 1) % MaxSize == front) exit(0);
    }
  }
}
void printChar(char c) {
  printf("%c", c);
}
void test_FloorOrder ()
{
  printf("test FloorOrder started...\n");
  char *s = "ABC  DE G  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  FloorOrder(Tree, printChar);
}

// 求第 k 层的子节点个数
int LeafLevel (BiTree T, int k)
{
  int level = 0, count = 0;
  int MaxSize = 50;
  BiTree Qu[50];
  BiTree current;
  int front = -1, tear = -1, last = 0;
  //根节点进队
  tear = 0; front = 0; level = 1;
  Qu[tear++] = T;
  // 当队列不为空
  while(front != tear) {
    current = Qu[front];
    if (current->lchild) count++;
    if (current->rchild) count++;
    if (front == last) {
      if (level == k) {
        return count;
      }
      if (current->lchild && current->rchild) {
        last = tear + 2;
      } else if (current->lchild || current->rchild) {
        last = tear + 1;
      } else {
        last = tear;
      }
      count = 0;
      level++;
    }
    front = (front + 1) % MaxSize;
    if (current->lchild) {
      Qu[tear] = current->lchild;
      tear = (tear + 1) % MaxSize;
      if ((tear + 1) % MaxSize == front) exit(0);
    }
    if (current->rchild) {
      Qu[tear] = current->rchild;
      tear = (tear + 1) % MaxSize;
      if ((tear + 1) % MaxSize == front) exit(0);
    }
    
  }
}
void test_LeafLevel ()
{
  printf("test LeafLevel started...\n");
  char *s = "ABC  DE G  F   ";
  BiTree Tree;
  CreateBiTree2(&Tree, &s);
  int n = LeafLevel(Tree, 2);
  printf("leaf of level is %d\n", n);
}

int main(int argc, char const *argv[])
{
  test_LeafLevel();
  return 0;
}
