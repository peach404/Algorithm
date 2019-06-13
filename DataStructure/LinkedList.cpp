#include <stdlib.h>
#include <stdio.h>
//출처 https://luckyyowu.tistory.com/324

typedef struct list {
    struct node *cur;
    struct node *head;
    struct node *tail;
} linkedList;

typedef struct node {
    int data;
    struct node *next;
} node;

node * getNode(linkedList * L,int idx){ //특정 인덱스 값 가져오기
    L->cur= L->head;
    while(L->cur !=NULL && idx>0){
        idx--;
        L->cur = L->cur->next;
    }

    return L->cur;
}

void createNode(linkedList *L, int ndata) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = ndata;
    newNode->next = NULL;
    if(L->head == NULL && L->tail == NULL)
        L->head = L->tail = newNode;
    else {
        L->tail->next = newNode;
        L->tail = newNode;
    }

    L->cur = newNode;
}

void deleteLastNode(linkedList *L) {
    node *p = L->head;
    while(p->next->next != NULL) {
        p = p->next;
    }
    p->next = p->next->next;
    L->tail = p;
}

void printNodes(linkedList *L) {
    node *p = L->head;

    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void) {
    //linkedList pointer define start
    linkedList *L = (linkedList *)malloc(sizeof(linkedList));
    L->cur = NULL;
    L->head = NULL;
    L->tail = NULL;
    //linkedList pointer define end

    createNode(L, 1);
    createNode(L, 2);
    createNode(L, 3);
    printNodes(L);
    node * tmp =getNode(L,2);
    printf("%d\n",tmp->data);
    deleteLastNode(L);
    createNode(L, 4);
    createNode(L, 5);
    createNode(L, 6);
    deleteLastNode(L);
    deleteLastNode(L);
    createNode(L, 7);
    printNodes(L);

    return 0;
}

