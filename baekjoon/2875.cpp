//
// Created by 김소연 on 12/06/2019.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main(){
    int f,m,k;
    scanf("%d %d %d",&f,&m,&k);

    int sum=0;
    int cnt=m;

    while(1) {

        if(cnt*2<=f){
            sum = (f-cnt*2)+(m-cnt);
            if(sum>=k){
                printf("%d",cnt);
                break;
            }
            cnt--;
        }else{
            cnt--;
        }
    }

    return 0;
}