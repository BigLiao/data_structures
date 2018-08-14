// 广义表

#define OK 1
#define ERROR -1
#define OVERFLOW -2
#include <stdlib.h>
#include <stdio.h>
#define Status int
#define AtomType int

// 头尾链表储存表示
typedef enum {ATOM, LIST} ElemTag;
typedef struct GLNode {
  ElemTag tag;
  union {
    AtomType atom;
    struct {
      struct GLNode *hp, *tp;
    } ptr;
  };
} *GList;

// 广义表的扩展线性链表储存表示
typedef struct GLNode2 {
  ElemTag tag;
  union {
    AtomType atom;
    struct GLNode2 *hp;
  };
  struct GLNode2 *tp;
} *GList2;