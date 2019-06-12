//
// Created by 김소연 on 11/06/2019.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];
int main() {

    int n,val;

    scanf("%d %d", &n,&val);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

    }
    int i = n-1;
    int cnt=0;
    while(val !=0 && i>=0){

        if(arr[i]<=val){
            val -= arr[i];
            cnt++;
        }else i--;

    }

    printf("%d\n",cnt);

    return 0;
}