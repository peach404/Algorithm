//
// Created by 김소연 on 07/02/2019.
//

#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M, x, y, K;
int board[21][21];
int dice[7];
int nx, ny, tmp;

int bx[5]={0,0,0,-1,1};
int by[5]={0,1,-1,0,0};

void check(int dir) {
    if (dir == 1) { //동쪽
        swap(dice[1], dice[3]);
        swap(dice[4], dice[1]);
        swap(dice[6], dice[4]);

    }
    if (dir == 2) { //서쪽
        swap(dice[4], dice[1]);
        swap(dice[1], dice[3]);
        swap(dice[3], dice[6]);
    }
    if (dir == 3) { //북
        swap(dice[5], dice[6]);
        swap(dice[1], dice[5]);
        swap(dice[2], dice[1]);

    }
    if (dir == 4) {
        swap(dice[2], dice[1]);
        swap(dice[1], dice[5]);
        swap(dice[5], dice[6]);
    }
    return;
}

int main() {

    scanf("%d %d %d %d %d", &M, &N, &x, &y, &K);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %d", &board[i][j]);
        }
    }
    for (int i = 0; i < K; i++) {
        int dir = 0;
        scanf(" %d", &dir);

        int nx = x + bx[dir];
        int ny = y + by[dir];

        if(nx >=0 && ny>=0 && nx < M && ny < N) {
            check(dir);

            if (board[nx][ny] == 0) {
                board[nx][ny] = dice[6];
            } else {
                dice[6] = board[nx][ny];
                board[nx][ny] = 0;
            }

            printf("%d\n", dice[1]);
            x = nx;
            y = ny;
        }
    }

    return 0;
}