
//
// Created by 김소연 on 09/06/2019.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
void go(int y,int x){

    arr[y][x]=9;
    queue <pair <int,int> > q;
    q.push({y,x});

    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();

        if(arr[qy][qx+1]==0 || arr[qy][qx+1]==2){
            int ny = qy;
            int nx = qx+1;

            if(ny<0 || nx<0 || ny>10 || nx>10) continue;
            if(arr[ny][nx]==0) {
                q.push({ny, nx});
            }
            arr[ny][nx] = 9;
        }
        else if((arr[qy][qx+1]==1 && arr[qy+1][qx]==0) || (arr[qy][qx+1]==1 && arr[qy+1][qx]==2)){
            int ny = qy+1;
            int nx = qx;

            if(ny<0 || nx<0 || ny>10 || nx>10) continue;

            if(arr[ny][nx]==0) {
                q.push({ny, nx});
            }
            arr[ny][nx]=9;

        }

    }

}
int main() {

    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++) {
            scanf("%d",&arr[i][j]);
        }
    }

    go(2,2);

    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;

}