// 算法题目,KMP 算法
#include "./string-1.h"
#define MAXSIZE 20

void generateNext (HString Str, int next[]);
void getNext (HString Str, int next[]);
// 在 Str 中查找 subStr，找到了就返回所在位置，找不到就返回-1
int searchString (HString Str, HString subStr) {
  int next[MAXSIZE], i, j;
  getNext(subStr, next);
  i = 0; j = 0;
  while(i < Str.length && j < subStr.length) {
    if (Str.ch[i] == subStr.ch[j] || j == -1) {
      i++; j++;
    } else {
      j = next[j];
    }
  }
  if (j >= subStr.length)
    return i - subStr.length;
  else
    return -1;
}

// 计算 next 值
void generateNext (HString Str, int next[]) {
  next[0] = -1;
  next[1] = 0;
  for (int i = 2; i < Str.length; i++) {
    int k = next[i - 1]; // 在前一个的基础上比较
    if (Str.ch[i - 1] == Str.ch[k]) {
      k++;
    } else if (Str.ch[i - 1] == Str.ch[0]) {
      k = 1;
    } else {
      k = 0;
    }
    next[i] = k;
  }
}

// 书上的，太屌了
void getNext (HString Str, int next[]) {
  int j, k;
  j = 0; k = -1; next[0] = -1;
  while (j < Str.length - 1) {
    if (k == -1 || Str.ch[j] == Str.ch[k]) {
      j++; k++;
      next[j] = k;
    } else k = next[k];
  }
}

int main(int argc, char const *argv[])
{
  HString S;
  InitHString(&S, "asd1231e21abcabcde32131232213");
  HString t;
  InitHString(&t, "abcabcde");
  int x = searchString(S, t);
  printf("result is %d\n", x);
  return x;
}
