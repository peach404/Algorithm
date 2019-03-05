//
// Created by 김소연 on 05/03/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

int arr[5][5];
set <int> s;
int tmp;
int by[4]={0,-1,0,1};
int bx[4]={1,0,-1,0};
int c[8]={0,10,100,1000,10000,100000,1000000,10000000};
void dfs(int y,int x,int num,int tmp){
    if(num >7){
        return;
    }
    if(num == 7){
//        cout<< tmp<<'\n';
        s.insert(tmp);

        return;
    }
    else{
        for(int i=0;i<4;i++){
            int ny = y + by[i];
            int nx = x + bx[i];
            if(ny>=0 && nx>=0 && ny<4 && nx<4){

                dfs(ny,nx,num+1,arr[ny][nx]+(10*tmp));

            }

        }
    }
}

int main() {

    int T;

    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        memset(arr,0,sizeof(arr));
        s.clear();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf(" %d",&arr[i][j]);
            }
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) {
                dfs(i, j,1,arr[i][j]);

            }
        }

        printf("#%d %d\n",tc+1,s.size());


    }


    return 0;
}