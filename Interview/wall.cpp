//
// Created by 김소연 on 30/05/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
char arr[10][10];
int num[10][10];
int tmp[10][10][2];

//tmp[10][10][0] = 사전순으로 간 경우
//tmp[10][10][1] = 한번 역 사전순으로 간 경우
int visited[5][5][2];
int by[4]={0,-1,0,1};
int bx[4]={1,0,-1,0};

int maxval = 0;

struct Data{
    int y;
    int x;
    bool flag;
};

int bfs(int sy,int sx){
    int ret=0;
    queue <Data> q;
    Data start;
    start.y = sy;
    start.x = sx;
    start.flag = false;

    q.push({start});

    while(!q.empty()){

        Data qdata = q.front();

        int qy = qdata.y;
        int qx = qdata.x;
        bool flag = qdata.flag;

        q.pop();

        for(int i=0;i<4;i++){

            Data ndata;
            int ny = by[i] + qy;
            int nx = bx[i] + qx;

            ndata.y = ny;
            ndata.x = nx;


            if(ny<0 || nx<0 || ny>4 || nx>4){
                continue;
            }

            // 처음
            if( num[qy][qx] < num[ny][nx]&& !flag){
                visited[ny][nx][0]=1;
                ndata.flag = false;
                q.push({ndata});
                tmp[ny][nx][0] = tmp[qy][qx][0]+1;
              //  printf("1 : %d %d %c   %d\n",ny,nx,arr[ny][nx],tmp[ny][nx][0]);
            }
            // 한번 사전 순 앞에 오는 경우

            else if( num[qy][qx] > num[ny][nx]&& !flag){
                visited[ny][nx][1]=1;
                ndata.flag = true;
                q.push({ndata});
                tmp[ny][nx][1] = tmp[qy][qx][0]+1;
              //  printf("2 : %d %d %c   %d\n",ny,nx,arr[ny][nx],tmp[ny][nx][1]);
            }

          //   사전 순 앞에 오게 한 후
            else if( num[qy][qx] < num[ny][nx]&& flag){
                visited[ny][nx][1]=1;
                ndata.flag = true;
                q.push({ndata});
                tmp[ny][nx][1] = tmp[qy][qx][1]+1;
               // printf("3 : %d %d %c   %d\n",ny,nx,arr[ny][nx],tmp[ny][nx][1]);
            }

        }


    }

    return ret;
}

int main(){

    for(int i=0;i<5;i++){
        scanf("%s",arr[i]);
        for(int j=0;j<5;j++){

            num[i][j] = arr[i][j] - 'A';
        }
    }


    int ans=0;
    int ret=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++) {
          //  printf("++++++++++++++++++++++++++\n");
            maxval=0;

            memset(visited,0,sizeof(visited));
            memset(tmp,0,sizeof(tmp));
            visited[i][j][0] = 1;
            visited[i][j][1] = 1;

            tmp[i][j][0]=1;
            tmp[i][j][1]=1;
            ret=bfs(i,j);

            int a = tmp[4][4][0];
            int b = tmp[4][4][1];

            ret = max(a,b);

            if(ans <ret){
                ans = ret;
            }
        }
    }

    printf("%d\n",ans);


    return 0;
}
