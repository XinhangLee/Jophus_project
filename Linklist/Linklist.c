//
// Created by lixh1 on 24-12-14.
//
//functions on linker list (implementations).
#include"Linklist.h"
#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>


void Init(Linklist *list) {
    list->head = NULL;
    list->tail = NULL;
}


bool IsEmpty(Linklist *list) {
    return list->head == NULL;
}

int GetHeadVal(Linklist *list) {
    return list->head->index;
}

void Print(Linklist *list) {
    if (IsEmpty(list)) {
        return;
    }

    Node const *node = list->head;

    do {
        printf("%d ", node->index);
        node = node->next;
    } while (node != list->head);
    printf("\n");
}

void Append(Linklist *list, const int index){
    Node *node = malloc(sizeof *node);
    if(node == NULL) {
        return;
    }
    node->index = index;

    if (IsEmpty(list)) {
        list->head = node;
    }else{
        list->tail->next = node;
    }
    list->tail = node;
    list->tail->next = list->head;
}

bool IsSingleton(Linklist *list) {
    return !IsEmpty(list) && list->head == list->tail;
}


void Delete(Linklist *list, Node *prev) {
    if (IsEmpty(list)) {
        return;
    }

    if (IsSingleton(list)) {
        free(list->head);
        Init(list);
        return;
    }

    Node *cur = prev->next;
    Node *next = cur->next;

    prev->next = next;

    if (cur == list->head) {
        list->head = next;
    }

    if (cur == list->tail) {
        list->tail = prev;
    }
    free(cur);
}

