//
// Created by 김소연 on 14/02/2019.
//

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int price;
    int change=1000;
    int cnt=0;

    scanf("%d",&price);
    change-=price;

    while(change!=0){
        if(change>=500){
            change-=500;
            cnt++;
        }
        else if(change>=100){
            change-=100;
            cnt++;
        }else if(change>=50){
            change-=50;
            cnt++;
        }
        else if(change>=10){
            change-=10;
            cnt++;
        }else if(change>=5){
            change-=5;
            cnt++;
        }
        else if(change>=1){
            change-=1;
            cnt++;
        }

    }

    if(price==0){
        cnt=0;
    }
    printf("%d\n",cnt);

    return 0;
}