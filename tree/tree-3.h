// 二叉树习题解析
#include <stdio.h>
#include <stdlib.h>
#define Status int
#define OK 1
#define ERROR 0
#define TElemType char
#define OVERFLOW -1

typedef struct BTNode {
  TElemType data;
  struct BTNode *lchild, *rchild;
} BTNode; // 二叉树的链式储存结构

// ------ 构造二叉树 --------

// 定理：先序遍历序列和中序遍历序列可唯一确定二叉树
BTNode *CreateBTree1 (char *pre, char *in, int n) {
  // pre 先序遍历序列，in 中序遍历序列， n 序列长度
  if (n <= 0) return NULL;
  BTNode *tree = (BTNode *) malloc(sizeof(BTNode));
  tree->data = *pre;
  char *p;
  for (p = in; p <in + n; p++) {
    if (*p == *pre) {
      break;
    }
  }
  int k = p - in;
  tree->lchild = CreateBTree1(pre+1, in, k);
  tree->rchild = CreateBTree1(pre+k+1, p + 1, n - k - 1);
  return tree;
}

// 同上：后序遍历序列和中序遍历序列可唯一确定二叉树
BTNode *CreateBTree2 (char *post, char *in, int n) {
  // post 后序遍历序列，in 中序遍历序列， n 序列长度
  if (n <= 0) return NULL;
  BTNode *tree = (BTNode *) malloc(sizeof(BTNode));
  tree->data = *(post + n - 1);
  char *p;
  for (p = in; p <in + n; p++) {
    if (*p == *(post + n - 1)) {
      break;
    }
  }
  int k = p - in;
  tree->lchild = CreateBTree2(post, in, k);
  tree->rchild = CreateBTree2(post+k, p + 1, n - k - 1);
  return tree;
}
