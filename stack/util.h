void print_array (int A[], int n)
{
  printf("[ ");
  for(int i = 0; i < n; ++i) {
    printf("%d,", A[i]);
  }
  printf(" ]\n");
}