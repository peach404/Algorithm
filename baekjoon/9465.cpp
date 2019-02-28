//
// Created by 김소연 on 22/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int arr[2][100001];
int dp[2][100001];
int main () {

    int tc;
    int n;

    scanf("%d",&tc);

    for(int t=0;t<tc;t++){
        scanf("%d",&n);

        for(int k=0;k<2;k++) {
            for (int i = 0; i < n; i++) {
                scanf(" %d", &arr[k][i]);
            }
        }

        dp[0][0]=arr[0][0];
        dp[1][0]=arr[1][0];
        for(int i=1;i<=n;i++){

            dp[0][i] = max(dp[1][i-1],dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1],dp[0][i-2]) + arr[1][i];
        }


        printf("%d\n",max(dp[0][n],dp[1][n]));

        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
    }


    return 0;
}