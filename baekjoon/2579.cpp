//
// Created by 김소연 on 26/04/2019.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int stair[310];
int dp[500];
int main() {

    int n;
    scanf("%d",&n);


    for(int i=0;i<n;i++){
        scanf("%d",&stair[i]);
    }

    dp[0]=stair[0];
    dp[1]=max(stair[1],stair[1]+stair[0]);
    dp[2]=max(stair[2]+stair[1],stair[0]+stair[2]);

    for(int i=3;i<n;i++) {
        dp[i]=max(stair[i-1]+stair[i]+dp[i-3],dp[i-2]+stair[i]);
    }

    cout << dp[n-1]<<endl;
    return 0;
}