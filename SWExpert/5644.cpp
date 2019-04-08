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

int M,A;
int movearr[2][101];


struct AP{
    int y;
    int x;
    int c; // 충전 범위
    int p; // 성능
    bool use;
}ap[8];

struct USER{
    int y;
    int x;
}user[2];

int cal_d(int ax,int bx,int ay,int by){

    int d1 = ax-bx>0 ? ax-bx : bx-ax;
    int d2 = ay-by>0 ? ay-by : by-ay;

    return d1+d2;

}


void go(){



}

int main() {

    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {




        scanf("%d %d", &M, &A);


        for (int i = 0; i < 2; i++) {
            for(int j=0;j<M;j++){
                scanf("%d", &movearr[i][j]);
            }
        }

        for (int i = 0; i < A; i++) {
            int y, x, cval, pval;
            scanf("%d %d %d %d", &x, &y, &cval, &pval);
            ap[i].c = cval;
            ap[i].p = pval;
            ap[i].x = x;
            ap[i].y = y;
            ap[i].use = false;
        }

        user[0].x=1;
        user[0].y=1;
        user[1].x=10;
        user[1].y=10;

        go();



        printf("#%d %d\n", tc + 1);

        memset(movearr, 0, sizeof(movearr));
        memset(ap,0,sizeof(ap));


        }


        return 0;
    }

