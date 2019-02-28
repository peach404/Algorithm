//
// Created by 김소연 on 28/02/2019.
//


#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char arr[101][101];
char no[101][101];
bool visited[101][101];
bool novisited[101][101];
int bx[4] = {1, 0, -1, 0};
int by[4] = {0, -1, 0, 1};
int n;

void dfs(int y, int x, char cmp) {

    for (int i = 0; i < 4; i++) {
        int ny = y + by[i];
        int nx = x + bx[i];

        if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
            if (!visited[ny][nx] && arr[ny][nx] == cmp) {
                visited[ny][nx] = true;
                dfs(ny, nx, cmp);
            }

        }
    }
}

void dfs2(int y, int x, char cmp) {

    for (int i = 0; i < 4; i++) {
        int ny = y + by[i];
        int nx = x + bx[i];

        if (ny >= 0 && nx >= 0 && nx < n && ny < n) {
            if (!novisited[ny][nx] && no[ny][nx] == cmp) {
                novisited[ny][nx] = true;
                dfs2(ny, nx, cmp);
            }
        }
    }
}


int main() {
    scanf("%d", &n);
    int cnt = 0;
    int nocnt = 0;
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &tmp);
            arr[i][j] = tmp;
            if (tmp == 'G') {
                no[i][j] = 'R';
            } else {
                no[i][j] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                dfs(i, j, arr[i][j]);
                cnt++;
            }
            if (!novisited[i][j]) {
                novisited[i][j] = true;
                dfs2(i, j, no[i][j]);
                nocnt++;
            }

        }
    }

    printf("%d\n%d\n", cnt, nocnt);

    return 0;
}