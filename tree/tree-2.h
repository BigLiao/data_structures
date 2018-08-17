// 线索二叉树
#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR 0
#define TElemType char
#define OVERFLOW -1

typedef enum {Link, Thread} PointerTag;
typedef struct BiThrNode {
  TElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;


// 构造二叉树
// 来自 tree-1.h 
Status createBiThrTree (BiThrTree *T, TElemType **e) {
  if (**e == ' ') *T = NULL;
  else {
    if (!(*T = (BiThrNode *) malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    (*T)->data = **e;
    (*T)->LTag = (*T)->RTag = Link;
    (*e)++;
    createBiThrTree(&((*T)->lchild), e);
    (*e)++;
    createBiThrTree(&((*T)->rchild), e);
  }
  return OK;
}

// 二叉树线索化, 中序线索二叉树
void InThreading (BiThrTree T, BiThrNode **pre) {
  if (T) {
    InThreading(T->lchild, pre);
    if (!T->lchild) {
      T->LTag = Thread;
      T->lchild = *pre;
    }
    if (!T->rchild) {
      (*pre)->RTag = Thread;
      (*pre)->rchild = T;
    }
    (*pre) = T;
    InThreading(T->rchild, pre);
  }
}