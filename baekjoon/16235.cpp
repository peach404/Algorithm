//
// Created by 김소연 on 26/03/2019.
//

#include <queue>
#include <vector>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M, K; //땅,나무개수,년도
int tree_size;
struct TREE{

    int y;
    int x;
    int food;
    int age;
    bool dead;
    int howmany;

};

int A[101][101];
TREE tree[101];
int map[101][101][101];


int by[8]={-1,-1,-1,0,0,0,1,1};
int bx[8]={-1,0,1,-1,1,-1,0,1};

void spring(){
    for(int i=0;i<=tree_size;i++){
        if(map[tree[i].y][tree[i].x][0] < tree[i].age){
            tree[i].dead=true;

        }
    }
}


void summer(){

    for(int i=0;i<=tree_size;i++){
        if(tree[i].dead==true){
            int val=floor(tree[i].age/2);
            map[tree[i].y][tree[i].x][0]+=val;
        }
    }


}


void fall(){

    for(int i=0;i<=tree_size;i++){
        int oldx=0,oldy=0;

        if(tree[i].age %5 ==0){
            tree[i].y = oldy;
            tree[i].x = oldx;

            for(int pos=0;pos<8;pos++){
                int ny = oldy + by[pos];
                int nx = oldx + bx[pos];

                if(ny<0 || nx<0 || ny>N || nx>N){
                    continue;
                }

                int a = tree_size+1;
                tree[a].y = ny;
                tree[a].x = nx;
                tree[a].age=1;
                tree[a].food = map[ny][nx][0];
                int compare=1;

                while(true){
                    if(map[ny][nx][compare]>0){
                        compare++;
                        tree[map[ny][nx][compare]].howmany++;

                    }
                    else if(map[ny][nx][compare]==0){
                        map[ny][nx][compare+1]=a; //여기 디버깅

                        break;
                    }
                }
                tree[a].dead=false;
                tree[a].howmany = compare+1;
            }

        }
    }
}

void winter(){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j][0]+= A[i][j];
        }
    }

}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j][0]=5;
            scanf(" %d", &A[i][j]);
        }
    }


    for (int i = 1; i <= M; i++) {
        int x=0,y=0,z=0;
        scanf("%d %d %d",&x,&y,&z);
        tree[i].x = x;
        tree[i].y = y;
        tree[i].age = z;
        tree[i].dead= false;
        tree[i].food=5;
        tree[i].howmany=1;
        tree_size++;
        map[y][x][1]=i;
    }

    return 0;
}