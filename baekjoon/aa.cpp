//
// Created by 김소연 on 05/03/2019.
//


#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

string str;

int main(void){
    cin>>str;
    for(int i =0;i<str.size(); i++){
        int now = str[i] - 64;
        printf("%d ", now);
    }
    return 0;
}