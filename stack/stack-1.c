#include "./stack-1.h"

// 数制转换，用整除法将十进制转换成八进制
void conversion ()
{
  // 输入任意十进制数，将它转换成八进制
  printf("请输入一个十进制数:");
  int input;
  scanf("%d", &input);
  SqStack S;
  InitStack(&S);
  int m, n;
  m = input;
  while(m) {
    n = m % 8;
    m = (int) m / 8;
    PushStack(&S, n);
  }
  printf("\n 得到八进制数为：");
  while(!StackEmpty(&S)) {
    printf("%d", PopStack(&S));
  }
}

// 对输入字符串中的 () [] 是否成对进行检查
int parenthesisChecker (char *str)
{
  SqStack S;
  InitStack(&S);
  char *p = str;
  while(*p != '\0') {
    if (*p == '(' || *p == '[') {
      PushStack(&S, (int) *p);
    } else if (*p == ')') {
      int q = PopStack(&S);
      if (q != '(') {
        printf("string is lack of %c\n", '(');
        return 0;
      }
    } else if (*p == ']') {
      int q = PopStack(&S);
      if (q != '[') {
        printf("string is lack of %c\n", '[');
        return 0;
      }
    }
    p++;
  }
  if (StackEmpty(&S)) {
    printf("string is ok\n");
    return 1;
  } else {
    printf("the %c has no compare\n", GetTop(&S));
    return 0;
  }
  
}

int main() {
  // conversion();
  char *s = "([)";
  parenthesisChecker(s);
}