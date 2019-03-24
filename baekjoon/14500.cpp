//
// Created by 김소연 on 25/03/2019.
//

#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int map[501][501];
bool visited[501][501];

int by[5]={0,0,1,-1};
int bx[5]={1,-1,0,0};
int N,M;
int sumv;
int tmp;
int ans=0;


void dfs(int y,int x,int cnt){

    if(cnt>3){
        return;
    }
    if(cnt==3 && sumv<tmp){
        sumv= tmp;
        return;
    }

    for(int i=0;i<4;i++){
        int ny = y+ by[i];
        int nx = x+ bx[i];

        if(ny<0 || nx<0 || ny>N || nx>M){
            continue;
        }

        if(!visited[ny][nx]) {
            visited[ny][nx]=true;
            tmp += map[ny][nx];
            dfs(ny, nx, cnt + 1);
            tmp -= map[ny][nx];
            visited[ny][nx]=false;
        }
    }

}

void check() {
    // ㅗ
    for(int i = 1; i < N; i ++) {
        for(int j = 1; j < M - 1; j ++) {
            int temp = map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i][j + 1];
            ans = max(ans, temp);
        }
    }

    // ㅜ
    for(int i = 0; i < N - 1; i ++) {
        for(int j = 1; j < M - 1; j ++) {
            int temp = map[i][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1];
            ans = max(ans, temp);
        }
    }

    // ㅓ
    for(int i = 1; i < N - 1; i ++) {
        for(int j = 1; j < M; j ++) {
            int temp = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j - 1];
            ans = max(ans, temp);
        }
    }

    // ㅏ
    for(int i = 1; i < N - 1; i ++) {
        for(int j = 0; j < M - 1; j ++) {
            int temp = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1];
            ans = max(ans,temp);
        }
    }
}
int main() {


    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %d",&map[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            sumv=0;
            tmp=0;
            memset(visited,0,sizeof(visited));
            visited[i][j] = true;
            tmp += map[i][j];
            dfs(i, j, 0);
            if(sumv>ans){
                ans=sumv;
            }
        }
    }
    check();
    printf("%d\n",ans);
    return 0;
}