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
bool visited[21][21];
int lefty[1]={1};
int leftx[1]={-1};

int righty[1]={1};
int rightx[1]={1};

int upy[1]={-1};
int upx[1]={1};

int rightupy[1]={-1};
int rightupx[1]={-1};

struct Cafe{
    int y;
    int x;
    set <int> sArray;
    int cnt;
};

Cafe cafe[101];
int maxv=0;

void dfs(int y,int x,int cafe_size,int flag){

    for(auto item=cafe[cafe_size].sArray.begin();item != cafe[cafe_size].sArray.end();item++){
        cout << *item << '\t';
    }
    printf("\n");

    flag =flag %4;

    if(y == cafe[cafe_size].y && x == cafe[cafe_size].x){

        //같으면
        if(cafe[cafe_size].cnt == cafe[cafe_size].sArray.size()){
            if(maxv<cafe[cafe_size].cnt){
                maxv = cafe[cafe_size].cnt;
                cafe_size++;
            }
        }
        return;

    }

    int ny=0, nx=0;
    if(flag==0){
        ny = y + lefty[0];
        nx = x + leftx[0];

        if(ny>=0 && nx>=0 && nx<n && ny<n){
            if(cafe[cafe_size].cnt==0){ //초기값
                cafe[cafe_size].y = y;
                cafe[cafe_size].x = x;
                cafe[cafe_size].sArray.insert(map[y][x]);
            }
            cafe[cafe_size].sArray.insert(map[ny][nx]);
            cafe[cafe_size].cnt+=1;

            dfs(ny,nx,cafe_size,0);
            cafe[cafe_size].sArray.erase(map[ny][nx]);
            cafe[cafe_size].cnt-=1;
        }else{
            flag=1;
        }
    }
    if(flag==1){
        ny = y + righty[0];
        nx = x + rightx[0];

        if(ny>=0 && nx>=0 && nx<n && ny<n) {

            cafe[cafe_size].sArray.insert(map[ny][nx]);
            cafe[cafe_size].cnt+=1;
            dfs(ny, nx, cafe_size, 1);
            cafe[cafe_size].sArray.erase(map[ny][nx]);
            cafe[cafe_size].cnt-=1;

        }else{
            flag = 2;
        }
    }
    if(flag==2){
        ny = y + upy[0];
        nx = x + upx[0];

        if(ny>=0 && nx>=0 && nx<n && ny<n) {

            cafe[cafe_size].sArray.insert(map[ny][nx]);
            cafe[cafe_size].cnt+=1;
            dfs(ny, nx, cafe_size, 2);
            cafe[cafe_size].sArray.erase(map[ny][nx]);
            cafe[cafe_size].cnt-=1;
        }else{
            flag = 3;
        }
    }
    if(flag==3){
        ny = y + rightupy[0];
        nx = x + rightupx[0];

        if(ny>=0 && nx>=0 && nx<n && ny<n) {

            cafe[cafe_size].sArray.insert(map[ny][nx]);
            cafe[cafe_size].cnt+=1;
            dfs(ny, nx, cafe_size, 3);
            cafe[cafe_size].sArray.erase(map[ny][nx]);
            cafe[cafe_size].cnt-=1;

        }else{
            flag = 0;
        }
    }

}

int main() {

    int T;

    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){


        scanf("%d",&n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%1d",&map[i][j]);


            }
        }

        dfs(0,1,0,0);

    }

    return 0;
}