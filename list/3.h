// 单链表

#include <stdlib.h>
#include <stdio.h>
#define ElemType int
#define OK 1
#define ERROR -1

typedef struct LNode 
{
  ElemType data;
  struct LNode *next;
} LinkList;

// 头插法创立单链表
void CreateListF(LinkList *L, ElemType a[], int n)
{
  LinkList *s; int i;
  L = (LinkList *) malloc(sizeof(LinkList));
  L->next = NULL;
  for(i = 0; i < n; i++) {
    s = (LinkList *) malloc(sizeof(LinkList));
    s->data = a[i];
    s->next = L->next;
    L->next = s;
  }
}

// 尾插入创建链表
void CreateListR(LinkList *L, ElemType a[], int n)
{
  LinkList *s, *r; int i;
  L = (LinkList *) malloc(sizeof(LinkList));
  r = L;
  L->next = NULL;
  for (i = 0; i < n; i++) {
    s = (LinkList *) malloc(sizeof(LinkList));
    s->data = a[i];
    s->next = NULL;
    r->next = s;
    r = s;
  }
}

// 查找元素返回逻辑位置
int LocateElem(LinkList *L, ElemType e)
{
  LinkList *a = L->next;
  int i = 1; //逻辑位置从1开始
  while(a != NULL && a->data != e) {
    a = a->next;
    i++;
  };
  if (a != NULL) {
    return i;
  } else {
    return -1;
  }
}

// 插入节点
void insertList(LinkList *L, int n, ElemType e)
{
  // 首先找到位置 n
  int i = 1;
  LinkList *a = L->next; // 第一个元素
  while(a != NULL && i < n - 1) {
    a = a->next;
    i++;
  }
  if (i = n - 1) {
    // 找到第 i-1 个
    LinkList *s = (LinkList *) malloc(sizeof(LinkList));
    s->data = e;
    s->next = a->next;
    a->next = s;
  }
}

// 删除节点操作
void deleteNode(LinkList *L, int n)
{
  int i = 1;
  LinkList *a = L->next;
  while(a != NULL && i < n - 1) {
    a = a->next;
    i++;
  }
  if (i == n - 1) {
    LinkList *s = a->next;
    a->next = s->next;
    free(s);
  }
}

// 有序链表的归并
void MergeList(LinkList *L1, LinkList *L2, LinkList *L3)
{
  L3 = (LinkList *) malloc(sizeof(LinkList));
  LinkList *a, *b, *c, *s;
  a = L1->next;
  b = L2->next;
  c = L3;
  while(a != NULL && b != NULL) {
    s = (LinkList *) malloc(sizeof(LinkList));
    if (a->data < b->data) {
      s->data = a->data;
      a = a->next;
    } else {
      s->data = b->data;
      b = b->next;
    }
    s->next = NULL;
    c->next = s;
    c = c->next;
  }
  while(a != NULL) {
    // 循环完了 L1还有
    s = (LinkList *) malloc(sizeof(LinkList));
    s->data = a->data;
    a = a->next;
    s->next = NULL;
    c->next = s;
    c = c->next;
  }
  while(b != NULL) {
    // 循环完了 L1还有
    s = (LinkList *) malloc(sizeof(LinkList));
    s->data = b->data;
    b = b->next;
    s->next = NULL;
    c->next = s;
    c = c->next;
  }
}