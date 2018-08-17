#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR 0
#define ElemType char
#define OVERFLOW -1

// 二叉树和节点
typedef struct BiTNode {
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


// 构造二叉树
// 可以按先序、中序、后序，递归构造
Status CreateBiTree (BiTree *T) {
  // T 是指向指针的指针
  char ch = getchar();
  if (ch == ' ') T = NULL;
  else {
    if (!(*T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
    (*T)->data = ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
  }
  return OK;
}
Status CreateBiTree2 (BiTree *T, ElemType **e) {
  if (**e == ' ') *T = NULL;
  else {
    if (!(*T = (BiTNode *) malloc(sizeof(BiTNode)))) exit(OVERFLOW);
    (*T)->data = **e;
    (*e)++;
    CreateBiTree2(&((*T)->lchild), e);
    (*e)++;
    CreateBiTree2(&((*T)->rchild), e);
  }
  return OK;
}

// 中序遍历二叉树
Status InOrderTraverse (BiTree T, Status (*Visit)(ElemType e)) {
  if (T) {
    InOrderTraverse(T->lchild, Visit);
    Visit(T->data);
    InOrderTraverse(T->rchild, Visit);    
  }
  return OK;
}

// 后序遍历二叉树
Status InOrderTraverse2 (BiTree T, Status (*Visit)(ElemType e)) {
  if (T) {
    InOrderTraverse2(T->lchild, Visit);
    InOrderTraverse2(T->rchild, Visit);
    Visit(T->data);    
  }
  return OK;
}

