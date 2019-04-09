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
    int d; // 충전 범위
    int p; // 성능
    bool use;
}ap[8];

struct USER{
    int y;
    int x;
}user[2];

int bx[5]={0,0,1,0,-1};
int by[5]={0,-1,0,1,0};

int abs(int a){

    return a>0 ? a : -a;
}

bool check(int a,int b){

    int tmp = abs(user[a].y - ap[b].y) + abs(user[a].x - ap[b].x);

    if(tmp <= ap[b].d) {return true;}
    else return false;

}
int ret =0;
void dfs(int user,int d){

    if(user == 2){
        ret = max(d,ret);
        return;
    }

    for(int i=0;i<A;i++){

        if(check(user,i) && !ap[i].use ){
            ap[i].use = true;
            dfs(user+1,ap[i].p+d);
            ap[i].use = false;
        }

    }

    dfs(user+1,d);
}

int middle(){
    ret = 0;
    dfs(0,0);
    return ret;
}


int go(){
    int ans=0;

    ans+= middle();

    for(int i=0;i<M;i++){
        user[0].y += by[movearr[0][i]];
        user[0].x += bx[movearr[0][i]];
        user[1].y += by[movearr[1][i]];
        user[1].x += bx[movearr[1][i]];

      //  printf("%d %d\n",i,ans);
        ans+=middle();
    }
    return ans;
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
            scanf("%d %d %d %d", &ap[i].x, &ap[i].y, &ap[i].d, &ap[i].p);
            ap[i].use = false;
        }

        user[0].x=1;
        user[0].y=1;
        user[1].x=10;
        user[1].y=10;


        printf("#%d %d\n", tc + 1, go());

        memset(movearr, 0, sizeof(movearr));
        memset(ap,0,sizeof(ap));


        }


        return 0;
    }

