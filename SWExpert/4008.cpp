//
// Created by 김소연 on 11/04/2019.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

/**
 *
 * 연산자의 우선 순위는 고려하지 않고 왼쪽에서 오른쪽으로 차례대로 계산한다.
 * 주어진 연산자 카드를 사용하여 수식을 계산했을 때 그 결과가 최대가 되는 수식과
 * 최소가 되는 수식을 찾고 두 값의 차이를 출력하시오
 * + , - , * , / 1 2 3 4
 * **/
int n;
int v[100];
int num[100];


int cal(int mode,int a,int b){
   if(mode==0){
       return a+b;
   }else if(mode==1){
       return a-b;
   }else if(mode==2){
       return a*b;
   }else{
       return a/b;
   }
}
int maxv=0;
int minv=987654321;
int check[15];
int res=0;
void dfs(int cnt,int res){

    if(cnt==n-1){
      //  printf("%d\n",res);
        if(res<minv){
            minv=res;
        }
        if(res>maxv){
            maxv=res;
        }

        return;
    }
    for(int k=0;k<4;k++) {
        if (v[k] > 0) {
            v[k] -= 1;
            dfs(cnt + 1, cal(k, res, num[cnt + 1]));
            v[k] += 1;

        }
    }
}

int main() {

    int T=0;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        scanf("%d",&n);
        int a=0;
        memset(v,0,sizeof(v));
        memset(num,0,sizeof(num));

        for(int i=0;i<4;i++){
            scanf("%d",&v[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }

        minv=987654321;
        maxv=-987654321;
        res=num[0];
        dfs(0,res);

        printf("#%d %d\n",tc+1,maxv-minv);
    }

    return 0;
}

