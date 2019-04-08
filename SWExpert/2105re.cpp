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
int map[50][50];

int by[4]={0,1,2,1};
int bx[4]={0,-1,0,1};

int maxv=0;
void rightfun(int ay,int ax,set <int> sArray,int cnt,int line){
    if(ay<0 || ax<0 || ay>=n || ax>=n || ay-1<0 || ax+1>=n){
        return;
    }

    sArray.insert(map[ay][ax]);
    sArray.insert(map[ay-1][ax+1]);
    if(sArray.size() == cnt+2){
        printf("오른쪽확 : ");
        for(auto item=sArray.begin();item != sArray.end();item++){
            cout << *item << '\t';
        }
        printf("\n");


        if(maxv<cnt+2){
            maxv=cnt+2;
        }
        rightfun(ay+1,ax+1,sArray,cnt+2);
    }

}

void leftfun(int ay,int ax,set <int> sArray,int cnt){
    if(ay<0 || ax<0 || ay>=n || ax>=n|| ax+1>=n || ay+1>=n){
        return;
    }
    sArray.insert(map[ay][ax]);
    sArray.insert(map[ay+1][ax+1]);
    if(sArray.size() == cnt+2){
        printf("왼쪽확장 : ");
        for(auto item=sArray.begin();item != sArray.end();item++){
            cout << *item << '\t';
        }
        printf("\n");


        if(maxv<cnt+2){
            maxv=cnt+2;
        }
        leftfun(ay+1,ax-1,sArray,cnt+2);
    }

}

void nemo(int y,int x){



}

void dfs(int y,int x){
    set <int> sArray;
    int cnt=0;
    for(int i=0;i<4;i++){
        int ny = y + by[i];
        int nx = x + bx[i];


        if(ny<0 || nx<0 || ny>=n || nx>=n){

            return;
        }
        sArray.insert(map[ny][nx]);
        cnt++;
    }

    if(sArray.size() == cnt){
        if(maxv<cnt){
            maxv=cnt;
        }
        printf("y: %d x: %d\n",y,x);
        printf("4개일때 : ");
        for(auto item=sArray.begin();item != sArray.end();item++){
            cout << *item << '\t';
        }
        printf("\n");

        rightfun(y+3,x+1,sArray,cnt);
        leftfun(y+2,x-2,sArray,cnt);

    }

}



int main() {

    int T;

    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){


        scanf("%d",&n);
        maxv=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dfs(i,j);
            }

        }
        if(maxv==0){
            maxv=-1;
        }
        printf("#%d %d\n",tc+1,maxv);


    }

    return 0;
}
