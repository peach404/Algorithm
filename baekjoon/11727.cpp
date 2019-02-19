//
// Created by 김소연 on 19/02/2019.
//

#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

long long arr[1001]={0,1,3};

int main(){
    int n;

    scanf("%d",&n);


    for(int i=3;i<=n;i++){
        arr[i]= arr[i-1]+(2*arr[i-2]);
        arr[i] %= 10007;
    }

    printf("%lld\n",arr[n]);

}