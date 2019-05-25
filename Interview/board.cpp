//
// Created by 김소연 on 25/05/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
char arr[10][10];

int num[10][10];
int by[4]={0,-1,0,1};
int bx[4]={1,0,-1,0};

int maxval = 0;
bool flag=false;
int dfs(int sy,int sx ,int cnt, bool visited[5][5]) {

    if( cnt> maxval){
        maxval = cnt;
    }

    for (int i = 0; i < 4; i++) {
        int ny = sy + by[i];
        int nx = sx + bx[i];

        if (ny < 0 || nx < 0 || ny > 4 || nx > 4) {
            continue;
        }

        if(!visited[ny][nx] && num[sy][sx]<num[ny][nx]){
            visited[ny][nx]=true;

           // printf("%d %d :cnt %d  %c\n",ny,nx,cnt+1,arr[ny][nx]);


            dfs(ny,nx,cnt+1,visited);

            visited[ny][nx]=false;

        }

        if(!flag && !visited[ny][nx] && num[sy][sx]>num[ny][nx]){
            flag= true;
            visited[ny][nx]=true;

          //  printf("%d %d :cnt %d  %c\n",ny,nx,cnt+1,arr[ny][nx]);


            dfs(ny,nx,cnt+1,visited);

            visited[ny][nx]=false;
            flag = false;

        }
    }
    return maxval;

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
            printf("===============================\n");
            maxval=0;
            flag = false;
            bool visited[5][5]={0, };
            visited[i][j] = true;
            ret=dfs(i,j,1,visited);
            if(ret>ans){
                ans = ret;
            }
        }
    }

    printf("%d\n",ans);


    return 0;
}