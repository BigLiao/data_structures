// 双链表

#include <stdio.h>
#define ElemType int
#define OK 1
#define ERROR -1

typedef struct DLinkList
{
  ElemType data;
  struct DLinkList *next;
  struct DLinkList *prior;
} DLinkList;

// 创建双链表，头插法
void CreateDListF(DLinkList *L, ElemType m[], int n)
{
  DLinkList *s; int i;
  L = (DLinkList *) malloc(sizeof(DLinkList));
  L->next = L->prior = NULL;
  for (i = 0; i < n; i++) {
    s = (DLinkList *) malloc(sizeof(DLinkList));
    s->prior = L;
    s->data = m[i];
    s->next = L->next;
    if (L->next != NULL) {
      L->next->prior = s;
    }
    L->next = s;
  }

}

int main () {
}