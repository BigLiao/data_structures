// 算法题目

// 设计一个循环队列，用 front和 rear 分别作为队头和队尾指针，
// 另外用一个 tag 标识队列可能为空（0）或者满（1），用 front==rear 可判断队满还是队空；

#include <stdio.h>
#define ElemType int
#define MAXSIZE 10
#define Status int
#define OK 1
#define ERROR 0

typedef struct {
  ElemType data[MAXSIZE];
  int front, rear;
  int tag;
} QueueLink;

void initQueue (QueueLink *Q) {
  Q->front = Q->rear = 0;
  Q->tag = 0;
}

void printQueue (QueueLink Q) {
  if (Q.tag == 0 && Q.front == Q.rear) return;
  int k = Q.front;
  do {
    printf("%2d->", Q.data[k]);
    k = (k + 1) % MAXSIZE;
  } while (k != Q.rear);
  printf("\n");
}

Status PushQuene (QueueLink *Q, int e) {
  if (Q->front == Q->rear && Q->tag == 1) {
    return ERROR; // 队满
  }
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  // if (Q->rear == Q->front) Q->tag = 1;// 
  Q->tag = 1; // 可能满，不肯能空
  return OK;
}

Status PopQuene (QueueLink *Q, int *e) {
  if (Q->front == Q->rear && Q->tag == 0) {
    // 队空
    return ERROR;
  }
  *e = Q->data[Q->front];
  Q->tag = 0; // 出队一个元素，可能变空！
  Q->front = (Q->front + 1) % MAXSIZE;
  return OK;
}

int main(int argc, char const *argv[])
{
  QueueLink Qu;
  initQueue(&Qu);
  PushQuene(&Qu, 2);
  PushQuene(&Qu, 1);
  PushQuene(&Qu, 3);
  PushQuene(&Qu, 5);
  printQueue(Qu);
  int e;
  PopQuene(&Qu, &e);
  printf("e=%d\n", e);
  printQueue(Qu);
  return 0;
}


