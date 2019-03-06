//
// Created by 김소연 on 06/03/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;
int n, m;
char arr[40][40];
bool roop[40][40][16][5];

int by[4] = {0, 1, 0, -1};
int bx[4] = {1, 0, -1, 0};

//0,1,2,3 =>오,아래,왼,위
int ny;
int nx;
int memo;
bool flag;

void check(int y, int x) {
    if (y < 0) {
        ny = n - 1;
    }
    if (y > n - 1) {
        ny = 0;
    }
    if (x < 0) {
        nx = m - 1;
    }
    if (x > m - 1) {
        nx = 0;
    }
}

bool isroop(int y, int x, int memo, int d) {
    if (!roop[ny][nx][memo][d]) {
        roop[ny][nx][memo][d] = true;
        return true;
    } else {
        return false;
    }
}

int go(int y, int x, int memo, int d) {
    char tmp = arr[y][x];


    //숫자
    if (tmp >= 48 && tmp <= 57) {
        ny = y + by[d];
        nx = x + bx[d];
        memo = tmp - '0';
        check(ny, nx);


        if (isroop(ny, nx, memo, d)) {

            return go(ny, nx, memo, d);
        } else {
            return 0;
        }
    }
    //방향
    if (tmp == '>' || tmp == '<' || tmp == 'v' || tmp == '^') {
        if (tmp == '>') {
            d = 0;
        } else if (tmp == '<') {
            d = 2;
        } else if (tmp == 'v') {
            d = 1;
        } else {
            d = 3;
        }

        ny = y + by[d];
        nx = x + bx[d];

        check(ny, nx);
        if (isroop(ny, nx, memo, d)) {

            return go(ny, nx, memo, d);
        } else {
            //    flag=false;
            return 0;
        }
    }

    if (tmp == '-' || tmp == '+') {
        ny = y + by[d];
        nx = x + bx[d];

        check(ny, nx);

        if (memo == 15) {
            if (isroop(ny, nx, 0, d)) {

                return go(ny, nx, 0, d);
            } else {
                //flag=false;
                return 0;
            }
        } else if (memo == 0) {
            if (isroop(ny, nx, 15, d)) {

                return go(ny, nx, 15, d);
            } else {
                //flag=false;
                return 0;
            }
        } else {

            if (tmp == '-') {
                memo -= 1;
                if (isroop(ny, nx, memo, d)) {

                    return go(ny, nx, memo, d);
                } else {
                    //flag=false;
                    return 0;
                }
            }
            if (tmp == '+') {
                memo += 1;
                if (isroop(ny, nx, memo, d)) {
                    return go(ny, nx, memo, d);
                } else {
                    //flag=false;
                    return 0;
                }
            }
        }

    }
    if (tmp == '_' || tmp == '|') {
        if (tmp == '_') {
            if (memo == 0) {
                d = 0;
            } else {
                d = 2;
            }
        } else {
            if (memo == 0) {
                d = 1;
            } else {
                d = 3;
            }
        }
        ny = y + by[d];
        nx = x + bx[d];

        check(ny, nx);
        if (isroop(ny, nx, memo, d)) {

            return go(ny, nx, memo, d);
        } else {
            return 0;
        }
    }

    if (tmp == '.') {
        ny = y + by[d];
        nx = x + bx[d];

        check(ny, nx);
        if (isroop(ny, nx, memo, d)) {

            return go(ny, nx, memo, d);
        } else {
            return 0;
        }
    }

    if (tmp == '@') {
        flag = true;
        return 1;
    }

    if (tmp == '?') {
        int ans = 0;
        //  for(int i=0;i<4;i++){
        ny = y + by[0];
        nx = x + bx[0];


        check(ny, nx);

        if (isroop(ny, nx, memo, d)) {
            ans = go(ny, nx, memo, 0);
        } else {
            //    flag=false;
            ans = 0;
        }

        if (ans == 1) {
            return 1;
        }


        ny = y + by[1];
        nx = x + bx[1];


        check(ny, nx);

        if (isroop(ny, nx, memo, d)) {
            ans = go(ny, nx, memo, 1);
        } else {
            //    flag=false;
            ans = 0;
        }
        if (ans == 1) {
            return 1;
        }


        ny = y + by[2];
        nx = x + bx[2];


        check(ny, nx);

        if (isroop(ny, nx, memo, d)) {
            ans = go(ny, nx, memo, 2);
        } else {
            //    flag=false;
            ans = 0;
        }

        if (ans == 1) {
            return 1;
        }


        ny = y + by[3];
        nx = x + bx[3];


        check(ny, nx);

        if (isroop(ny, nx, memo, d)) {
            ans = go(ny, nx, memo, 3);
        } else {
            //    flag=false;
            ans = 0;
        }
        if (ans == 1) {
            return 1;
        }

    }
}


int main() {

    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {

        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &arr[i][j]);

            }
        }
        flag = false;
        roop[0][0][0][0] = true;
        int result = go(0, 0, 0, 0);

        if (result == 1) {

            printf("#%d YES\n", tc + 1);
        } else {

            printf("#%d NO\n", tc + 1);
        }
        memset(arr, '\0', sizeof(arr));
        memset(roop, false, sizeof(roop));

    }

    return 0;
}
