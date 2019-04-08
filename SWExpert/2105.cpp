//
// Created by 김소연 on 04/04/2019.
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
int map[21][21];
int check[101];
int visited[21][21];
int cnt;
int ans;
int py,px;
void go(int y,int x,int flag){
    cnt++;
    check[map[y][x]]+=1;
    visited[y][x]+=1;

    if(flag==4 && visited[y][x]==2){
        if(ans<cnt-1){
            ans = cnt-1;
        }
    }else{
        if(flag == 0){
            if(!check[map[y+1][x+1]] && map[y][x]!=0) {
                go(y + 1, x + 1, 1);
            }
        }else if(flag ==1){
            if(!check[map[y+1][x+1]] && map[y+1][x+1]!=0) {
                go(y + 1, x + 1, 1);
            }
            if(!check[map[y+1][x-1]] && map[y+1][x-1]!=0) {
                go(y + 1, x - 1, 2);
            }
        }else if(flag ==2){
            if(!check[map[y+1][x-1]] && map[y+1][x-1]!=0) {
                go(y + 1, x - 1, 2);
            }
            if(!check[map[y-1][x-1]] && map[y-1][x-1]!=0) {
                go(y - 1, x - 1, 3);
            }
        }else if(flag == 3){
            if(!check[map[y-1][x-1]] && map[y-1][x-1]!=0) {
                go(y - 1, x - 1, 3);
            }
            if(py == y-1 && px ==x+1){
                go(y-1,x+1,4);
            }
            else if(!check[map[y-1][x+1]] && map[y-1][x+1]!=0) {
                go(y - 1, x + 1, 4);
            }
        }else {
            if(py == y-1 && px ==x+1){
                go(y-1,x+1,4);
            }
            else if(!check[map[y-1][x+1]] && map[y-1][x+1]!=0) {
                go(y - 1, x + 1, 4);
            }

        }


    }
    cnt--;
    check[map[y][x]]-=1;
    visited[y][x]-=1;

}


int main() {

    int T;

    scanf("%d",&T);

    for(int tc=0;tc<T;tc++) {


        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        memset(check,false,sizeof(check));
        memset(visited,false,sizeof(visited));
        ans=-1;

        for (int i = 1; i < n; i++) {
            for (int j = 2; j < n; j++) {
                py=i;
                px=j;
                go(i, j,0);
            }
        }

        printf("#%d %d\n",tc+1,ans);
    }

    return 0;
}
