// 顺序表相关的算法设计题目
// 数据结构习题

#include <stdlib.h>
#include "1.h"

// 将顺序表里的元素逆置，要求空间复杂度O(1)
void reverseList (SqList *L) {
  int i = 0, j = L->length - 1;
  while(i < j) {
    ElemType temp = L->data[i];
    L->data[i] = L->data[j];
    L->data[j] = temp;
    i++;
    j--;
  }
}

// 冒泡排序
void bubleSeq (SqList *L)
{
  int i = 1;
  while(i < L->length) {
    int k = i;
    while(k > 0 && L->data[k - 1] > L->data[k]) {
      ElemType temp = L->data[k - 1];
      L->data[k - 1] = L->data[k];
      L->data[k] = temp;
      k--;
    }
    i++;
  }
}
void bubleSeq_test () {
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  bubleSeq(&L);
  print_arr_m(L.data, L.length);
}

void reverseList_test () {
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  reverseList(&L);
  print_arr_m(L.data, L.length);
}

// 将顺序表里的元素循环左移 p 个单位
void reverse_move(SqList *list, int left, int right) {
    while(left < right) {
      int temp = list->data[left];
      list->data[left] = list->data[right];
      list->data[right] = temp;
      left++;
      right--;
    }
  }
void leftmove (SqList *L, int p)
{
  int i = 0, j = L->length - 1;
  reverse_move(L, i, j);
  reverse_move(L, i, L->length - p - 1);
  reverse_move(L, L->length - p, j);
}
void leftmove_test () {
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  leftmove(&L, 4);
  print_arr_m(L.data, L.length);
}


// 从顺序表中删除值等于 x 的元素， 要求空间复杂度 O(1)
void deleteElem (SqList *L, ElemType x)
{
  int i = 0, k = 0;
  while(i < L->length) {
    if (L->data[i] != x) {
      L->data[k] = L->data[i];
      k++;
    }
    i++;
  }
  L->length = k;
}
void deleteElem_test () 
{
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  deleteElem(&L, 4);
  print_arr_m(L.data, L.length);
}

// 顺序表中删除值在 x 至 y 之间的元素，要求空间复杂度 O(1)
void deleteRange (SqList *L, int min, int max)
{
  int i = 0, k = 0;
  while(i < L->length) {
    if (L->data[i] < min || L->data[i] > max) {
      L->data[k] = L->data[i];
      k++;
    }
    i++;
  }
  L->length = k;
}
void deleteRange_test () 
{
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  deleteRange(&L, 2, 6);
  print_arr_m(L.data, L.length);
}

// 设有一个顺序表L，元素为整数，设计一个算法将 L中所有小于0的整数放前面，大于0的整数放后面
void devide(SqList *L)
{
  int i = 0, j = L->length - 1;
  while(i < j) {
    while(L->data[i] <= 5 && i < j) i++;
    while(L->data[j] > 5 && i < j) j--;
    int temp = L->data[i];
    L->data[i] = L->data[j];
    L->data[j] = temp;
  }
}
void devide_test () {
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  devide(&L);
  print_arr_m(L.data, L.length);
}

// 设计一个算法，从顺序表中删除重复的元素，保持原顺序不变
void delRepeat (SqList *L)
{
  int i = 0, k = 0;
  while(i < L->length) {
    int j = 0;
    while(L->data[j] != L->data[i] && j < k) {
      j++;
    }
    if (j >= k) {
      // 就是没找到相同的
      L->data[k] = L->data[i];
      k++;
    }
    i++;
  }
  L->length = k;
}
void delRepeat_test () {
  SqList L;
  InitList(&L);
  randomList(&L);
  print_arr_m(L.data, L.length);
  delRepeat(&L);
  print_arr_m(L.data, L.length);
}

// 设计一个算法，从 有序的 顺序表中删除重复的元素，保持原顺序不变
void delRepeatSeq (SqList *L)
{
  int i = 1, k = 1;
  while(i < L->length) {
    if (L->data[i - 1] != L->data[i]) {
      L->data[k] = L->data[i];
      k++;
    }
    i++;
  }
  L->length = k;
}
void delRepeatSeq_test () {
  SqList L;
  InitList(&L);
  randomList(&L);
  bubleSeq(&L);
  print_arr_m(L.data, L.length);
  delRepeatSeq(&L);
  print_arr_m(L.data, L.length);
}


// 用顺序表表示集合，设计一个算法求两集合的交集
void interSection (SqList *L1, SqList *L2, SqList *L3)
{
  int i = 0, k = 0;
  while(i < L1->length) {
    int j = 0;
    while(j < L2->length && L2->data[j] != L1->data[i]) j++;
    if (j < L2->length) {
      // 说明有相同的
      L3->data[k] = L1->data[i];
      k++;
    }
    i++;
  }
  L3->length = k;
}
void interSection_test () {
  SqList L1, L2, L3;
  InitList(&L1);
  randomList(&L1);
  delRepeat(&L1);
  print_arr_m(L1.data, L1.length);
  InitList(&L2);
  randomList(&L2);
  delRepeat(&L2);
  print_arr_m(L2.data, L2.length);
  InitList(&L3);
  interSection(&L1, &L2, &L3);
  print_arr_m(L3.data, L3.length);
}


// 用顺序表表示集合，设计一个算法求两集合的并集
void unionSet (SqList *L1, SqList *L2, SqList *L3)
{
  int i = 0, j = 0, k = 0;
  while(i < L1->length) {
    // L1 全部复制过去
    L3->data[k] = L1->data[i];
    i++;
    k++;
  }
  while(j < L2->length) {
    // L2 只复制 L1中没有的
    i = 0;
    while(i < L1->length && L1->data[i] != L2->data[j]) i++;
    if (i == L1->length) {
      // 说明循环完了没找到
      L3->data[k] = L2->data[j];
      k++;
    }
    j++;
  }
  L3->length = k;
}
void unionSet_test () {
  SqList L1, L2, L3;
  InitList(&L1);
  randomList(&L1);
  delRepeat(&L1);
  print_arr_m(L1.data, L1.length);
  InitList(&L2);
  randomList(&L2);
  delRepeat(&L2);
  print_arr_m(L2.data, L2.length);
  InitList(&L3);
  unionSet(&L1, &L2, &L3);
  print_arr_m(L3.data, L3.length);
}


// 用顺序表表示集合，设计一个算法求两集合的差集
void substructSet (SqList *L1, SqList *L2, SqList *L3)
{
  int i = 0, k = 0;
  while(i < L1->length) {
    int j = 0;
    while(j < L2->length && L1->data[i] != L2->data[j]) j++;
    if (j == L2->length) {
      // 查找完毕了没找到相同的
      L3->data[k] = L1->data[i];
      k++;
    }
    i++;
  }
  L3->length = k;
}
void substructSet_test () {
  SqList L1, L2, L3;
  InitList(&L1);
  randomList(&L1);
  delRepeat(&L1);
  print_arr_m(L1.data, L1.length);
  InitList(&L2);
  randomList(&L2);
  delRepeat(&L2);
  print_arr_m(L2.data, L2.length);
  InitList(&L3);
  substructSet(&L1, &L2, &L3);
  print_arr_m(L3.data, L3.length);
}

int main() {
  srand ( time(NULL) );
  substructSet_test();
}
