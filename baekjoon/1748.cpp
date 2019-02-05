//
// Created by 김소연 on 04/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    int n;

    scanf("%d",&n);

    int tmp=9;
    int ans=0;
    int i=1;
    while(tmp < n){

        ans += tmp * i;
        n-=tmp;
       // printf("n: %d\n",n);
        tmp*=10;
        i++;
    }
    ans+= i*n;

    printf("%d\n",ans);

    return 0;
}