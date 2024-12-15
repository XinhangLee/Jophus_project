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

void SitAroundCircle(Linklist *list,const int num) {
    for (int i = 1; i <= num; ++i) {
        Append(list,i);
    }
}

void KillUntilOne(Linklist *list) {
    Node *node = list->head;

    while (!IsSingleton(list)) {
        Delete(list,node);
        node = node->next;
    }
}

int GetSurvivor(Linklist *list) {
    return GetHeadVal(list);
}