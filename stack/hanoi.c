// 汉诺塔问题

#include <stdio.h>

// 计数用
int count = 0;

// 移动函数
void move (int n, char from, char to)
{
  printf("%d: move %d from %c to %c\n", ++count, n, from, to);
}

void hanoi (int n, char x, char y, char z)
{
  if (n == 1) {
    move(n, x, z);
  } else {
    hanoi(n - 1, x, z, y);
    move(n, x, z);
    hanoi(n - 1, y, x, z);
  }
}

int main()
{
  /* code */
  hanoi(9, 'A', 'B', 'C');
  return 0;
}
