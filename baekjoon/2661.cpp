//
// Created by 김소연 on 01/03/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[81];
int n;
bool kind(int k){


    for(int i=k;i<=k*2;k++){
        for(int j=k+1;j<k*2;j++){

            if(arr[k] == arr[j])
                return false;
        }
    }
}

void dfs(int u){

    if(u==n){
        return;
    }

    for(int i=1;i<4;i++){
        if(kind(u)){
            arr[u]=i;
            dfs(u+1);
        }

    }
}

int main(){


    scanf("%d",&n);

    dfs(0);

    for(int i=0;i<n;i++){

    }


    return 0;
}