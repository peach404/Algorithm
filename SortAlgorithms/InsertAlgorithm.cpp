//
// Created by 김소연 on 21/05/2019.
//

#include <cstdio>
#include <iostream>

using namespace std;
int arr[1001];
int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);
    }

    int done = 0;


    while(done < n-1 && done>=0){
        int k = done+1;
        int x = arr[k];


        while(k>0){

            if(arr[k-1]>x){
                arr[k] = arr[k-1];
            }else{
                break;
            }
            k--;
        }

        if(k != done+1){
            arr[k]=x;
        }
        done++;

    }

    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}