// 求解迷宫问题
#include "./stack-1.h"

// 构造一个迷宫，1代表墙，0代表通道
// 入口为[2][2]，出口为[8][8]
int maze[10][10] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
  { 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
  { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

// typedef struct {
//   int i; // 行号
//   int j; // 列号
//   int di; // 下一步的方位，上右下左分别用 0,1,2,3表示，顺时针
// } SElemType;

// #undef ElemType
// #define ElemType SElemType

Status MazePath (int i1, int j1, int i2, int j2)
{
  SqStack mazeStack;
  int i, j, di, find;
  InitStack(&mazeStack);
  SElemType enter = {i1, j1, -1};
  PushStack(&mazeStack, enter);
  int x = 10000;
  while(!StackEmpty(&mazeStack)) {
    if (x-- == 0) return ERROR;
    SElemType *top;
    GetTop(&mazeStack, &top);
    i = top->i; j = top->j; di = top->di;
    if (i == i2 && j == j2) {
      // 找到出口了
      printf("找到出口了哈哈哈\n");
      while(mazeStack.base <= mazeStack.top) {
        printf("\t(%d,%d)", mazeStack.base->i, mazeStack.base->j);
        mazeStack.base++;
      }
      printf("\n");
      return OK;
    }
    find = 0; // 存在下一个块
    while(di < 4 && find == 0) {
      di++;
      switch(di) {
        case 0:
          i = top->i - 1; j = top->j; break;
        case 1:
          j = top->j + 1; i = top->i; break;
        case 2:
          i = top->i + 1; j = top->j; break;
        case 3:
          j = top->j - 1; i = top->i; break;
      }
      if (maze[i][j] == 0) find = 1;
    }
    if (find == 1) {
      top->di = di;
      SElemType e = {i, j, -1};
      PushStack(&mazeStack, e);
      printf("前进(%d, %d)\n", i, j);
      maze[i][j] = -1;
    } else {
      // 找遍了所有方向都没有路了
      maze[top->i][top->j] = 0;
      printf("退回(%d, %d)\n", top->i, top->j);
      PopStack(&mazeStack);
    }
  }
  printf("找不到出路\n");
  return OK;
}

// 改进算法, 求最短路径
Status MazePathMin (int i1, int j1, int i2, int j2)
{
  SqStack mazeStack, minStack;
  InitStack(&mazeStack);
  InitStack(&minStack);
  int i, j, di, find;
  int resultCount = 0;
  SElemType enter = {i1, j1, -1};
  PushStack(&mazeStack, enter);
  int x = 10000;
  while(!StackEmpty(&mazeStack)) {
    if (x-- == 0) return ERROR;
    SElemType *top;
    GetTop(&mazeStack, &top);
    i = top->i; j = top->j; di = top->di;
    if (i == i2 && j == j2) {
      // 找到出口了
      printf("找到出口%d\n", ++resultCount);
      printf("sizeof mazestack is %d\n", StackLength(&mazeStack));
      maze[top->i][top->j] = 0;
      PopStack(&mazeStack);
    }
    find = 0; // 存在下一个块
    while(di < 4 && find == 0) {
      di++;
      switch(di) {
        case 0:
          i = top->i - 1; j = top->j; break;
        case 1:
          j = top->j + 1; i = top->i; break;
        case 2:
          i = top->i + 1; j = top->j; break;
        case 3:
          j = top->j - 1; i = top->i; break;
      }
      if (maze[i][j] == 0) find = 1;
    }
    if (find == 1) {
      top->di = di;
      SElemType e = {i, j, -1};
      PushStack(&mazeStack, e);
      // printf("前进(%d, %d)\n", i, j);
      maze[i][j] = -1;
    } else {
      // 找遍了所有方向都没有路了
      maze[top->i][top->j] = 0;
      // printf("退回(%d, %d)\n", top->i, top->j);
      PopStack(&mazeStack);
    }
  }
  if (StackLength(&minStack) == 0) {
    printf("找不到出路\n");
  } else {
    printf("一共找到%d个路径，其中最短路径是\n", resultCount);
    while(mazeStack.base <= mazeStack.top) {
      printf("\t(%d,%d)", mazeStack.base->i, mazeStack.base->j);
      mazeStack.base++;
    }
    printf("\n");
  }
  
  return OK;
}

int main(int argc, char const *argv[])
{
  MazePathMin(1, 1, 8, 8);
  return 0;
}



