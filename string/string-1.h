// 字符串

#define OK 1
#define ERROR -1
#define OVERFLOW -2
#include <stdlib.h>
#include <stdio.h>
#define Status int
#include <assert.h>

typedef struct {
  char *ch;
  int length;
} HString;

Status InitHString (HString *s, char ch[]) {
  int length = 0, i = 0;
  while(ch[i++] != '\0') length++;
  s->ch = (char *) malloc(length * sizeof(char) + 1);
  for (i = 0; i < length; i++) {
    s->ch[i] = ch[i];
  }
  s->ch[length] = '\0';
  s->length = length;
  return OK;
}

// 把 string T 插入到 string s 中
Status StrInsert (HString *s, int pos, HString t) {
  if (pos < 0 || pos > s->length) {
    return ERROR;
  }
  if (t.length == 0) return OK;
  s->ch = (char *) realloc(s->ch, (s->length + t.length) * sizeof(char) + 1);
  if (!s->ch) return OVERFLOW;
  for (int i = s->length; i >= pos; i--) {
    s->ch[i + t.length] = s->ch[i];
  }
  for (int j = 0; j < t.length; j++) {
    s->ch[pos + j] = t.ch[j];
  }
  s->length = s->length + t.length;
  return OK;
}

int StrLength (HString S) {
  return S.length;
}

// 比较字符串
int StrCompare(HString S, HString T) {
  int i = 0;
  while(i < S.length && i < T.length && S.ch[i] == T.ch[i]) i++;
  if (i < S.length && i < T.length) {
    return S.ch[i] > T.ch[i] ? 1 : -1;
  } else if (S.length == T.length) {
    return 0;
  } else {
    return S.length > T.length ? 1 : -1;
  }
}
// 上面的函数写的太烂了吧
int GoodStrCompare (HString S, HString T) {
  for (int i = 0; i < S.length && i < T.length; i++) {
    if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
  }
  return S.length - T.length;
}

Status ClearString(HString *S) {
  S->length = 0;
  free(S->ch);
  return OK;
}

Status Concat (HString *T, HString S1, HString S2) {
  T->ch = (char *) malloc(S1.length + S2.length + 1);
  if (!T->ch) return OVERFLOW;
  for (int i = 0; i < S1.length; i++) {
    T->ch[i] = S1.ch[i];
  }
  for (int j = 0; j <= S2.length; j++) {
    T->ch[S1.length + j] = S2.ch[j];
  }
  return OK;
}

Status SubString (HString *Sub, HString S, int pos, int len) {
  if (pos < 0 || pos >= S.length || len < 0 || len > S.length - pos)
    return ERROR;
  if (Sub->ch) free(Sub->ch);
  if (len == 0) {
    Sub->ch = NULL;
    Sub->length = 0;
  } else {
    Sub->ch = (char *) malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
      Sub->ch[i] = S.ch[i + pos];
    }
    Sub->length = len;
  }
  return OK;
}
