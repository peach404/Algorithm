//
// Created by 김소연 on 11/04/2019.
//


#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

/**
 *
 * N*N 크기
 * 최대한 긴 등산로 만들 계획
 *
 * 등산로 만드는 규칙
 * 1. 가장 높은 봉우리에서 시작해야 한다.
 * 2. 높은 지형에서 낮은 지형으로 가로 또는 세로 방향으로 연결 되어야한다.
 * 3. 딱 한 곳을 정해서 최대 K 깊이만큼 지형을 깎는 공사를 할 수 있다.
 * **/

int N,K;
int map[9][9];

int by[4]={0,-1,0,1};
int bx[4]={1,0,-1,0};

int visitied[9][9];

int res;
bool flag=false;
int cnt=1;
int mcnt=0;
int dfs(int y,int x,int len,int flag){

    if(len>mcnt){
        mcnt = len;
    }
    visitied[y][x]=1;

    for(int i=0;i<4;i++){
        int ny = y + by[i];
        int nx = x + bx[i];

        if(ny<0 || nx<0 || ny>N-1 || nx>N-1) continue;

        if(map[ny][nx]<map[y][x] && visitied[ny][nx]==0){
           //printf("+ %d %d\n",ny,nx);
            dfs(ny,nx,len+1,flag);

        }else if(map[y][x]>map[ny][nx]-K && !flag && visitied[ny][nx]==0){

            int t= map[ny][nx];
            map[ny][nx]=map[y][x]-1;
          //  printf("+ %d %d\n",ny,nx);
            dfs(ny,nx,len+1,true);
            map[ny][nx]=t;

        }
    }
    visitied[y][x]=0;

  //  printf("마지막 %d\n",mcnt);
    return mcnt;
}



int main() {

    int T=0;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){

        scanf("%d %d",&N,&K);
        int tmp=0;
        int maxv=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) {
                scanf("%d", &tmp);
                map[i][j]=tmp;
                if(tmp>maxv){
                    maxv = tmp;
                }
            }
        }

        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){

                if(map[i][j]==maxv){
                    cnt=1;
                    mcnt=0;
                  //  printf("start: %d %d\n",i,j);
                    res=dfs(i,j,1,0);


                    if(res>ans){
                        ans = res;
                    }

                }
            }
        }
        memset(visitied,0,sizeof(visitied));
        memset(map,0,sizeof(map));
        printf("#%d %d\n",tc+1,ans);
    }

    return 0;
}