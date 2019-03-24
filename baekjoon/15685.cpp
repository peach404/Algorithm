//
// Created by 김소연 on 24/03/2019.
//

#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int by[4]={0,-1,0,1};
int bx[4]={1,0,-1,0};
int map[101][101]={0, };
int main() {

    int n;

    scanf("%d",&n);


    for(int i=0;i<n;i++){

        int carve[1024]={0, };
        int carve_size=0;

        int x,y,d,g;
        scanf("%d %d %d %d",&x,&y,&d,&g);

        carve[carve_size++]=d;
        map[y][x]=1;

        for(int j=0;j<g;j++){
            for(int k=carve_size-1;k>=0;k--){ //k = 이전 커브
                carve[carve_size++]=(carve[k]+1) %4;
            }
        }

        for(int a=0;a<carve_size;a++) {
          y += by[carve[a]]; //커브는 그 전 좌표에 다가 새로운 방향 값을 더해야 한다!!!!!!!!!!
          x += bx[carve[a]];
            if(y>=0 && x>=0 && y<101 && x<101) {
                map[y][x] = 1;
            }
        }
    }
    int ret = 0;
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (map[y][x]==1 && map[y][x + 1]==1 && map[y + 1][x]==1 && map[y + 1][x + 1]==1) {
                ++ret;
            }
        }
    }

    printf("%d\n", ret);

    return 0;
}