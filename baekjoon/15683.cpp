//
// Created by 김소연 on 25/03/2019.
//

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int map[8][8];
int N,M;

//# 대신 -1로!

struct CCTV{
    int y;
    int x;
    int type;
};
int cctv_size;
CCTV cctv[8];
int ret=100;

int bais[5]={4,2,4,4,1};

void arrcopy(int want[8][8],int provider[8][8]){

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            want[i][j]=provider[i][j];
        }
    }
    return;
}
void update(int d,CCTV cctv){
    d = ( d % 4 );
    if(d==0){ //->
        for(int i=cctv.x+1;i<M;i++){
            if(map[cctv.y][i] == 6){
                break;
            }
            map[cctv.y][i] = -1;
        }
    }
    if(d==1){ //V
        for(int i=cctv.y-1;i>=0;i--){
            if(map[i][cctv.x] == 6){
                break;
            }
            map[i][cctv.x] = -1;
        }

    }
    if(d==2){ //<-
        for(int i=cctv.x-1;i>=0;i--){
            if(map[cctv.y][i] == 6){
                break;
            }
            map[cctv.y][i] = -1;
        }
    }
    if(d==3){ //^
        for(int i=cctv.y+1;i<N;i++){
            if(map[i][cctv.x] == 6 ){
                break;
            }
            map[i][cctv.x] = -1;
        }
    }
}

void dfs(int cctv_idx){

    if(cctv_size == cctv_idx){
        int tmp=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) {
                if(map[i][j]==0){
                    tmp++;
                }
            }
        }

        if(tmp<ret){
            ret = tmp;
        }
        return;
    }

    int backup[8][8]={0, };

    int type =cctv[cctv_idx].type;
    for(int dir=0 ; dir<bais[type] ; dir++){
        arrcopy(backup,map);

        if(type== 0){
            update(dir,cctv[cctv_idx]);
        }
        else if(type == 1 ){
            update(dir,cctv[cctv_idx]);
            update(dir+2,cctv[cctv_idx]);

        }
        else if(type == 2){
            update(dir,cctv[cctv_idx]);
            update(dir+1,cctv[cctv_idx]);
        }
        else if(type == 3){
            update(dir,cctv[cctv_idx]);
            update(dir+1,cctv[cctv_idx]);
            update(dir+2,cctv[cctv_idx]);
        }
        else{
            update(dir,cctv[cctv_idx]);
            update(dir+1,cctv[cctv_idx]);
            update(dir+2,cctv[cctv_idx]);
            update(dir+3,cctv[cctv_idx]);
        }

        dfs(cctv_idx+1);
        arrcopy(map,backup);
    }


};


int main() {


    scanf("%d %d",&N,&M);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){

            scanf("%d",&map[i][j]);

            if(map[i][j]>0 && map[i][j]<6){
                cctv[cctv_size].type=map[i][j]-1;
                cctv[cctv_size].y = i;
                cctv[cctv_size].x = j;
                cctv_size++;

            }

        }
    }

    dfs(0);
    printf("%d\n",ret);
    return 0;
}

