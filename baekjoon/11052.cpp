//
// Created by 김소연 on 19/02/2019.
//

#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001]={0};
int d[1001];

int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf(" %d",&arr[i]);
    }
    d[0]=arr[0];
    d[1]=arr[1];


    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) {
            d[i]=max(d[i],d[i-j]+arr[j]);
            //cout << d[i] << '\n';
        }
    }

    printf("%d\n",d[n]);
}