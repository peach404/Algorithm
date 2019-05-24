//
// Created by 김소연 on 21/05/2019.
//

#include <cstdio>
#include <iostream>

using namespace std;
int arr[1001];
int main() {
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);
    }

    int minval=0;
    int idx=0;

    for(int i=0;i<n-1;i++){
        minval = arr[i+1];
        idx = i+1;
        for(int j=i+1;j<n;j++){
            if(minval>arr[j]){
                minval = arr[j];
                idx = j;
            }
        }
        if(i != idx && arr[i] >arr[idx]) {
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}