// 顺序表算法

#include <stdio.h>
#define MaxSize 50
#define ElemType int
#define OK 1
#define ERROR -1

typedef struct
{
  ElemType data[MaxSize];
  int length;
} SqList; // 声明顺序表的类型

void InitList (SqList *L) 
{
  L->length = 0;
}

//返回表中指定元素
ElemType GetElem(SqList *L, int i)
{
  if (i < 0 || i >= L->length) return ERROR;
  return L->data[i];
}

// 按元素查找位置
int LocateElem(SqList *L, ElemType e)
{
  int i = 0;
  while(i < L->length && L->data[i] != e) i++;
  if (L->data[i] == e) {
    return i;
  }
  return ERROR;
}

// 插入数据
int ListInsert(SqList *L, int i, ElemType e)
{
  if (i < 0 || i > L->length) return ERROR;
  if (L->length == i) {
    L->data[i] = e;
    L->length++;
    return OK;
  }
  int r = L->length - 1; // 最后一个
  while(r >= i && r != 0) {
    L->data[r+1] = L->data[r];
    --r;
  }
  L->data[r] = e;
  L->length++;
  return OK;

}

// 删除元素
int ListDelete(SqList *L, int i)
{
  if (i < 0 || i >= L->length) return ERROR;
  for (int j = i; j < L->length - 1; j++) {
    L->data[j] = L->data[j+1];
  }
  L->length--;
  return OK;
}

//有序顺序表并归
void Merge(SqList *L1, SqList *L2, SqList *L3)
{
  // 把有序的 L1 和 L2 合并成 L3
  int i = 0, j = 0, k = 0;
  while (i < L1->length && j < L2->length) {
    if (L1->data[i] < L2->data[j]) {
      L3->data[k] = L1->data[i];
      ++i;
    } else {
      L3->data[k] = L2->data[j];
      ++j;
    }
    ++k;
  }
  while (i == L1->length && j < L2->length) {
    L3->data[k++] = L2->data[j++];
  }
  while (i < L1->length && j == L2->length) {
    L3->data[k++] = L1->data[i++];
  }
  L3->length = k;
}

void print_arr_m(int L[], int len)
{
  int length = (int) sizeof(*L) / sizeof(L[0]);
  printf("[ ");
  for (int i = 0; i < len; i++) {
    printf(" %d ", L[i]);
  }
  printf(" ]\n");
}

int main() {
  SqList L;
  InitList(&L);
  ListInsert(&L, 0, 100);
  ListInsert(&L, 1, 101);
  ListInsert(&L, 2, 102);
  ListInsert(&L, 3, 103);

  print_arr_m(L.data, L.length);
  ListDelete(&L, 2);
  print_arr_m(L.data, L.length);
  SqList L1, L2, L3;
  InitList(&L1);
  InitList(&L2);
  InitList(&L3);
  ListInsert(&L1, 0, 3);
  ListInsert(&L1, 1, 4);
  ListInsert(&L1, 2, 7);
  ListInsert(&L1, 3, 9);
  ListInsert(&L1, 4, 39);
  printf("L1:\n");
  print_arr_m(L1.data, L1.length);
  ListInsert(&L2, 0, 5);
  ListInsert(&L2, 1, 10);
  ListInsert(&L2, 2, 15);
  ListInsert(&L2, 3, 20);
  printf("L2:\n");
  print_arr_m(L2.data, L2.length);
  Merge(&L1, &L2, &L3);
  printf("L3:\n");
  print_arr_m(L3.data, L3.length);
  return OK;
}


