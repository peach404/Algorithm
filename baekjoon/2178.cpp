//
// Created by 김소연 on 29/01/2019.
//

#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int miro[101][101];
int check[101][101];
int dy[4]={1,0,-1,0};
int dx[4]={0,-1,0,1};

int N,M;
queue <pair <int,int> > q;
int bfs(int y,int x){
    q.push({x,y});

    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;

        q.pop();
        for(int i=0;i<4;i++){

            int ny = qy + dy[i];
            int nx = qx + dx[i];


            if(nx >=0 && ny >=0 && nx <N && ny <M){
                if(check[nx][ny] == 0 && miro[nx][ny]==1){
                    check[nx][ny]=check[qx][qy]+1;
                    q.push({nx,ny});
                }
            }
        }
    }

    return check[N-1][M-1];
}


int main(){


    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&miro[i][j]);
        }
    }

    check[0][0]=1;
    int ans=bfs(0,0);

    printf("%d",ans);
    return 0;
}