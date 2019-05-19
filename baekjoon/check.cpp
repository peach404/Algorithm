//
// Created by 김소연 on 13/05/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int check[100];

int main() {

    int n=0;
    int m=0;
    scanf("%d %d",&n,&m);
    int tmp=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int num =i;

      //  if(num>9) {
            while (num != 0) {
                tmp=num % 10;


                if (tmp == m) {
                    //printf("%d\n",i);
                    cnt++;
                }
                num/=10;
            }
       // }
       // else{
        //    if(i==m){
         //       cnt++;
          //  }

        //}

    }
    printf("%d\n",cnt);
    return 0;
}