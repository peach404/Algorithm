//
// Created by 김소연 on 25/05/2019.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[1001];
int b[1001];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

    for(int i=0;i<n-1;i++){

        int tmp = a[n-1];
        for(int j=n-1;j>0;j--){
            a[j]=a[j-1];
        }
        a[0]=tmp;
        bool flag = false;

        for(int k=0;k<n;k++){
            if(a[k]!=b[k]){
                flag = false;
                break;
            }
            else{
                flag = true;
            }
        }

        if(flag){
            printf("true\n");
            return 0;
        }
    }
    printf("false\n");

    return 0;
}