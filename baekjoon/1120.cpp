//
// Created by 김소연 on 13/06/2019.
//

#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
    char A[55];
    char B[55];
    scanf("%s",A);
    scanf("%s",B);
    int asize = strlen(A);
    int bsize = strlen(B);

    int basic = bsize - asize+1;
    int ans=987654321;
    int k=0;
    while(basic--){
        int cnt=0;
        for(int j=0;j<asize;j++){
        //    printf("%c %c\n",A[j],B[j+k]);
            if(A[j]!=B[j+k]){
                cnt++;
            }
        }
        ans = min(cnt,ans);
        k++;
        //printf("---------\n");
    }
    printf("%d\n",ans);
    return 0;
}