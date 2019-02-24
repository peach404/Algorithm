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

    long long dp[10001];
    int coin[101];
    int n,k;


    scanf("%d %d",&n,&k);

    for(int i=0;i<n;i++){
        scanf(" %d",&coin[i]);
    }
    dp[0]=coin[0];

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            dp[i] =
        }
    }
    return 0;
}