//
// Created by 김소연 on 12/06/2019.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
// 중요한 점은 모든 로프를 사용할 필요가 없다.


int main(){

    int n;
    scanf("%d",&n);
    vector <int> v(n);
    vector <int> ans(n);

    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
    int k=n;
    for(int i=0;i<n;i++){
        ans[i] = v[i]*k;
        k--;
    }
    sort(ans.begin(),ans.end(),greater<int> ());

    printf("%d",ans[0]);


    return 0;
}