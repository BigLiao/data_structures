// 稀疏矩阵储存

#define OK 1
#define ERROR -1
#define OVERFLOW -2
#include <stdlib.h>
#include <stdio.h>
#define Status int
#define MAXSIZE 10000
#define ElemType int

typedef struct {
  int i, j;
  ElemType e;
} Triple; // 三元组

typedef struct {
  Triple data[MAXSIZE + 1];
  int mu, nu, tu; // 矩阵的行数、列数、非零元个数
} TSMatrix;

Status CreateTSMatrix (TSMatrix *T) {
  // 输入数字作为矩阵
  printf("请输入矩阵的行数和列数:\n");
  int m = 0, n = 0, tu = 0;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    printf("输入第%d行：", i + 1);
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      if (x != 0) {
        Triple t = {i, j, x};
        T->data[tu++] = t;
      }
    }
    printf("\n");
  }
  printf("输入完成\n");
  T->mu = m;
  T->nu = n;
  T->tu = tu;
  return OK;
}

Status PrintMatrix (TSMatrix *T) {
  int m = 0, n = 0, t = 0;
  for (int i = 0; i < T->mu; i++) {
    for (int j = 0; j < T->nu; j++) {
      if (T->data[t].i == i && T->data[t].j == j) {
        printf("%5d", T->data[t].e);
        t++;
      } else {
        printf("%5d", 0);
      }
    }
    printf("\n");
  }
  printf("打印完成!\n");
  return OK;
}

// 矩阵的转置
// 算法 1，时间复杂度为 mu*tu
Status TransposeSMatrix (TSMatrix M, TSMatrix *T) {
  T->mu = M.nu; T->nu = M.mu; T->tu = M.tu;
  int q = 0;
  for (int i = 0; i < T->mu; i++) {
    for (int t = 0; t < M.tu; t++) {
      if (M.data[t].j == i) {
        T->data[q].e = M.data[t].e;
        T->data[q].i = M.data[t].j; T->data[q].j = M.data[t].i;
        q++;
      }
    }
  }
  return OK;
}

// 算法2
Status TransposeSMatrix2 (TSMatrix M, TSMatrix *T) {

}

// 矩阵乘法
Status MutipleSMatrix (TSMatrix M, TSMatrix N, TSMatrix *T) {
  if (M.nu != N.mu) return ERROR;
  T->mu = M.mu; T->nu = N.nu; T->tu = 0;
  for (int I = 0; I < T->mu; I++) {
    for (int J = 0; J < T->nu; J++) {
      int Tij = 0;
      for (int s = 0; s < M.nu; s++) {
        int Ms = 0, Ns = 0;
        for (int m = 0; m < N.tu; m++) {
          if (M.data[m].i == I && M.data[m].j == s) {
            Ms = M.data[m].e;
            break;
          }
        }
        for (int n = 0; n < N.tu; n++) {
          if (N.data[n].j == J && N.data[n].i == s) {
            Ns = N.data[n].e;
            break;
          }
        }
        Tij += Ms * Ns;
      }
      if (Tij != 0) {
        T->data[T->tu].i = I; T->data[T->tu].j = J;
        T->data[T->tu].e = Tij;
        T->tu++;
      }
    }
  }
  return OK;
}
// 这个算法复杂度爆表啊。。。（mu * nu * nu2 * 2tu）