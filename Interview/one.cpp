//
// Created by 김소연 on 02/06/2019.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    for (int i=2; i<=n; i++){
        for (int j=1; j<i; j++){
            if(num[i]>num[j])
                dp[i] = Math.max(dp[i], dp[j]+1);
            else
                dp[i] = Math.max(dp[i], 1);
        }
    }

    return 0;
}