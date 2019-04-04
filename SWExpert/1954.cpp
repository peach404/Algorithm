//
// Created by 김소연 on 05/04/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;
int n;
int map[11][11];

int by[4]={0,1,0,-1};
int bx[4]={1,0,-1,0};
int d;
void dfs(int y,int x,int idx){
    if(idx>n*n){
        return;
    }

    if( y<0 || x<0 || y>n-1 || x>n-1 || map[y][x] !=0){
        d++;
        d%=4;
        return;
    }
    map[y][x]=idx;
    dfs( y + by[d],x + bx[d],idx+1);
    dfs( y +by[d],x + bx[d],idx+1);

}

int main(){

    int T;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        d=0;
        memset(map,0,sizeof(map));
        scanf("%d",&n);

        dfs(0,0,1);

        printf("#%d\n",tc+1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}