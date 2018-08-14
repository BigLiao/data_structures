// 例题4-2-22

#include <stdio.h>
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0
#define MAXSIZE 5

typedef struct {
  int front, rear;
  ElemType data[MAXSIZE];
} Queue;

void InitQueue (Queue *Q) {
  Q->front = Q->rear = -1;
}

int QueueIsFull (Queue *Q) {
  if (Q->front = (Q->rear + 1) % MAXSIZE) {
    printf("queue is full\n");
    return 1;
  } else {
    return 0;
  }
}

int QueueIsEmpty (Queue *Q) {
  if (Q->front = Q->rear) {
    printf("queue is empty\n");
    return 1;
  } else {
    return 0;
  }
}


Status EnQueue (Queue *Q, ElemType e) {
  if (QueueIsFull(Q)) return ERROR;
  Q->rear = (Q->rear + 1) % MAXSIZE;
  Q->data[Q->rear] = e;
  return OK;
}

Status DeQueue (Queue *Q, ElemType *e) {
  if (QueueIsEmpty(Q)) return ERROR;
  Q->front = (Q->front + 1) % MAXSIZE;
  *e = Q->data[Q->front];
}

int QueueLength (Queue *Q) {
  return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

Status DelQueue_ (Queue *Q, int k) { // 垃圾💩
  // 删除第k 个元素，k 从 1 开始
  if (k < 1 || k > QueueLength(Q)) return ERROR;
  Queue tempQu;
  InitQueue(&tempQu);
  while(!QueueIsEmpty(Q)) {
    int m;
    DeQueue(Q, &m);
    EnQueue(&tempQu, m);
  }
  int i = 0;
  while(!QueueIsEmpty(&tempQu)) {
    i++;
    if (i == k) continue;
    int n;
    DeQueue(&tempQu, &n);
    EnQueue(Q, n);
  }
} // 妈的，垃圾算法！出队之后可以立即进队！！！

Status DelQueue (Queue *Q, int k) {
  // 改进上述算法
  if (k < 1 || k > QueueLength(Q)) return ERROR;
  int length = QueueLength(Q);
  for (int i = 1; i <= length; i++) {
    int e;
    DeQueue(Q, &e);
    if (i != k) {
      EnQueue(Q, e);
    }
  }
}
