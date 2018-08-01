// 循环队列，顺序表示

#define MAXSIZE 100
#define ElemType int
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef int Status;

typedef struct {
  ElemType *base;
  int front;
  int rear;
} SqQueue;

Status InitQueue (SqQueue *Q)
{
  Q->base = (ElemType *) malloc(MAXSIZE * sizeof(ElemType));
  if (!Q->base) exit(OVERFLOW);
  Q->front = 0;
  Q->rear = 0;
  return OK;
}

int QueueLength (SqQueue *Q)
{
  return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

Status EnQueue (SqQueue *Q, ElemType e)
{
  if ((Q->rear + 1) % MAXSIZE == Q->front) {
    // 队列满了
    return ERROR;
  }
  Q->base[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  return OK;
}

ElemType DeQueue (SqQueue *Q)
{
  if (Q->rear == Q->front) {
    return ERROR;
  }
  ElemType e = Q->base[Q->front];
  Q->front = (Q->front + 1) % MAXSIZE;
  return e;
}


void printQueueLength (SqQueue *Q)
{
  int length = QueueLength(Q);
  printf("Length of queue is %d\n", length);
}