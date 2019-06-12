//
// Created by 김소연 on 12/06/2019.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
//10의 5승은 int 형으로 못 받아서 문자열로 받아야한다!!!!!!!!!


int main(){
    int ans=0;
    bool flag = false;
    vector <int> v;
    char tmp[100001];
    scanf("%s",tmp);
    int a;
    int sum=0;
    int k=strlen(tmp);
    for(int i=0;i<k;i++){
        a=tmp[i]-'0';
        sum+=a;
        if(a == 0){
            flag = true;
        }
        v.push_back(a);
    }
    int size = v.size();

    if(sum%3==0 && flag){
        sort(v.begin(),v.end(),greater<int> ());
        for(int i=0;i<size;i++){
            printf("%d",v[i]);
        }
    }else{
        printf("-1\n");
        return 0;
    }


    return 0;
}
