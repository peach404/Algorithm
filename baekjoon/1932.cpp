////
//// Created by 김소연 on 31/01/2019.
////

#include <cstdio>

int main(){
    int N;
    long long num[501][501]={0,};
    long long max[501][501]={0,}; //최대값이 저장될 배
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        for(int j=0; j <i + 1 ;j++){
            scanf("%lld",&num[i][j]);
        }
    }

    max[0][0] = num[0][0];
    for(int i = 0 ; i < N-1 ; i++){
        for(int j=0; j <i + 1 ;j++){
            if( max[i+1][j] < max[i][j] + num[i+1][j]) //왼쪽 대각선
                max[i+1][j] = max[i][j] + num[i+1][j];

            if( max[i+1][j+1] < max[i][j] + num[i+1][j+1]) //오른쪽 대각선
                max[i+1][j+1] = max[i][j] + num[i+1][j+1];
        }
    }

    long long ans = 0;
    for(int i = 0 ; i < N ; i++){
        if(max[N-1][i] > ans)
            ans = max[N-1][i] ;
    }
    printf("%lld\n",ans);

    return 0;
}