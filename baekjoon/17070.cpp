//
// Created by 김소연 on 10/04/2019.
//


#include<iostream>
#include<cstdio>
#include<queue>
#include<stdio.h>
using namespace std;
/*
 r은 행 ,c는 열
 파이프 형태는 2개의 연속된 칸을 차지
 각각의 칸은 빈칸이거나 벽이다
 회전 가능 방향 3가지 가로 세로 내리기 대각선
 처음 파이프는 1,1과 1,2 차지하고 있고 방향은 가로이다.
 파이프 한쪽 끝을 N,N으로 이동시키는 방법의 개수

 1. 가로인 경우 이동 조건
 2. 세로인 경우 이동 조건
 3. 대각선인 경우 이동 조건
 4. 이동시키는 함수

*/
int map[20][20];
bool visited[20][20];
queue <pair< pair<int, int>, int > > q;
int n = 0;
int ans = 0;
bool check(int y, int x) {
    if (y >= 0 && y < n && x >= 0 && x < n) return true;
    else return false;
}

void bfs() {
    while (!q.empty()) {
        int qy = q.front().first.first;
        int qx = q.front().first.second;
        int qmode = q.front().second; //0은 가로, 1 세로 ,2 대각선

        q.pop();

        if (qy == n - 1 && qx == n - 1) {
            ans++;
            visited[qy][qx] = false;
            continue;
        }
        if (qmode == 0) {
            if (check(qy, qx + 1)) {
                if (map[qy][qx + 1] == 0 ) {
                    visited[qy][qx + 1] = true;
                    q.push({ { qy,qx + 1 },0 });

                }
            }
            if (check(qy + 1, qx) && check(qy + 1, qx + 1) && check(qy, qx + 1)) {
                if (map[qy + 1][qx] == 0 && map[qy + 1][qx + 1] == 0 && map[qy][qx + 1] == 0 ) {
                    visited[qy + 1][qx + 1] = true;
                    q.push({ { qy + 1,qx + 1 }, 2 });
                }
            }
        }
        else if (qmode == 1) {
            if (check(qy + 1, qx)) {
                if (map[qy + 1][qx] == 0 ) {
                    visited[qy + 1][qx] = true;
                    q.push({ {qy + 1,qx},1 });
                }
            }
            if (check(qy + 1, qx) && check(qy + 1, qx + 1) && check(qy, qx + 1)) {
                if (map[qy + 1][qx] == 0 && map[qy + 1][qx + 1] == 0 && map[qy][qx + 1] == 0) {
                    visited[qy + 1][qx + 1] = true;
                    q.push({ { qy + 1,qx + 1 }, 2 });
                }
            }
        }
        else if (qmode == 2) {
            if (check(qy, qx + 1)) {
                if (map[qy][qx + 1] == 0 ) {
                    visited[qy][qx + 1] = true;
                    q.push({ { qy,qx + 1 },0 });
                }
            }
            if (check(qy + 1, qx)) {
                if (map[qy + 1][qx] == 0 ) {
                    visited[qy + 1][qx] = true;
                    q.push({ {qy + 1,qx},1 });
                }
            }
            if (check(qy + 1, qx) && check(qy + 1, qx + 1) && check(qy, qx + 1)) {
                if (map[qy + 1][qx] == 0 && map[qy + 1][qx + 1] == 0 && map[qy][qx + 1] == 0 ) {
                    visited[qy + 1][qx + 1] = true;
                    q.push({ { qy + 1,qx + 1 }, 2 });
                }
            }
        }

    }


}

int main() {

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &map[i][j]);
        }
    }
    q.push({ {0,1},0 });
    visited[0][1] = true;
//   printf("-----\n");
    bfs();
    printf("%d\n", ans);
    return 0;
}