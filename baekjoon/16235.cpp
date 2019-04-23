


#include <iostream>
#include <string.h>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K;
int A[15][15];
int map[15][15];
struct TREE {
    int y;
    int x;
    int age;
    int idx;
};
vector<TREE> fir;
queue<TREE> dead;
queue<TREE> nextyear;

bool operator<(TREE a, TREE b) {
    return (a.age >= b.age);
};
TREE tree[101];

int treecnt = 0;
int by[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int bx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring() {
    if (fir.size()>0) {
        sort(fir.begin(),fir.end());
        for(int i=0;i<fir.size();i++) {
            TREE val = fir[i];

            if (val.age <= map[val.y][val.x]) {
                map[val.y][val.x] -= val.age;
                tree[val.idx].age += 1;
                nextyear.push(tree[val.idx]);
            } else {
                dead.push(tree[val.idx]);

            }
        }
    }
    fir.clear();
}

void summer() {
    while (!dead.empty()) {
        TREE dead_tree = dead.front();
        map[dead_tree.y][dead_tree.x] += (dead_tree.age / 2);
        dead.pop();
    }
}

void fail() {

    while (!nextyear.empty()) {
        TREE tmp= nextyear.front();
        if (tmp.age % 5 == 0) {
            for (int j = 0; j < 8; j++) {
                int ny = by[j] + tmp.y;
                int nx = bx[j] + tmp.x;

                if (ny <= 0 || nx <= 0 || ny > N || nx > N) {
                    continue;
                }

                tree[treecnt].y = ny;
                tree[treecnt].x = nx;
                tree[treecnt].age = 1;
                tree[treecnt].idx = treecnt;
                fir.push_back(tree[treecnt]);
                treecnt++;
            }
            fir.push_back(tree[tmp.idx]);
        } else {

            fir.push_back(tmp);
        }
        nextyear.pop();
    }
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] += A[i][j];
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
            map[i][j] = 5;
        }
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &tree[i].x, &tree[i].y, &tree[i].age);
        tree[i].idx = i;
        fir.push_back(tree[i]);
        treecnt++;
    }

    while (K--) {
        spring();
        summer();
        fail();
        winter();
    }
    int res=fir.size();
    printf("%d\n",res );

    return 0;
}