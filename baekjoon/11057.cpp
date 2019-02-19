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
int d[1001]={0,10,55};

int main(){

    int n;
    int ten=10;

    scanf("%d",&n);
    ten*=(n-1);

    for(int i=3;i<=9;i++){
       // for(int j=i+1;j<=9;j++){
            d[i]=d[i-2]+(d[i-1]*9);
        //}
    }
    return 0;
}