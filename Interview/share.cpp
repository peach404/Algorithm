//
// Created by 김소연 on 27/05/2019.
//

#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

int stu[1000][1000];
int talker[1000];
int ans=0;
int N,K;
void go(int y,int x,int cnt ,int dicide){
    if(y>N){
        if(ans<cnt) ans = cnt;
        return;
    }
    if(dicide>K) {
        return;
    }
    if(x>K && y<N){
        go(y+1,1,cnt,dicide);
    }else if(x>K && y>N){ return;}

   if(stu[y][x]==1 && x==dicide && talker[x]==0){
       talker[x]=1;
       go(y+1,1,cnt+1,dicide+1);
       talker[x]=0;
   }else{
       for(int i=x;i<=K;i++) {
           go(y, x + 1, cnt, dicide);
       }

   }

}


int main(){


    int num1,num2;
    scanf("%d %d",&N,&K);

    for(int i=1;i<=N;i++){
        scanf("%d %d",&num1,&num2);

        for(int a=num1;a<=num2;a++){
            stu[i][a]=1;
        }
    }
    int ans=0;


    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            //if(stu[i][j]==1){
                go(i,j,0,1);
           // }
        }
    }


    return 0;
}
