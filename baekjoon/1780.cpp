//
// Created by 김소연 on 25/04/2019.
//

#include <cstdio>
#include <iostream>

using namespace std;
int map[3000][3000];
int minuscnt = 0;
int zerocnt = 0;
int onecnt = 0;
int n;
void go(int y, int x, int size) {
    bool flag=true;
    for (int ny = y; ny < y+size; ny++) {
        for (int nx = x; nx < x+size; nx++) {
            if (map[ny][nx] != map[y][x]) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        int a = map[y][x];
        switch (a) {
            case 0 :
                zerocnt++;
                break;

            case 1:
                onecnt++;
                break;

            case -1 :
                minuscnt++;
                break;
        }
/////////참이면 cnt 증가되고 다시 함수 호출 됬던 곳으로 돌아감
////////거짓이면 새로운 포문에 들어가서 size/3이 된다.
    }else {
        for (int i = y; i < y+size; i+=size/3) {
            for (int j = x; j <  x+size; j+=size/3) {
                //printf("%d %d %d\n",i,j,size/3);
                go(i, j, size/3);
            }
        }
    }

}


int main() {


    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    go(1, 1, n);

    printf("%d\n%d\n%d\n",minuscnt,zerocnt,onecnt);
    return 0;
}


