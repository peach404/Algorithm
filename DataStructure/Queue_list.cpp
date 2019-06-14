//
// Created by 김소연 on 14/06/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *next;
};

typedef struct Queue{
    Node * front;
    Node * rear;
    int cnt;
};
void QInit(Queue *q){
    q->front = q->rear = NULL;
    q->cnt = 0;
}
int IsEmpty(Queue *q){
    if(q->cnt == 0){
        return 1;
    }else
        return 0;

}
void QPush(Queue * q,int num){
    Node *p =(Node *)malloc(sizeof(Node));
    p->data = num;
    p->next = NULL;

    if(IsEmpty(q)){
        q->front = p;
        q->rear = p;
    }else {
        q->rear->next = p;
        q->rear = p;
    }
    q->cnt++;
}
void QPop(Queue *q){
    Node *p;
    if(!IsEmpty(q)) {
        p = q->front;
        q->front = q->front->next;
        free(p);
        q->cnt--;
    }
}
void Print(Queue *q){
    Node *p;
    p = q->front;

    for(int i=0;i<q->cnt;i++){
        printf("%d\n",p->data);
        p = p->next;
    }
}

int main(void){

    Queue q;
    QInit(&q);
    QPush(&q,5);
    QPush(&q,6);
    QPush(&q,7);
    QPush(&q,8);
    QPush(&q,9);
    Print(&q);
    QPop(&q);
    Print(&q);



    return 0;
}
