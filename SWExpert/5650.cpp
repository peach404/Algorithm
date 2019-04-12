//
// Created by 김소연 on 11/04/2019.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;


/**
 *
 * 핀볼은 블록이나 웜홀 또는 블랙홀을 만나지 않는 한 현재 방향을 유지하면서 계속 직진한다.
 * 블록의 수평면이나 수직면 또는 벽을 만날 경우 방향을 바꿔 반대 방향으로 돌아오고,
 *
 * 핀볼이 웜홀에 빠지면 동일한 숫자를 가진 다른 반대편 웜홀로 빠져 나오게 되며
 * 진행 방향은 그대로 유지된다.
 *
 * 핀볼이 블랙홀을 만나면 핀볼이 사라지게 되어 게임이 종료된다.
 * 핀볼이 출발 위치로 돌아오거나 블랙홀에 빠질 때 게임 종료된다.
 * 점수는 벽이나 블록에 부딪힌 횟수가 된다.
 * 게임판 위에서 출발 위치와 진행 방향을 임의로 선정 가능 할 때
 * 게임에서 얻을 수 있는 점수의 최댓값을 구하라
 * 단, 블록, 웜홀 또는 블랙홀이 있는 위치에서는 출발할 수 없다.
 *
 * 경사면을 만날 경우에는 직각으로 진행 방향이 꺾이게 된다.
 * */
int N;
int map[150][150];
int by[5]={0,0,0,1,-1}; //동 서 남 북
int bx[5]={0,1,-1,0,0};
int cy,cx;

struct Whome{
    int y;
    int x;
};


Whome whomecal(int sy,int sx,int d){
    Whome whome;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]==map[sy][sx] && i !=sy && j != sx){
                whome.y =i+by[d];
                whome.x = j+bx[d];
                return whome;
            }
        }
    }
}

int go(int y,int x,int d){
    bool flag = true;
    int cnt=0;
    int ny = y+ by[d];
    int nx = x + bx[d];
    int fir = 0;
    while(flag){
        flag = false;

        if(ny<1 || nx <1 || nx>N || ny >N){
            if(d==1) d=2;
            else if(d==2) d=1;
            else if(d==3) d=4;
            else d=3;
            cnt++;
            ny = ny + by[d];
            nx = nx + bx[d];

            continue;
        }

        if(map[ny][nx]== -1 || (ny==cy && nx==cx && fir != 0) ){ //블랙홀
            return cnt;
        }

        if(map[ny][nx]== 0){
            ny = by[d]+ ny;
            nx = bx[d]+ nx;
        }

        else if(map[ny][nx]>=6 && map[ny][nx]<=10){ //웜홀
            Whome newwhome=whomecal(ny,nx,d);
            ny = newwhome.y;
            nx = newwhome.x;

        }
        //블록 부딛힘
        else if(map[ny][nx]>0 && map[ny][nx]<6){
            if(map[ny][nx]==1){
                if(d==1) d=2;
                else if(d==2) d=4;
                else if(d==3) d=1;
                else d=3;
            }else if(map[ny][nx]==2){
                if(d==1) d=2;
                else if(d==2) d=3;
                else if(d==3) d=4;
                else d=1;

            }else if(map[ny][nx]==3){
                if(d==1) d=3;
                else if(d==2) d=1;
                else if(d==3) d=4;
                else d=2;
            }else if(map[ny][nx]==4){
                if(d==1) d=4;
                else if(d==2) d=1;
                else if(d==3) d=2;
                else d=3;
            }else if(map[ny][nx]==5){
                if(d==1) d=2;
                else if(d==2) d=1;
                else if(d==3) d=4;
                else d=3;
            }
            cnt++;
            ny = ny + by[d];
            nx = nx + bx[d];
        }
        flag = true;
        fir =2;
    }

}

int main() {

    int T=0;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        scanf("%d",&N);
        int res=0;
        int maxv=0;

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                scanf("%d",&map[i][j]);
            }
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++) {

                if(map[i][j]==0){
                    for(int k=1;k<=4;k++){
                        cy = i;
                        cx = j;
                        res=go(i,j,k);

                        if(res>maxv){
                            maxv = res;
                        }
                    }
                }

            }
        }

        memset(map,0,sizeof(map));

        printf("#%d %d\n",tc+1,maxv);
    }

    return 0;
}