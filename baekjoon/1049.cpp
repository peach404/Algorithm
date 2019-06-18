//
// Created by 김소연 on 18/06/2019.
//

#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
//꼭 같은 패키지 안사도 됨

int main() {

    cin >> n >> m ;

    int a =0;
    int b =0;
    int c =987654321;
    int d =987654321;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        c = min(a,c);
        d = min(d,b);
    }


    int ans=987654321;
    int num;
    int num2;
    if(n>6) {

        int val = n / 6;
        int tmp = n % 6;

        num = (val * c) + (tmp * d);
        num2 = n * d;
        ans = min(num,num2);
        if(tmp>0){
            num = c *(val+1);
            ans = min(ans, num);
        }

    }else{

        num = c;
        num2 = n * d;
        ans = min(num,num2);
    }

    printf("%d",ans);

    return 0;
}