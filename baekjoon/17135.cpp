//
// Created by 김소연 on 10/04/2019.
//

#include <queue>
#include <set>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
/**
 * 1. 궁수 3명 배치 -> DFS 0
 * 2. 거리 계산 0
 * 3. 궁수 한명의 맞출 수 있는 거리만큼 돌면서 궁수 있는지 확인하고 있으면 거리가 작은것 부터 그리고 왼쪽에있는 애 죽임
 * 동시에 여러명 죽일 수 있음
 * 4. 적 내리기
 * **/

int N, M, D;
int map[20][20];
int copymap[20][20];
int fly[20];
int res;
int enemy=-1;
struct flyInfo {
    int y;
    int x;
    bool dead;
} flyInfo[3];

struct KillInfo {
    int y;
    int x;

} killInfo[3];

int flyy;
int ans = 0;

int abs(int a) {
    return a > 0 ? a : -a;
}

int cal(int gy, int gx, int flyy, int flyx) {
    return ((abs(gy - flyy) + abs(gx - flyx)));
}

void go(int idx) {
    idx %= 3;
    if(enemy==0){
        return;
    }
    bool flag = false;
    int kill = 1000000;
    int ny = 0;
    int nx = 0;

    for (int i = 0; i <= N - 1; i++) {
        for (int j = 0; j <= M - 1; j++) {


            if (i < 0 || i > N - 1 || j < 0 || j > M - 1) {
                continue;
            }

            if (map[i][j] == 1) {

                int tmp = cal(i, j, flyInfo[idx].y, flyInfo[idx].x); //D 구하기

                if (tmp <= D) {
                    if (kill > tmp) {  //거리 짧은 적 저장

                        //   printf("---%d %d %d %d\n",i, j, flyInfo[idx].y-1, flyInfo[idx].x);

                        kill = tmp;
                        ny = i;
                        nx = j;
                        flag = true;
                    } else if (kill == tmp) { // 거리가 같으면 왼쪽 적 저장
                        if (nx > j) {
                            ny = i;
                            nx = j;
                        }
                    }
                }

            }

        }
    }
    if (flag) { // 적을 죽였으면 일단 죽인애들애다가 저장

        flyInfo[idx].dead = true;
        killInfo[idx].y = ny;
        killInfo[idx].x = nx;

    }
    if (idx == 2) {
        enemy=0;
        for (int a = 0; a < 3; a++) {
            if (flyInfo[a].dead) {
                if (map[killInfo[a].y][killInfo[a].x] == 1) { //한명이 똑같은 적 죽여도 되기때문
                    map[killInfo[a].y][killInfo[a].x] = 0;
                    res++;
                 //  printf("%d %d %d\n", killInfo[a].y, killInfo[a].x, res);
                    killInfo[a].y = 0;
                    killInfo[a].x = 0;
                }
            }
            flyInfo[a].dead = false;
        }

        for(int by=N-2;by>=0;by--){
            for(int cx =0;cx<M;cx++){
                map[by+1][cx]=map[by][cx];
                if(map[by+1][cx]==1){
                    enemy++;
                }
            }
        }
        for(int bx=0;bx<M;bx++ ){
            map[0][bx]=0;
        }
    }

    go(idx + 1);

}

void copy() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = copymap[i][j];
        }
    }
}

void dfs(int a, int cnt) { //궁수 3명 정하기 백트레킹
    if (a > M) {
        return;
    }
    if (cnt == 3) {
        int k = 0;
        memset(flyInfo, false, sizeof(flyInfo));

        for (int i = 0; i < M; i++) {
            if (fly[i] == 1) {
               //  printf("%d\t",i);
                flyInfo[k].y = N; //궁수 정보 저장
                flyInfo[k].x = i;
                flyInfo[k].dead = false;
                k++;
            }
        }
      //    printf("\n");
        res = 0;
        enemy=-1;
        go(0);
        copy();
        if (ans < res) {
            ans = res;
        }
       // printf("aaa%d\n",ans);
        return;
    }

    fly[a] = 1;
    dfs(a + 1, cnt + 1);
    fly[a] = 0;
    dfs(a + 1, cnt);
}

int main() {

    scanf("%d %d %d", &N, &M, &D);
    int a = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a);
            map[i][j] = a;
            copymap[i][j] = a;
        }

    }

    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}