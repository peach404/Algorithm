//
// Created by 김소연 on 25/05/2019.
//

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
char arr[22][22];
int num[22][22];
bool visited[22][22];
int check[100];
int n,m;
int by[4]={0,-1,0,1};
int bx[4]={1,0,-1,0};
int maxv=0;
void dfs(int sy,int sx,int cnt){
    if(cnt>maxv){
        maxv = cnt;
    }

    for (int i = 0; i < 4; i++) {
        int ny = sy + by[i];
        int nx = sx + bx[i];

        if (ny < 0 || nx < 0 || ny > n-1 || nx > m-1) {
            continue;
        }

        if( check[num[ny][nx]]==0){
            check[num[ny][nx]]=1;
            //visited[ny][nx]=true;
           // printf("%d %d %d    %c\n",ny,nx,cnt+1,arr[ny][nx]);

            dfs(ny,nx,cnt+1);

            check[num[ny][nx]]=0;

        }


    }

}

int main() {

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
        for(int j=0;j<m;j++){
            num[i][j] = arr[i][j] - 'A';
        }
    }

    check[num[0][0]]=1;
   // visited[0][0]=true;
    dfs(0,0,1);

    printf("%d\n",maxv);
    return 0;
}