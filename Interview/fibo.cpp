//
// Created by 김소연 on 24/05/2019.
//

#include <cstdio>
#include <iostream>

using namespace std;

int arr[10000];
int n;

int fibo(int i){

    if(i<=1){
        return i;
    }


    return fibo(i-1)+fibo(i-2);
}

int memofibo(int i){

    if(i<=1){
        return i;
    }
    else if(arr[n]!=0){
        return arr[i];
    }else{
        return arr[i] = memofibo(i-1)+memofibo(i-2);
    }


}

int main(){


    scanf("%d",&n);


  //  int ans=fibo(n);
   int ans = memofibo(n);

    printf("%d",ans);

    return 0;
}