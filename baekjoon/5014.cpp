//
// Created by 김소연 on 31/01/2019.
//
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int F,S,G,Q,U,D;
    scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);

    queue <int> q;
    vector <int> v(F+1,-1);

    vector <int> check(F+1);
    q.push(S);
    v[S]=0;
    check[S]=1;

    while(!q.empty()){

        int me = q.front();
        q.pop();

        if(me+U<=F && check[me+U]==0){
            q.push(me+U);
            check[me+U]=1;
            v[me+U]= v[me]+1;
        }
        if(me-D>0 && check[me-D]==0){
            q.push(me-D);
            check[me-D]=1;
            v[me-D] = v[me]+1;
        }

    }
    if(v[G]==-1){
        printf("use the stairs");
    }else
        printf("%d",v[G]);
}