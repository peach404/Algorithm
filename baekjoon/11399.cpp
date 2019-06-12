//
// Created by 김소연 on 11/06/2019.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr;
int sum[1001];
int main(){

    int n;
    int tmp=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    sum[0]=arr[0];
    int ans =sum[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+arr[i];
        ans+= sum[i];
    }

    printf("%d\n",ans);

    return 0;
}