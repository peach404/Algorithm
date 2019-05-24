//
// Created by 김소연 on 24/05/2019.
//

#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
char arr[100];
int main(){

    scanf("%s",arr);

    int j = strlen(arr);
    j-=1;
    int i=0;
    while(j-i!=1){
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        i++;
        j--;

    }

    printf("%s",arr);

    return 0;
}