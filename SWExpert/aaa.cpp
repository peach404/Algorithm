//
// Created by 김소연 on 16/03/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

int main() {
    int n;
    int arr[1000002];
    int tmp =0;
    int idx=0;

    priority_queue <pair <int,int> >pq;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);
        pq.push({arr[i],i+1});
        if(arr[i]>tmp){
            tmp = arr[i];
            idx = i+1;
        }
    }
    int t=n/2;
    int nf=0;
    int ns=0;
    int max=0;
    while(t--){
        nf=pq.top().first;
        ns=pq.top().second;
        pq.pop();

        if(nf<tmp){
           int a =idx-ns;
           if(a>max){
               max = a;
           }
        }

    }
    printf("%d\n",max);

    return 0;
}