//
// Created by 김소연 on 13/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int palace[51][51][4];
int visited[51][51];
int n,m;
int bx[4]={0,-1,0,1};
int by[4]={-1,0,1,0};

int bfs(int x,int y){
    queue <pair <int,int> >q;
    q.push({x,y});
    int roomsize=0;

    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        int oneroom=0;
        for(int i=0;i<4;i++){
            if(palace[qx][qy][i]==0){
                int nx = qx + bx[i];
                int ny = qy + by[i];

                if(nx >=0 && ny >= 0 && nx <n && ny<m && visited[nx][ny]==-1){
                  //  printf("%d %d\n",nx,ny);
                    q.push({nx,ny});
                    visited[qx][qy]=0;
                    roomsize++;
                }
            }
            else{
                oneroom++;
            }
        }
        if(oneroom==4){
            roomsize=1;
        }
    }


    return roomsize;

}

int main() {



    scanf("%d %d",&m,&n); //m:x y:y

    memset(visited,-1,sizeof(visited));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp=0;
            scanf(" %d",&tmp);

            //2진수로 바꾸기
            for(int k=4;k>=0;k--){
                palace[i][j][k]=(tmp >> k & 1 ? 1:0);
            }
        }
    }
    int rsize=0;
    int maxsize=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==-1){

                rsize= bfs(i,j);
                if(rsize>0) {
                    printf("%d %d\n",i,j);
                    cnt++;
                }
                if(rsize >maxsize){
                    maxsize = rsize;
                }
            }


        }
    }
    printf("cnt: %d\n maxsize: %d\n",cnt,maxsize+1);


    return 0;
}