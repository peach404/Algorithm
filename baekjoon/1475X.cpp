//
// Created by 김소연 on 23/04/2019.
//

#include <iostream>
#include <cstdio>
#include <string.h>

int main(){

    char arr[1000001];
    int check[2]={0, };
    int a[11]={0, };
    scanf("%s",arr);

    int len = strlen(arr);
    int ans=0;
    for(int i=0;i<len;i++){
        int tmp = arr[i]-'0';

        if(tmp == 6 || tmp == 9){
           if(check[0]<2){
               check[0]+=1;

           }
           else{
               ans++;
               memset(check,0, sizeof(check));
               check[0]+=1;
           }

        }else if(a[tmp] ==0){
            a[tmp]+=1;
        }else{
            ans++;
            memset(a,0,sizeof(a));
            a[tmp]+=1;
        }
    }
    printf("%d\n",ans+1);

    return 0;
}