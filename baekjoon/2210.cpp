//
// Created by 김소연 on 27/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <set>

using namespace std;
int arr[5][5];
int bx[4]={1,0,-1,0};
int by[4]={0,-1,0,1};
set <int> s;
set<int>::iterator iter;

//set 사용

void back(int cnt,int y,int x,int num){

    if(cnt==6){
        s.insert(num);


        return;
    }

    for(int i=0;i<4;i++){
        int ny = y + by[i];
        int nx = x + bx[i];

        if(ny>=0 && nx>=0 && ny<5 && nx<5){
            back(cnt+1,ny,nx,10*num+arr[ny][nx]);
        }
    }
}


int main(){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf(" %d",&arr[i][j]);
        }
    }

    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
           back(1,i,j,arr[i][j]);
       }
    }

    //SET 출력
//    for(iter=s.begin(); iter != s.end();iter++){
//        cout << * iter <<"\n";
//    }

    printf("%d\n",s.size());

    return 0;
}