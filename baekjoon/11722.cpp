//
// Created by 김소연 on 24/04/2019.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int main() {

    int arr[1001]={0,};
    int n=0;
    int dp[1001]={0, };
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j <i;j++){
            if(arr[i] < arr[j] && dp[j]+1>dp[i])
                // 현재 비교하고 있는 인덱스의 값을 선택하는 것이 최대 길이가 될 수 있는가?
                dp[i] = dp[j]+1;
        }
    }
    int maxv=-987654321;
    for(int i=0;i<n;i++){
        maxv = max(maxv,dp[i]);
    }
    printf("%d",maxv);
    return 0;
}