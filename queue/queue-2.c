// 银行排队事件模拟
// 数据结构3-5
#include "./queue-2.h"

typedef struct {
  int OccurTime;
  int NType;
} Event;

#undef ElemType
#define ElemType Event

int main(int argc, char const *argv[])
{
  ElemType x;
  SqQueue SQ;
  InitQueue(&SQ);
  return 0;
}
