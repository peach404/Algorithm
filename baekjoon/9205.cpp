//
// Created by 김소연 on 01/03/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int n;
vector<pair<int, int> > all;
bool visited[101];

void dfs(int ind) {

    visited[ind]=true;

    int y = all[ind].first;
    int x = all[ind].second;

    for(int i=1;i<n+2;i++){
        int ny = all[i].first;
        int nx = all[i].second;


        if(!visited[i]) {

            //printf("%d %d\n",sum1,sum2);
            if ((abs(ny-y) + abs(nx-x)) <= 1000) {
                dfs(i);
            }
        }
    }

}


int main() {

    int T;
    scanf("%d", &T);


    for (int tc = 0; tc < T; tc++) {
        scanf("%d", &n);

        for (int i = 0; i < n + 2; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            all.push_back({a, b});
        }
        all.push_back({0,0});
        visited[0]=true;
        dfs(0);
        if (visited[n+1]) {
            printf("happy\n");
        } else {
            printf("sad\n");
        }
        all.clear();
        memset(visited,false,sizeof(visited));


    }


    return 0;
}