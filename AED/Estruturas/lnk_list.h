#ifndef _LLIST_H
#define _LLIST_H
#ifdef _LLIST_C

typedef struct E E;

typedef struct list List;

void clear(List* l);
void insert(List* l, E item);
void append(List* l, E item);
E remove(List* l);
void moveToStart(List *l);
void moveToEnd(List *l);
void prev(List *l);
void next(List *l);
int legth(List *l);
int currPos(List *l);
void moveToPos(List *l, int pos);
E getValue(List *l);

#endif
#endif