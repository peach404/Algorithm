//
// Created by 김소연 on 08/03/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

int A[102];
int B[102];


struct CPINFO {
    int x;
    int y;
    int c;
    int p;
};
int M, BCcnt;
struct CPINFO cp[10];
int arr[102][2][2];
int bx[5] = {0, 0, 1, 0, -1};
int by[5] = {0, -1, 0, 1, 0};

int tenx[5] = {0, 0, 1, 0, -1};
int teny[5] = {0, -1, 0, 1, 0};


queue<int> q;

void check(int x, int y, int a, int size) {

    int cnt = 0;
    int t = 0;
    int nx = 0;
    int ny = 0;

    bool flag = 0;
    while (size--) {

//        if(x==1&&y==1&& !flag){
//            nx=1;
//            ny=1;
//            flag=true;
//        }else if(x==10 &&y==10 && !flag){
//            nx=10;
//            ny=10;
//            flag=true;


        if (a == 0) {
            nx = x + bx[A[cnt]];
            ny = y + by[A[cnt]];
            a = 0;
        } else {
            nx = x + tenx[B[cnt]];
            ny = y + teny[B[cnt]];
            a = 1;
        }

        int plus = 0;
        int p = 0;
        for (int i = 1; i <= BCcnt; i++) {
            int d = abs(nx - cp[i].x) + abs(ny - cp[i].y);
            if (d <= cp[i].c) {
                if (plus > 0) {
                    p++;
                    arr[t][a][p] = cp[i].p;
                    q.push(t);
                } else {
//                    printf("%d %d\n",cp[i].p,cnt+1);
                    arr[t][a][p] = cp[i].p;
                    plus = cp[i].p;
                }
            }
        }
        x = nx;
        y = ny;
        cnt++;
        t++;
    }


}


int main() {

    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {

        scanf("%d %d", &M, &BCcnt);


        //이동정보 받음
        A[0] = 0;
        B[0] = 0;
        for (int i = 1; i <= M; i++) {
            scanf(" %d", &A[i]);
        }
        for (int i = 1; i <= M; i++) {
            scanf(" %d", &B[i]);
        }

        for (int i = 1; i <= BCcnt; i++) {
            int y, x, cval, pval;
            scanf("%d %d %d %d", &x, &y, &cval, &pval);
            cp[i].c = cval;
            cp[i].p = pval;
            cp[i].x = x;
            cp[i].y = y;
        }

        check(1, 1, 0, M + 1);
        check(10, 10, 1, M + 1);

        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            int a = 0;
            int b = 0;
            int k = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (arr[idx][i][j] > 0) {
                        if (i == 0) {
                            a += 1;
                        } else {
                            b += 1;
                        }
                    }
                }
            }
            if (a == 2 && b == 1) {
                if (arr[idx][0][0] == arr[idx][1][0]) {
                    arr[idx][0][0] = arr[idx][0][1];
                } else if (arr[idx][0][1] == arr[idx][1][0]) {
                    arr[idx][0][1] = 0;
                } else {
                    k = max(arr[idx][0][0], arr[idx][0][1]);
                    arr[idx][0][0] = k;
                    arr[idx][0][1] = 0;
                }
            } else if (a == 2 && b == 0) {
                k = max(arr[idx][0][0], arr[idx][0][1]);
                arr[idx][0][0] = k;
                arr[idx][0][1] = 0;
            } else if (a == 1 && b == 2) {
                if (arr[idx][1][0] == arr[idx][0][0]) {
                    arr[idx][1][0] = arr[idx][1][1];

                } else if (arr[idx][1][1] == arr[idx][0][0]) {
                    arr[idx][1][1] = 0;
                } else {
                    k = max(arr[idx][1][0], arr[idx][1][1]);
                    arr[idx][1][0] = k;
                    arr[idx][1][1] = 0;
                }
            } else if (a == 0 && b == 2) {
                k = max(arr[idx][1][0], arr[idx][1][1]);
                arr[idx][1][0] = k;
                arr[idx][1][1] = 0;

            } else if (a == 2 && b == 2) {
                //큰수 앞으로
                if (arr[idx][0][1] > arr[idx][0][0]) {
                    k = arr[idx][0][1];
                    arr[idx][0][1] = arr[idx][0][0];
                    arr[idx][0][0] = k;
                }

                if (arr[idx][1][1] > arr[idx][1][0]) {
                    k = arr[idx][1][0];
                    arr[idx][1][0] = arr[idx][1][1];
                    arr[idx][1][1] = k;
                }

                //////////////////////////////////////////////

                if (arr[idx][0][0] == arr[idx][1][0]) {

                    if (arr[idx][0][1] > arr[idx][1][1]) {
                        arr[idx][0][0] = arr[idx][0][1];
                        arr[idx][1][1] = 0;
                    } else {
                        arr[idx][1][0] = arr[idx][1][1];
                        arr[idx][0][0] = 0;
                    }

                }
                if (arr[idx][0][0] == arr[idx][1][1]) {
                    arr[idx][0][1] = 0;
                    arr[idx][1][1] = 0;
                }
                if (arr[idx][0][1] == arr[idx][1][1]) {
                    arr[idx][0][1] = 0;
                    arr[idx][1][1] = 0;
                }
                if (arr[idx][0][1] == arr[idx][1][0]) {
                    arr[idx][0][1] = 0;
                    arr[idx][1][1] = 0;
                }
            }

        }
            int all = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j <= M; j++) {
                    if (arr[j][i][0] > 0) {
                        all += arr[j][i][0];
//                    printf("%d %d %d\n",j,i,arr[j][i][0]);
                    }
                }
            }
            printf("#%d %d\n", tc + 1, all);

            memset(A, 0, sizeof(A));
            memset(B, 0, sizeof(B));
            memset(cp, 0, sizeof(cp));
            memset(arr, 0, sizeof(arr));

        }


        return 0;
    }

