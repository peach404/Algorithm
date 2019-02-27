//
// Created by 김소연 on 14/02/2019.
//
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int n,m;
int arr[1001][1001];
int ans[1001][1001][2];
int visited[1001][1001][2];
int bx[4]={1,0,-1,0};
int by[4]={0,-1,0,1};

struct Data{
    int y=0;
    int x=0;
    bool flag= false;

    Data(int _y,int _x,bool _flag):y(_y),x(_x),flag(_flag){}

};


void bfs(int y,int x){

    ans[y][x][0]=1;
    ans[y][x][1]=1;

    visited[y][x][0]=1;
    visited[y][x][1]=1;
    queue <Data> q;
    q.push(Data(y,x,false));

    while(!q.empty()){
        int qy = q.front().y;
        int qx = q.front().x;
        bool flag = q.front().flag;
        q.pop();
        for(int i=0;i<4;i++){
            int cy = by[i]+qy;
            int cx = bx[i]+qx;

            if( cy>=0 && cx>=0 && cy<n && cx<m){

                if(visited[cy][cx][0]==0 && arr[cy][cx]==0 && !flag){ //벽 안 뚫고 그냥 이동
                    visited[cy][cx][0] = 1;
                    q.push(Data(cy,cx,false));
                    ans[cy][cx][0] = ans[qy][qx][0] +1;
                  //  printf("qy:%d qx:%d     그냥 %d %d : %d\n",qy,qx,cy,cx,ans[cy][cx][0]);
                }
                else if(arr[cy][cx]==1 && !flag && visited[cy][cx][0] == 0) { //벽 뚫기
                    visited[cy][cx][1] = 1;
                    ans[cy][cx][1] = ans[qy][qx][0] + 1;
                    q.push(Data(cy, cx, true));
                  //  printf("qy:%d qx:%d     벽 %d %d : %d\n",qy,qx ,cy, cx,ans[cy][cx][1]);
                }else if(flag && visited[cy][cx][1]==0 && arr[cy][cx]==0){ //벽 뚫은채로 이동
                    visited[cy][cx][1] = 1;
                    q.push(Data(cy,cx,true));
                    ans[cy][cx][1] = ans[qy][qx][1] +1;
                 //   printf("qy:%d qx:%d    벽 뚫은채로 이동: %d %d: %d\n",qy,qx,cy,cx,ans[cy][cx][1]);

                }
            }
        }

    }

}

int main() {
    scanf("%d %d", &n, &m); //세 가
    memset(arr,2,sizeof(arr));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    bfs(0, 0);
    int a = ans[n-1][m-1][0];
    int b = ans[n-1][m-1][1];
    int val=0;
    if(a==0 && b==0){
        val = -1;
    }else if(a==0 || b==0){
        val = max(a,b);
    }else{
        val = min(a,b);
    }

    printf("%d\n",val);


return 0;
}