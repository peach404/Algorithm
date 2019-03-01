//
// Created by 김소연 on 28/02/2019.
//

#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int n;
int arr[101][101];
int tmparr[101][101];
int land[101][101];
bool visited[101][101];
queue <pair <int,int> >q;

vector <int> v;

int bx[4]={1,0,-1,0};
int by[4]={0,-1,0,1};
int landcnt=1;

void islandcnt(int y,int x,int num){

    visited[y][x]=true;
    if(arr[y][x]==1){
        land[y][x]=num;
    }
    for(int i=0;i<4;i++){
        int ny = y + by[i];
        int nx = x + bx[i];

        if(ny>=0 && nx>=0 && ny<n && nx<n){
           if(!visited[ny][nx] && arr[ny][nx]==1){
                visited[ny][nx]=true;
                land[ny][nx]=num;
                islandcnt(ny,nx,num);
            }
        }
    }


}

int spread(int num){
    queue <pair <int,int> >s;
    int ans=0;
    //섬 1개 큐에 넣기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(land[i][j]==num){
                s.push({i,j});
            }
        }
    }

    //////////////////////////

    int ssize=s.size();

    while(!s.empty()){

        for(int t=0;t<ssize;t++) {
            int sy = s.front().first;
            int sx = s.front().second;

            visited[sy][sx] = true;
            s.pop();

            for (int i = 0; i < 4; i++) {
                int ny = sy + by[i];
                int nx = sx + bx[i];

                if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
                    if (land[ny][nx] == 0 && !visited[ny][nx]) {
                        visited[ny][nx]=true;
                        tmparr[ny][nx]=tmparr[sy][sx]+1;
//                        printf("%d %d %d\n",ny,nx,arr[ny][nx]);
                        s.push({ny, nx});

                    } else if (land[ny][nx] >0 && land[ny][nx] != num) {
//                        printf("aa%d %d %d\n",ny,nx,arr[sy][sx]);
                        return tmparr[sy][sx];
                    }
                }
            }
        }

    }
}

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %d",&arr[i][j]);
        }
    }

    //섬 번호 매기기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(!visited[i][j]&& arr[i][j]==1){
                islandcnt(i,j,landcnt);
                landcnt++;
            }
        }
    }

    for(int i=1;i<landcnt;i++){
        memset(visited,false,sizeof(visited));
        memset(tmparr,0,sizeof(tmparr));
        int newval= spread(i);
        v.push_back(newval);
    }


    sort(v.begin(),v.end());
    printf("%d\n",v[0]);


    return 0;
}