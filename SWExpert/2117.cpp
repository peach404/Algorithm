//
// Created by 김소연 on 09/04/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;
int N,M; //M 비용 N 넓이
int map[21][21];


int abs(int a){

    return a>0 ? a : -a;
}
bool check(int homecnt,int k){ // 4번에서 참인지 거짓인지 반별
    int tmp=k*k + (k-1)*(k-1);
    return 0 <= (M*homecnt - tmp);
}

int homecheck(int k,int y,int x){
    int home=0;
    int ay = y-(k-1);
    int ax = x-(k-1);
    int by = y+(k-1);
    int bx = x+(k-1);



    for(int i=ay;i<=by;i++){
        for(int j=ax;j<=bx;j++){
            if(i<0 || i>N-1 || j<0 || j>N-1){
                continue;
            }
            if(map[i][j]==1) {
                int d = abs(i - y) + abs(j - x);
                if (d < k) {
                  //  printf("%d %d\n",i,j);
                    home++;
                }
            }
        }
    }

    return home;

}




/**
 * n*n 크기
 * 마름모 영역에서 제공
 * 마름모 크기는 1이상
 * 크기가 커질수록 운영비용도 커진다
 * 윤영바용 k*k+(k-1)*(k-1)
 * k = 1 비용 1
 * 2일때는 5...
 *
 * 범위를 벗어나도 되고, 운영 비용은 변경되지 않는다
 * 홈 방법 서비스제공 받는 집은 m의 비용을 지불한다
 * 보안회사는 손해를 최대한 보지 않으면서 많은 집에 방법 서비스
 * 손해를 보지 않으면서 홍 방범 서비스를 가장 많은 집에 제공하는 서비스 영역 찾기
 * 그때 집수
 * */




/**
 * 1. 비용 1부터 시작해서 마름모 설정
 * 2. 배열 0,0 부터 n-1,n-1 까지 순회
 * 3. 해당 인덱스 기준 마름모 배열안에 있는 집에 따라 비용 계산
 * 4. 운영비용이 홍 방범 서비스 제공받는 집들의 비용보다 작거나 같을 집 최대값 계산
 * 보안회사의 이익 >= 서비스 제공받는 집들을 통해 얻는 수익 - 운영비용
 * 5. 1번으로 돌아가 반복
 * 6. k는 1부터 n까지
 */

int main() {

    int T;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++){
        int ans=0;
        scanf("%d %d",&N,&M);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=1;k<=N+5;k++) {
                    int res = homecheck(k, i, j);
                    if(res>0 ) {
                        if (check(res, k)) {
                            if (ans < res) {
                                ans = res;
                            }
                        }
                    }
                }
            }
        }

        printf("#%d %d\n",tc+1,ans);
        memset(map,false,sizeof(map));

    }
    return 0;
}