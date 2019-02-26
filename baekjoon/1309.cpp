//
// Created by 김소연 on 26/02/2019.
//


#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int dp[100001][3];

    scanf("%d",&n);
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;

    for(int i=2;i<=n+1;i++){
        dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0]+dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0]+dp[i-1][1]) % 9901;
    }

    printf("%d\n",dp[n+1][0]);

    return 0;
}