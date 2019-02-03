//
// Created by 김소연 on 02/02/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int subin,sister;

int dis[100001];
int minv;
queue <int> q;

bool check(int a){
    if(a>=0 && a<=100000) return true;
    return false;
}

void bfs(int a){
    q.push(a);
    dis[a]=1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == sister) {
            minv = dis[x];
            return;
        }
        if(x >1000001){
            return;
        }

        if(check(x-1) &&dis[x-1] ==0){
            //  printf("%d\n",x-1);
            q.push(x-1);
            dis[x-1]=dis[x]+1;
        }

        if(check(x+1)&&dis[x+1] ==0 && x>=0){
            // printf("%d\n",x+1);
            q.push(x+1);
            dis[x+1]=dis[x]+1;
        }
        if(check(x*2) &&dis[x*2] ==0){
            // printf("%d\n",x*2);
            q.push(x*2);
            dis[x*2]=dis[x]+1;
        }
    }


}

int main(){



    scanf("%d %d",&subin,&sister);


    bfs(subin);

    printf("%d",minv-1);
    return 0;
}