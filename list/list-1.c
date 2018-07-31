// 顺序表算法
#include <stdio.h>
#include "list-1.h"


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


