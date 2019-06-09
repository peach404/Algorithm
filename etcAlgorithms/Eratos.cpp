//
// Created by 김소연 on 09/06/2019.
//

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int arr[1000];
int main(){
    int num=0;

    scanf("%d",&num);
    int k=2;


    while(k*k<=num){
        int i=k;

        if(arr[i]==0){
            while(i<=num/k){

                arr[i*k]=1;
                i++;
            }
        }
        k++;
    }

    for(int i=2;i<=num;i++){
        if(arr[i]==0) {
            printf("%d\n", i);
        }
    }


    return 0;
}