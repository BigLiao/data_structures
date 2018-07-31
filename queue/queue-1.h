// 链储存的队列
#define ElemType int
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef int Status;

typedef struct QNode {
  ElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
  QueuePtr front;
  QueuePtr rear;
} LinkQueue;

Status InitQueue (LinkQueue *Q);
Status DestroyQueue (LinkQueue *Q);
Status QueueEmpty (LinkQueue *Q);
Status QueueLength (LinkQueue *Q);
Status GetHead (LinkQueue *Q);
Status EnQueue (LinkQueue *Q, ElemType e);
ElemType DeQueue (LinkQueue *Q);
Status QueueTraverse (LinkQueue *Q);

Status InitQueue (LinkQueue *Q)
{
  // Q = (LinkQueue *) malloc(sizeof(LinkQueue));
  // if (!Q) exit(OVERFLOW);
  Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
  if (!Q) exit(OVERFLOW);
  Q->front->next = NULL;
  return OK;
}

Status DestroyQueue (LinkQueue *Q)
{
  while(Q->front) {
    Q->rear = Q->rear->next;
    free(Q->front);
    Q->front = Q->rear;
  }
  return OK;
}

// 从尾部插入元素
Status EnQueue (LinkQueue *Q, ElemType e)
{
  QNode *p = (QNode *) malloc(sizeof(QNode));
  p->data = e;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
}

// 从头部删除元素
ElemType DeQueue (LinkQueue *Q)
{
  if (Q->rear == Q->front) return ERROR;
  // 注意第一个元素是Q->front->next;
  QNode *p = Q->front->next;
  ElemType e = p->data;
  Q->front->next = p->next;
  free(p);
  return e;
}