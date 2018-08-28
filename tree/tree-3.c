#include "./tree-3.h"

void test_create () {
  BTNode *tree, *tree2;
  char *preorder = "ABDGCEF";
  char *inorder = "DGBAECF";
  char *postorder = "GDBEFCA";
  tree = CreateBTree1(preorder, inorder, 7);
  tree2 = CreateBTree2(postorder, inorder, 7);
  printf("ok\n");
}

int main(int argc, char const *argv[])
{
  test_create();
  return 0;
}
