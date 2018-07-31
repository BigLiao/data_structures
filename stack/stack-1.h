
#define STACK_INIT_SIZE 50
#define STACK_INCREMENT 10
#define ElemType int
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef int Status;

typedef struct {
  ElemType *top;
  ElemType *base;
  int stacksize;
} SqStack;

Status InitStack (SqStack *S)
{
  ElemType *a;
  a = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
  if (!a) exit(OVERFLOW);
  S->base = a;
  S->top = S->base;
  S->stacksize = STACK_INIT_SIZE;
  return OK;
}

ElemType GetTop (SqStack *S)
{
  if(S->top == S->base) return ERROR;
  return *(S->top - 1);
}

Status PushStack (SqStack *S, ElemType e)
{
  if (S->top - S->base >= S->stacksize) {
    // 空间不够要继续分配
    S->base = (ElemType *) realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(ElemType));
    if (!S->base) exit(OVERFLOW);
    S->stacksize += STACK_INCREMENT;
  }
  *S->top++ = e;
  return OK;
}

ElemType PopStack (SqStack *S) 
{
  if (S->base == S->top) return ERROR;
  return *(--S->top);
}

int StackEmpty (SqStack *S)
{
  if (S->top == S->base) return 1;
  else return 0;
}

