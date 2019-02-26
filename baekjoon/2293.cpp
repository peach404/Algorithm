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

    int dp[10001]={0,};
    int coin[101]={0,};
    int n,k;


    scanf("%d %d",&n,&k);

    for(int i=1;i<=n;i++){
        scanf("%d",&coin[i]);
    }
    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=coin[i];j<=k;j++){
      //      printf("dp[%d] : %d coin[%d]:%d dp[j-coin[i]]:%d\n",j,dp[j],i,coin[i],dp[j-coin[i]]);
            dp[j] += dp[j-coin[i]];
        }
    }

    printf("%d\n",dp[k]);
    return 0;
}