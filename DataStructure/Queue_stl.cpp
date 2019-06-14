//
// Created by 김소연 on 13/06/2019.
//

#include <list>
#include <iostream>
#include <cstdio>

using namespace std;

void qPush(list <int> *q,int num){
    q->push_back(num);
}

void qPop(list <int> *q){
    q->pop_front();
}
void qPrint(list <int> *q){
    list <int>::iterator it;

    for(it=q->begin();it!=q->end();++it){
        cout << *it << endl;
    }
    cout <<"--------------"<<endl;
}

int main(){


    list <int> q;

    qPush(&q,5);
    qPush(&q,4);
    qPush(&q,3);
    qPush(&q,2);
    qPush(&q,1);

    qPrint(&q);
    qPop(&q);
    qPrint(&q);
    return 0;
}