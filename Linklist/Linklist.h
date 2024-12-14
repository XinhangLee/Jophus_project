//
// Created by lixh1 on 24-12-14.
//

#ifndef LINKLIST_H
#define LINKLIST_H

//TODO:adding your code here.
#include <stdbool.h>
//(1) define data type:linklist (circular).

typedef struct node {
    int index;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} Linklist;


//(2) functions on linked list (declarations).
void Init(Linklist *list);
void Append(Linklist *list,int index);

bool IsEmpty(Linklist *list);
bool IsSingleton(Linklist *list);

void Print(Linklist *list);
void Delete(Linklist *list,Node *prev);

int GetHeadVal(Linklist *list);

#endif //LINKLIST_H
