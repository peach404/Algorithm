//
// Created by 김소연 on 28/03/2019.
//


#include <queue>
#include <vector>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M, K; //땅,나무개수,년도

int A[50][50];
int map[50][50];

struct TREE {
    int y;
    int x;
    int age;
};

bool operator<(TREE t, TREE u) {
    return (t.age > u.age); //작은값 나오게 함
}

int bx[8]={ -1, 0, +1, -1, +1, -1, 0, +1 };
int by[8]={-1, -1, -1, 0, 0, +1, +1, +1 };


priority_queue<TREE> pq[2];



int main() {


    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = 5;
            scanf(" %d", &A[i][j]);
        }
    }
    int cur =0;
    int next =0;
    for (int i = 0; i < M; i++) {
        int x, y, z;
        TREE tree;
        scanf("%d %d %d", &tree.x, &tree.y, &tree.age);

        --tree.x;--tree.y;

        pq[cur].push(tree);

    }

    while(K--) {

        next = (cur + 1) % 2;
        queue<TREE> dead;
        queue<TREE> survive;
        //
        while (!pq[cur].empty()) {
            TREE cur_tree = pq[cur].top();
            pq[cur].pop();

            if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
                map[cur_tree.y][cur_tree.x] -= cur_tree.age;
                TREE next_tree;
                next_tree.age = cur_tree.age + 1;
                next_tree.y = cur_tree.y;
                next_tree.x = cur_tree.x;

                survive.push(next_tree);
                pq[next].push(next_tree);
            } else {
                dead.push(cur_tree);
            }
        }


        //여름
        while (!dead.empty()) {
            TREE dead_tree = dead.front();
            dead.pop();
            map[dead_tree.y][dead_tree.x] += (dead_tree.age / 2);
        }

        //가을
        while (!survive.empty()) {
            TREE live = survive.front();
            survive.pop();

            if ((live.age % 5) == 0) {


                for (int k = 0; k < 8; k++) {
                    int ky = live.y + by[k];
                    int kx = live.x + bx[k];
                    TREE next_year;
                    next_year.y = ky;
                    next_year.x = kx;
                    next_year.age = 1;

                    if (ky >= 0 && kx >= 0 && ky < N && kx < N) {


                        pq[next].push(next_year);
                    }
                }
            }

        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] += A[i][j];
            }
        }

        cur = next;

    }
    printf("%d\n",pq[next].size());
    return 0;
}
