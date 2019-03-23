//
// Created by 김소연 on 23/03/2019.
//

#include <math.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int N, L,R;
int map[51][51];


int by[4]={0,0,1,-1};
int bx[4]={1,-1,0,0};

struct Info{
    int y;
    int x;

};


void create_func(int sy,int sx,int paint[][51],int index,int &count ,int &sum){

    int visited[51][51]={0, };
    visited[sy][sx]=1;

    queue <Info>q;
    Info head;
    head.y=sy;
    head.x=sx;
    q.push(head);

    while(!q.empty()) {
        Info cur = q.front();
        paint[cur.y][cur.x]=index;
        count++;
        sum += map[cur.y][cur.x];
        q.pop();

        for (int i = 0; i < 4; i++) {
            Info next;
            next.y = cur.y + by[i];
            next.x = cur.x + bx[i];

            if (next.y >= 0 && next.x >= 0 && next.x < N && next.y < N) {

                int tmp = abs(map[cur.y][cur.x] - map[next.y][next.x]);

                if (!visited[next.y][next.x] && tmp >= L && tmp <= R) {
                   // printf("%d %d\n",next.y,next.x);
                    visited[next.y][next.x]=1;
                    q.push(next);
                }
            }
        }
    }
}



int main() {

    scanf("%d %d %d",&N,&L,&R);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            scanf(" %d", &map[i][j]);
        }
    }
    bool flag=true;
    int ans=0;
    while(flag) {
        flag = false;

        int area_idx = 0;
        int sum[2501] = {0, };
        int count[2501] = {0, };
        int paint[51][51] = {0, };

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {

                if(paint[y][x] == 0 ){

                    area_idx++;
                    create_func(y,x,paint,area_idx,count[area_idx],sum[area_idx]);
                }
            }
        }



        for (int a = 1; a <= area_idx; a++) {
            if (count[a] > 1) {
                flag= true;
                int newv = floor(sum[a] / count[a]);
                for (int y = 0; y < N; y++) {
                    for (int x = 0; x < N; x++) {
                        if(paint[y][x]==a){
                            map[y][x]=newv;
                        }

                    }
                }
            }
        }

        if(flag){
            ans++;
        }



    }

    printf("%d\n",ans);

    return 0;
}