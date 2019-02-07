//
// Created by 김소연 on 07/02/2019.
//

#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int check[1000001];
int N,M;
int visited[10001];

int change(int nq,int i,int j){
    int tmp = nq;

    if(i==1){
        tmp -=(nq/1000)*1000;
        tmp +=j*1000;
    }
    else if(i==2){
        tmp -=((nq/100)%10)*100;
        tmp +=j*100;
    }else if(i==3){
        tmp -=((nq%100)/10)*10;
        tmp+=j*10;
    }else {
        tmp -=nq%10;
        tmp+=j;
    }

    return tmp;
}


int main() {
    vector<int> p;
    check[0] = 0;
    check[1] = 0;

    for (int i = 2; i <= 10000; i++) {
        if (check[i] == 0) {
            for (int j = i + i; j <= 10000; j += i) {
                check[j] = -1;
            }
        }
    }

    int T=0;

    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        scanf("%d %d",&N,&M);
        memset(visited,0,sizeof(visited));
        check[N]=1;
        queue <pair <int,int> > q;
        q.push({N,0});

        bool flag=false;
        while(!q.empty()) {
            int nq = q.front().first;
            int cnt = q.front().second;

            q.pop();

            if(nq == M){
                printf("%d\n",cnt);
                check[N]=0;
                flag=true;
                break;
            }

            for (int i = 1; i <=4; i++) {
                for (int j = 0; j <= 9; j++) {
                    int a = change(nq,i,j);

                    if(check[a]==0 && a>999 && a<10000 && visited[a]==0){
                        visited[a]=1;
                        q.push({a,cnt+1});
//                        printf("%d %d a: %d cnt:%d\n",i,j,a,cnt);
                    }

                }
            }
        }

        if(!flag){
            check[N]=0;
            printf("Impossible\n");
        }

    }



    return 0;
}