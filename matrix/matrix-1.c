#include "./matrix-1.h"

int main(int argc, char const *argv[])
{
  TSMatrix T;
  CreateTSMatrix(&T);
  PrintMatrix(&T);
  TSMatrix S;
  CreateTSMatrix( &S);
  PrintMatrix(&S);
  TSMatrix M;
  MutipleSMatrix(T, S, &M);
  PrintMatrix(&M);
  return 0;
}
