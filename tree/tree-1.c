#include "./tree-1.h"

void testCreate () {
  BiTree T;
  CreateBiTree(&T);
  printf("ttttt\n");
}
void testCreate2 () {
  char *s = "ABC  DE G  F   ";
  /*
    A
    |
    B ---
    |    |
    C    D ---------
         |          |
         E --- G    F
  */
  BiTree T;
  CreateBiTree2(&T, &s);
  printf("success\n");
}
Status print (char ch) {
  printf("---");
  printf("%c->", ch);
  return OK;
}
void testInorder () {
  char *s = "ABC  DE G  F   ";
  BiTree T;
  CreateBiTree2(&T, &s);
  // CreateBiTree(&T);
  InOrderTraverse(T, print);
  printf("\n");
  InOrderTraverse2(T, print);
}

int main(int argc, char const *argv[])
{
  testInorder();
  return 0;
}
