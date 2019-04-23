//
// Created by 김소연 on 23/04/2019.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a >b;
}
int main() {
    char arr[1000001];

    scanf("%s",arr);
    int asize = strlen(arr);

    int check[100];
    int tmp=0;
    int maxv=-987654321;
    int maxidx=0;
    vector <int> v;


    for(int i=0;i<asize;i++){

        if(arr[i]>=65 && arr[i]<=90){
            tmp=arr[i]-'A';
        }
        else{
            tmp=arr[i]-'a';
        }
        check[tmp]+=1;
        if(check[tmp]>=maxv){
            maxv = check[tmp];
            maxidx = tmp;
            v.push_back(maxv);
        }
    }
    sort(v.begin(),v.end(),cmp);

    if(v[0]==v[1] && v[0]!=1){
        printf("?\n");
    }else{
        printf("%c",maxidx+'A');
    }
    return 0;
}