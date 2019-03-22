//
// Created by 김소연 on 21/03/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N,S;
int ans;
int arr[1000001];
int sum;

void dfs(int idx){
    if(idx == N){
        return;
    }

    if(sum + arr[idx] == S ){
        ans++;
    }


    dfs(idx+1);

    sum+= arr[idx];
    dfs(idx+1);
    sum-= arr[idx];
}


int main() {

    scanf("%d %d",&N,&S);

    for(int i=0;i<N;i++){
        scanf(" %d",&arr[i]);
    }

    dfs(0);

    printf("%d\n",ans);
    return 0;
}

