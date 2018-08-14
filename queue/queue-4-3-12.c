// 算法题目
// 设有 MaxSize 个连续单元供一个栈和一个队列使用，且栈和队列的实际占用单元数事先并不知道，但是一共不能超过 MaxSize ，设计这一的栈和队列

#include <stdio.h>
#define OK 1
#define ERROR 0
#define Status int
#define ElemType int
#define MaxSize 20

// 采用静态链结构
typedef struct {
  ElemType data;
  int next;
} Node;

Node S[MaxSize];
void Init () {
  // S[0]存储一个可用节点的链头
  for (int i = 0; i < MaxSize - 1; i++) {
    S[i].next = i + 1;
  }
  S[MaxSize - 1].next = -1;
  S[0].data = MaxSize; // s[0]存储可用空间
}

int getSpace () {
  if (S[0].data < 1) return ERROR; // 空间用完了！
  int space = S[0].next;
  S[0].next = S[space].next;
  S[0].data--;
  return space;
}
Status freeSpace (int k) {
  // 释放空间
  S[k].next = S[0].next;
  S[0].next = k;
  S[0].data++;
  return OK;
}

typedef struct {
  int base, top;
} Stack; // 栈
typedef struct {
  int front, rear;
} Queue; // 队列

void InitStack (Stack *St) {
  St->base = St->top = -1;
}

Status EnStack (Stack *St, ElemType e) {
  int k = getSpace();
  if (!k) return ERROR;
  if (St->base == -1) {
    // 如果是第一个元素
    St->base = k;
    St->top = k;
    S[k].data = e;
  } else {
    S[k].data = e;
    S[k].next = St->top;
    St->top = k;
  }
  return OK;
}

Status DeStack (Stack *St, ElemType *e) {
  if (St->base == -1) return ERROR;
  int k = St->top;
  *e = S[k].data;
  if (St->top == St->base) {
    // 如果现在只有一个元素，应该置空
    St->top = St->base = -1;
  } else {
    St->top = S[k].next;
  }
  freeSpace(k);
  return OK;
}


void InitQueue (Queue *Qu) {
  Qu->front = Qu->rear = -1;
}

Status EnQueue (Queue *Qu, ElemType e) {
  int k = getSpace();
  if (!k) return ERROR;
  if (Qu->front == -1) {
    // 队列为空
    Qu->front = Qu->rear = k;
  } else {
    S[Qu->rear].next = k;
    Qu->rear = k;
  }
  S[Qu->rear].data = e;
  return OK;
}

Status DeQuque (Queue *Qu, ElemType *e) {
  if (Qu->rear == -1) return ERROR; // 队列为空
  int t = Qu->front;
  *e = S[t].data;
  if (Qu->front == Qu->rear) {
    // 只有一个元素，应该弹出并置空队列
    Qu->front = Qu->rear = -1;
  } else {
    Qu->front = S[t].next;
  }
  freeSpace(t);
  return OK;
}


int main(int argc, char const *argv[])
{
  Init();
  Stack St;
  InitStack(&St);
  EnStack(&St, 7);
  EnStack(&St, 2);
  EnStack(&St, 5);
  EnStack(&St, 9);
  Queue Qu;
  InitQueue(&Qu);
  EnQueue(&Qu, 12);
  EnQueue(&Qu, 13);
  int x;
  DeStack(&St, &x);
  printf("x=%d\n", x);
  DeStack(&St, &x);
  printf("x=%d\n", x);
  DeStack(&St, &x);
  printf("x=%d\n", x);
  EnQueue(&Qu, 14);
  EnStack(&St, 7);
  EnStack(&St, 2);
  EnStack(&St, 5);
  printf("a=a?%s\n", "abc");
  return 0;
}
