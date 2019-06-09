//
// Created by 김소연 on 09/06/2019.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int a,b;
    scanf("%d %d",&a,&b);

    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r;
    while(a%b!=0){
        r = a%b;
        a = b;
        b = r;
    }

    printf("%d",r);



    return 0;
}