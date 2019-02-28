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

int arr[9][9];
int tmp[9][9];

bool check[10];
queue<pair<int, int> > q;


bool change(int a, int b) {
    int tmpval = 0;
    int ans=0;
    for (int i = 0; i < 10; i++) {

        if (!check[i]) {
            tmpval = i;
        } else {
            ans++;
        }
    }
    if (ans == 9) {
        arr[a][b] = tmpval;
        printf("\n\n%d %d tmpval:%d\n\n", a, b, tmpval);
        q.pop();
        memset(check, false, sizeof(check));
        return true;
    } else {
        int k= 9-ans;
        while(k--) {
            q.pop();
        }
        q.push({a, b});
        memset(check, false, sizeof(check));
        return false;
    }
}

void back(int cnt, int ny, int nx, int num) {
    while (!q.empty()) {


        //가로 검사
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d %d arr:%d\n", i, j, arr[i][j]);
                check[arr[i][j]] = true;
                //back(cnt+1,i,j+1,num+1);
            }
            change(ny, nx);
            ny = q.front().first;
            nx = q.front().second;

        }

//        //세로 검사
//        for (int i = ny; i < 9; i++) {
//            for (int j = 0; j < 9; j++) {
//                check[arr[i][j]] = true;
//                back(cnt + 1, i, j, num + 1);
//            }
//        }
    }
}


int main() {
    int bin = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %d", &bin);
            arr[i][j] = bin;

            if (bin == 0) {
                q.push({i, j});
            }
        }
    }

    memcpy(tmp, arr, sizeof(arr));
    int a = q.front().first;
    int b = q.front().second;

    back(1, a, b, 0);

    return 0;
}