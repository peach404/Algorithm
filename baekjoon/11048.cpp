//
// Created by 김소연 on 25/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    int arr[1001][1001];
    int dp[1001][1001];

    scanf("%d %d", &n, &m);

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {
            scanf(" %d", &arr[i][j]);
        }
    }
    dp[0][0] = arr[0][0];

    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <=m ; j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + arr[i][j];
        }
    }

    printf("%d\n",dp[n][m]);
    return 0;
}