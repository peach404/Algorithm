//
// Created by 김소연 on 14/02/2019.
//
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int palace[51][51][4];
int visited[51][51];
int n, m;
int bx[4] = {0, -1, 0, 1};
int by[4] = {-1, 0, 1, 0};
int maxroom = 0;
int roomcnt = 1;
int roomsave[2501];

int bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push({x, y});
    int roomsize = 0;
    maxroom = 0;

    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        visited[qx][qy] = roomcnt;

        int oneroom = 0;
        for (int i = 0; i < 4; i++) {
            {
            if (palace[qx][qy][i] == 0) {
                int nx = qx + bx[i];
                int ny = qy + by[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && visited[nx][ny] == -1) {

                    q.push({nx, ny});
                    visited[qx][qy] = roomcnt;
                    roomsize++;
                    // printf("%d %d %d\n",nx,ny,roomcnt);

                }
            } else {
                oneroom++;
            }
            }
        }

        if (oneroom == 4) {
            roomsize = 1;
            return roomsize;
        }
    }


    return roomsize;

}

int main() {


    scanf("%d %d", &m, &n); //가 세

    memset(visited, -1, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            scanf(" %d", &tmp);

            //2진수로 바꾸기
            for (int k = 4; k >= 0; k--) {
                palace[i][j][k] = (tmp >> k & 1 ? 1 : 0);
            }
        }
    }


    int rsize = 0;
    int maxsize = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == -1) {
                rsize = bfs(i, j);
                roomsave[roomcnt] = rsize;
                roomcnt++;
                if(rsize>0){
                    cnt++;
                }
                if (rsize > maxsize) {
                    maxsize = rsize;
                }
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i + 1 < n && visited[i][j] != visited[i + 1][j]) {
                rsize = roomsave[visited[i][j]] + roomsave[visited[i + 1][j]];
                // printf("%d %d %d\n", roomsave[visited[i][j]], roomsave[visited[i+1][j]], rsize);
                if (rsize > maxroom) {
                    maxroom = rsize;
                }

            }
            if (j + 1 < m && visited[i][j] != visited[i][j + 1]) {
                rsize = roomsave[visited[i][j]] + roomsave[visited[i][j + 1]];
                //  printf("%d %d %d\n", roomsave[visited[i][j]], roomsave[visited[i][j+1]], rsize);
                if (rsize > maxroom) {
                    maxroom = rsize;
                }

            }

        }
    }


    printf("%d\n%d\n%d\n", cnt, maxsize, maxroom);


return 0;
}