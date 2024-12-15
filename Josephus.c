//
// Created by lixh1 on 24-12-14.
//
#include<stdio.h>
#include"Linklist/Linklist.h"


#define NUM 12

void SitAroundCircle(Linklist *list,int num);
void KillUntilOne(Linklist *list);
int GetSurvivor(Linklist *list);

int main(){
    printf("I hate Josephus game!\n");

    Linklist list;
    Init(&list);

    SitAroundCircle(&list,NUM);
    Print(&list);

    KillUntilOne(&list);
    const int survivor = GetSurvivor(&list);

    printf("num : survivor = %d : %d\n",NUM,survivor);

    return 0;
}

//将 n 个人按顺序加入到循环链表中。
void SitAroundCircle(Linklist *list,const int num) {
    for (int i = 1; i <= num; ++i) {
        Append(list,i);
    }
}

//模拟约瑟夫环的“杀戮”过程，直到剩下一个人。
void KillUntilOne(Linklist *list) {
    Node *node = list->head;

    while (!IsSingleton(list)) {
        Delete(list,node);
        node = node->next;
    }
}

//返回最后剩下的人的编号。
int GetSurvivor(Linklist *list) {
    return GetHeadVal(list);
}