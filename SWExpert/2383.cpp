//
// Created by 김소연 on 12/04/2019.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

/**
 * 밥을 빨리 먹기 위해 최대한 빠른 시간 내에 내려가야 한다.
 * 방 안의 사람들은 P, 계단의 입구를 S이다
 * 정답은 모든 사람들이 계단을 내려가 아래층으로 이동을 완료한 시간
 * 사람들이 아래층으로 이동하는 시간은 계단 입구까지 이동 시간과 계단을 내려가는 시간 포함
 *
 * 1. 계단 입구까지 이동시간
 * (사람P,세로 위치R 가로위치 C)
 * (계단 입구 S,세로위치 R 가로위치 C)
 *
 * 2. 계단을 내려가는 시간
 * 계단 입구에 도착한 후부터 계단을 완전히 내려갈 때까지의 시간
 * 계단 입구에 도착하면 1분 후 아래칸으로 내려갈 수 있다.
 * 계단 위에는 동시에 3명까지 올라가 있을 수 있다.
 * 이미 계단을 3명이 내려가고 있는 경우, 그중 한 명이 계단을 완전히 내려갈 때 까지 대기
 * 계단마다 길이 K, 계단에 올라간 후 완전히 내려가는데 K분이 걸린다.
 *
 * 모든 사람들이 계단을 내려가 이동이 완료되는 시간이 최소가 되는 경우를 찾아라
 *
 * */

struct Stair{
    int scnt;
    int y;
    int x;
    int k;
}stair[2];

struct Person{
    int y;
    int x;
    int time;
    int snum;
    int k;
}person[10];

int N;
int map[15][15];
int pcnt;
priority_queue <pair<int,int> > st1;
priority_queue <pair<int,int> > st2;


int abs(int a){
    return a>0 ? a : -a;
}
int entrance(int py,int px,int sy,int sx){
    return abs(py-sy)+abs(px-sx);
}

void go(){
    int minv=987654321;
    for(int i=0;i<pcnt;i++){
        person[i].time+=entrance(person[i].y,person[i].x,stair[person[i].snum].y,stair[person[i].snum].x)+1;
        person[i].k = stair[person[i].snum].k;
        if(person[i].snum==1){
            st1.push({person[i].time,i}); //시간, 인덱스
        }
        if(person[i].snum==2){
            st2.push({person[i].time,i});
        }
    }
    bool flag = true;
    while(flag){
        flag = false;

        if(!st1.empty()) {
            if(stair[0].scnt==0){

            }else {
                stair[0].scnt += 1;
                person[st1.top().second].time += 1;
                if(person[st1.top().second].k>0){
                    person[st1.top().second].k-=1;
                }else{
                    st1.pop();
                }
            }
        }


    }

}
void dfs(int cnt,int idx){

    if(cnt == pcnt){
        go();
//        for(int i=0;i<pcnt;i++){
//            printf("%d \t",person[i].snum);
//        }
//        printf("\n");
        return;
    }
    for(int i=idx;i<pcnt;i++){

        if(person[i].snum !=1){
            person[i].snum =1;
            dfs(cnt+1,idx+1);
        }
        if(person[i].snum !=2){
            person[i].snum =2;
            dfs(cnt+1,idx+1);
        }
        return;
    }

}

int main() {

    int T=0;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        scanf("%d",&N);
        int k=0;
        int p=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){

                scanf("%d",&map[i][j]);

                if(map[i][j]>1){
                    stair[k].y = i;
                    stair[k].x = j;
                    stair[k].scnt = 3;
                    stair[k].k = map[i][j];
                    k++;
                }
                if(map[i][j]==1){
                    pcnt++;
                    person[p].y = i;
                    person[p].x = j;
                    person[p].time = 0;
                    p++;
                }
            }
        }
        dfs(0,0);
    }

    return 0;
}