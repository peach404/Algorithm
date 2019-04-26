//
// Created by 김소연 on 26/04/2019.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int a[4];
int b[4];
int main() {

    for(int i=0;i<3;i++) {
        scanf("%1d", &a[i]);
    }
    for(int i=0;i<3;i++) {
        scanf("%1d", &b[i]);
    }

    int num1 = a[2]*100 + a[1]*10 + a[0];
    int num2 = b[2]*100 + b[1]*10 + b[0];

    printf("%d",max(num1,num2));

    return 0;
}