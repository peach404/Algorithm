//
// Created by 김소연 on 30/01/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int N, M, H;
int tomato[101][101][101];
int check[101][101][101];
int tcnt;
int d[6][3] = {
        {0,  0,  -1},
        {0,  0,  1},
        {0,  1,  0},
        {0,  -1, 0},
        {1,  0,  0},
        {-1, 0,  0}};

struct qtype {
    int z, x, y;
};
queue<qtype> q;

int bfs() {
    int day = 0;
    while (!q.empty()) {
        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {
            qtype qtop = q.front();
            q.pop();

            int tz = qtop.z;
            int tx = qtop.x;
            int ty = qtop.y;
            check[tz][tx][ty]=1;

            for (int a = 0; a < 6; a++) {
                int nz = d[a][0] + tz;
                int nx = d[a][1] + tx;
                int ny = d[a][2] + ty;

                if (nx >= 0 && ny >= 0 && nz >= 0 && nx < M && ny < N && nz < H) {
                    if (tomato[nz][nx][ny] == 0 && check[nz][nx][ny]==0) {
                        q.push({nz, nx, ny});
//                        printf("%d %d %d\n", nz, nx, ny);
                        tomato[nz][nx][ny] = 1;
                        check[nz][nx][ny]=1;

                    }

                }
            }

        }
        day++;
    }


    return day;
}


int main() {

    scanf("%d %d %d", &N, &M, &H);

    memset(tomato, -1, sizeof(tomato));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                int tmp;
                scanf("%d", &tmp);
                tomato[i][j][k] = tmp;
                if (tmp == 0) {
                    tcnt++;
                }
                if (tmp == 1) {

                    q.push({i, j, k});
                }
            }
        }
    }

    if (tcnt == 0) {
        printf("0");
        return 0;
    }

    int result = bfs();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (tomato[i][j][k] == 0) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    printf("%d", result-1);

    return 0;
}