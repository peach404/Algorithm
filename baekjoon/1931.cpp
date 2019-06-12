//
// Created by 김소연 on 11/06/2019.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Office{
    int start;
    int end;
};

bool cmp(Office p1,Office p2){

    if(p1.end == p2.end){
        return p1.start < p2.start;
    }else
        return p1.end < p2.end;
}

int main(){

    int n;
    scanf("%d",&n);
    vector <Office> v(n);
    int a,b;
    for(int i=0;i<n;i++){
        scanf("%d %d",&v[i].start,&v[i].end);

    }
    sort(v.begin(),v.end(),cmp);

    int tail = 0;
    int cnt=0;

    for(int i=0;i<v.size();i++){

        if(v[i].start >= tail){
            cnt++;
            tail = v[i].end;
        }

    }
    printf("%d\n",cnt);

    return 0;
}