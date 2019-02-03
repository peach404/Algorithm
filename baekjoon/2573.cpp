//
// Created by 김소연 on 01/02/2019.
//

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int ice[301][301];
bool visited[301][301];

int N, M;

int bx[4] = {1, -1, 0, 0};
int by[4] = {0, 0, 1, -1};

int icecnt;
int check;

void checkice(int i, int j) {
    if (visited[i][j])
        return;

    queue<pair<int, int> > c;
    visited[i][j] = true;
    c.push({i, j});

    while (!c.empty()) {
        int dx = c.front().first;
        int dy = c.front().second;

        c.pop();

        for (int a = 0; a < 4; a++) {
            int cx = dx + bx[a];
            int cy = dy + by[a];

            if (ice[cx][cy] != 0 && !visited[cx][cy] && cx >= 0 && cy >= 0 && cx < N && cy < M) {
                visited[cx][cy] = true;
                c.push({cx, cy});
            }

        }
    }


}

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp = 0;
            scanf(" %d", &tmp);
            ice[i][j] = tmp;
        }
    }

    icecnt = 0;
    int year = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ice[i][j] != 0 && !visited[i][j]) {
                checkice(i, j);
                icecnt++;
            }
        }
    }

    if (icecnt < 2) {
        while (icecnt < 2) {
            icecnt = 0;
            check = 0;
            memset(visited, false, sizeof(visited));

            //빼기 bfs
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if(ice[i][j] == 0 && !visited[i][j]) {

                        for (int a = 0; a < 4; a++) {
                            int cx = i + bx[a];
                            int cy = j + by[a];

                            if (ice[cx][cy] != 0 && !visited[cx][cy] && cx >= 0 && cy >= 0 && cx < N && cy < M) {
                                ice[cx][cy] -= 1;
                                check++;
                                if(ice[cx][cy] == 0) visited[cx][cy] = true;
                            }

                        }

                    }
                }
            }

            memset(visited, false, sizeof(visited));

            //체크 bfs
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (ice[i][j] != 0 && !visited[i][j]) {
                        checkice(i, j);
                        icecnt++;

                    }
                }
            }
            if (check == 0) {
                year = 0;
                break;
            } else
                year++;

        }
    }

    printf("%d", year);

    return 0;
}