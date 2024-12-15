//
// Created by lixh1 on 24-12-14.
//
//functions on linker list (implementations).
#include"Linklist.h"
#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>

//初始化链表。
void Init(Linklist *list) {
    list->head = NULL;
    list->tail = NULL;
}

//将新节点添加到链表尾部。
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

//删除指定节点，模拟“杀戮”过程。
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

//打印链表中所有人的编号。
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

//检查链表是否为空。
bool IsEmpty(Linklist const *list) {
    return list->head == NULL;
}

//检查链表是否只有一个元素。
bool IsSingleton(Linklist *list) {
    return !IsEmpty(list) && list->head == list->tail;
}

//获取存活者编号。
int GetHeadVal(Linklist const *list) {
    return list->head->index;
}