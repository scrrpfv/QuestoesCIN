#ifndef _LIST_H
#define _LIST_H

typedef struct E E;

typedef struct list List;
List* create_list(int size);
void clear(List* l);
void insert(List* l, E item);
void append(List* l, E item);
E remove(List* l);
void moveToStart(List l);
void moveToEnd(List l);
void prev(List l);
void next(List l);
int legth(List l);
int currPos(List l);
void moveToPos(List l, int pos);
E getValue(List l);

#endif