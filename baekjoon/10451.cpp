//
// Created by 김소연 on 04/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

bool visited[1001];
int arr[1001];
int n;

void dfs(int num) {
    visited[num]=true;
    if(!visited[arr[num]]) {
        dfs(arr[num]);
    }

}

int main() {
    int T;

    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {

        scanf("%d", &n);
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}