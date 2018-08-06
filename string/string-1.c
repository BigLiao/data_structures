#include "./string-1.h"

int main(int argc, char const *argv[])
{
  HString s1;
  InitHString(&s1, "31Aabc");
  HString t;
  InitHString(&t, "2bcd");
  int c = StrCompare(s1, t);
  
  return 0;
}
