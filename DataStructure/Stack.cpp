//
// Created by 김소연 on 13/06/2019.
//

#include <stdio.h>


struct STACK{

    int arr[100];
    int topidx;
};
void Init(STACK *nstack){
    nstack ->topidx = -1;
}

bool Isempty(STACK *nstack){
    if(nstack->topidx == -1)
        return true;
    else
        return false;
}

bool Isfull(STACK *nstack){
    if(nstack->topidx >100)
        return true;
    else
        return false;
}

int Peek(STACK *nstack){
    if(Isempty(nstack)) return -1;
    else
        return nstack->arr[nstack->topidx];
}

void Push(STACK *nstack , int data){
    if(Isfull(nstack)) printf("스택이 가득 찼습니다.\n");
    else
    {
        nstack->topidx += 1;
        nstack->arr[nstack->topidx] = data;
    }

}

void Pop(STACK *nstack){
    if(Isempty(nstack)) printf("스텍이 비었습니다.\n");
    else{
        nstack ->topidx -=1;
    }
}

int main(){
    STACK stack;

    Init(&stack);
    Push(&stack,5);
    Push(&stack,4);
    Push(&stack,3);
    Push(&stack,2);
    Push(&stack,1);

    printf("%d\n",Peek(&stack));


    Pop(&stack);
    printf("%d\n",Peek(&stack));

    Pop(&stack);
    printf("%d\n",Peek(&stack));
    Pop(&stack);
    printf("%d\n",Peek(&stack));
    Pop(&stack);
    printf("%d\n",Peek(&stack));
    Pop(&stack);
    printf("%d\n",Peek(&stack));


    return 0;
}