//
// Created by 김소연 on 25/04/2019.
//

#include <cstdio>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char arr[200];
    string str;
    scanf("%s",arr);
    int size = strlen(arr);

    for(int i=0;i<size;i++){
        if(arr[i]>=65 && arr[i]<=90){
            str+=arr[i];
        }
    }

    cout <<str;
    return 0;
}