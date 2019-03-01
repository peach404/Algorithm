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
bool flag=false;
bool check[10];
vector<pair<int, int> > v;

///////이건 모름
bool ispossible(int x,int y) {
    int check = 0;

    for (int i = 0; i < 9; i++) {
        if (arr[x][i] == 0) continue;
        if (check & (1 << arr[x][i]))return false;
        check |= (1 << arr[x][i]);
    }

    check = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i][y] == 0) continue;
        if (check & (1 << arr[i][y]))return false;
        check |= (1 << arr[i][y]);
    }
    check = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((x / 3 == i / 3) && (y / 3 == j / 3)) {
                if (arr[i][j] == 0) continue;
                if (check & (1 <<arr[i][j]))return false;
                check |= (1 << arr[i][j]);
            }
        }

    }
    return true;
}

void print(){
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
//백트랙킹으로 1~9 까지 숫자 넣어보고 맞는지 판단한다.
void back(int idx){
    if(flag){
        return;
    }
    if(idx == v.size()){
        print();
        flag=true;
    }
    else {
        int ny = v[idx].first;
        int nx = v[idx].second;

        for (int i = 1; i < 10; i++) {

            arr[ny][nx] = i;
            if (ispossible(ny, nx)) {
                back(idx + 1);
            }
            arr[ny][nx] = 0;
        }
    }
}


int main() {
    int bin = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %d", &bin);
            arr[i][j] = bin;

            if (bin == 0) {
                v.push_back({i, j});
            }
        }
    }

    memcpy(tmp, arr, sizeof(arr));
    back(0);


    return 0;
}