// 递归算法 题目

#include <stdio.h>
#include "./util.h"
#define ERROR 0
#define OK 1

// 用递归算法求数组 A中的最大元素
// n 是长度
int findMax(int A[], int n)
{
  if (1 == n) return 0;
  int m = findMax(A, n - 1); // 找到前 n-1个的最大元素
  if (A[m] < A[n - 1]) {
    return n - 1;
  } else {
    return m;
  }
}
void test_findMax()
{
  int A[] = {2,4,6,3,4,7,8,0};
  int max = findMax(A, 8);
  print_array(A, 8);
  printf("max of A is A[%d] = %d\n", max, A[max]);
  int A2[] = {33,4,4,30,410,0,18,0,1,1,1,1,1};
  int max2 = findMax(A2, 13);
  print_array(A2, 13);
  printf("max of A is A2[%d] = %d\n", max2, A2[max2]);
}


// 用递归算法求 n个不同字符的全排列
void perm (char str[], int k, int n)
{
  int i, j;
  char tmp;
  if (k == n - 1) {
    for (j = 0; j < n; j++)
      printf("%c", str[j]);
    printf("\n");
  } else {
    for (i = k; i < n; i++) {
      tmp = str[k];
      str[k] = str[i];
      str[i] = tmp;
      perm(str, k+1, n);
      tmp = str[i];
      str[i] = str[k];
      str[k] = tmp;
    }
  }
}
void test_perm () 
{
  char str[] = "abcd";
  perm(str, 0, 4);
}


// 组合问题：
// 从自然数1、2、3……、m 中任取 k 个数的所有组合
void comb (int a[], int m, int k)
{
  if (k == 1) {
    for (int j = 0; j < m; j++) {
      a[0] = j+1;
      printf("结果：");
      print_array(a, 3);
    }
  } else {
    for (int i = m; i >= k; i--) {
      a[k - 1] = i;
      comb(a, i - 1, k - 1);
    }
  }
}
void test_comb () {
  int a[3];
  comb(a, 5, 3);
}

// N皇后问题：
// 在 n*n 的棋盘上，放置 n 个皇后，求每个皇后不同行、不同列、不同斜对角线
void queen (int n)
{
  if (n > 20) return;
  int q[20]; // 存放每行皇后所在的列号
  

}
void place (int k, int n) {
  // 放置函数，用于递归
  if (k == n) {

  }
}

int main(int argc, char const *argv[])
{
  test_comb();
  return 0;
}
