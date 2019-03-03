//
// Created by 김소연 on 03/03/2019.
//

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int arr[28]= { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10,0 };

int main() {

    char tmp;
    int ans=0;


    while(1) {
        scanf("%1c", &tmp);
        if (tmp == '\n') {
            break;
        }

        tmp= tmp - 'A';
        ans+=arr[tmp];
        }
//        cout <<tmp <<":  "<< ans << "\n";

    cout << ans << "\n";
    return 0;
}
