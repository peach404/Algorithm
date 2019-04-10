//
// Created by 김소연 on 11/04/2019.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>


using namespace std;
/**
 n 가로 세로
 K 군집의 개수
 M 시간
바깥쪽 가장자리 특수한 약품 칠해짐
각 군집은 1시간마다 이동방향에 있는 다음 셀로 이동
M 시간 후에 남아 있는 미생물 수의 총합을 구하라


조건 1) 약품이 칠해진 가장자리에 도착하면 군집 내 미생물의 절반이 죽고
조건 1-1)이동방향이 반대로 바뀜
조건 1-2) 홀수인 경우 2로 나눈 후 소수점 이하는 버림
   => 따라서 미생물 수가 0이 되면 군집이 사라짐

조건 2) 이동 후 두 개 이상의 군집이 한 셀에 모이는 경우 군집들이 합쳐진다
조건 2-2) 합쳐 진 군집의 미생물 수는 군집들의 미생물 수의 합이며,
 이동 방향은 군집들 중 미생물 수가 가장 많은 군집의 이동방향이 된다.
 군집의 idx 값도 가장 큰 idx 값에 합쳐친다.

**/

struct Crowd {
    int y;
    int x;
    int kcnt;
    int d;
};
int by[5]={0,-1,1,0,0}; //1 상 2 하 3 좌 4 우
int bx[5]={0,0,0,-1,1};


int N,M,K;
int main() {
    int T=0;
    scanf("%d",&T);

    for(int tc=0;tc<T;tc++) {
        scanf("%d %d %d", &N, &M, &K);
        vector <int> map[101][101];
        vector <Crowd> v(K);
        int y,x,num,d;
        for(int i=0;i<K;i++){

            scanf("%d %d %d %d",&y,&x,&num,&d);
            v[i].y = y;
            v[i].x = x;
            v[i].kcnt = num;
            v[i].d = d;

            map[y][x].push_back(i);
        }

        while(M--){

            for(int i=0;i<K;i++){
                if(v[i].kcnt == 0) continue;
                map[v[i].y][v[i].x].clear();
            }

            for(int i=0;i<K;i++){
                if(v[i].kcnt == 0) continue;
                v[i].y += by[v[i].d];
                v[i].x += bx[v[i].d];
                map[v[i].y][v[i].x].push_back(i);

                if(v[i].y==0 || v[i].x==0 || v[i].x==N-1 || v[i].y==N-1){
                    v[i].kcnt = v[i].kcnt/2;
                    if(v[i].d ==1) v[i].d =2;
                    else if(v[i].d ==2) v[i].d =1;
                    else if(v[i].d ==3) v[i].d =4;
                    else v[i].d =3;
                }
            }

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(map[i][j].size() >1){
                        int s= map[i][j].size();
                        int sum=v[map[i][j][0]].kcnt;
                        int maxkcnt=v[map[i][j][0]].kcnt;
                        int maxd=v[map[i][j][0]].d;
                        int maxidx = map[i][j][0];
                        v[map[i][j][0]].kcnt=0;
                        for(int a=1;a<s;a++){
                            sum+=v[map[i][j][a]].kcnt;
                            if(maxkcnt < v[map[i][j][a]].kcnt){
                                maxkcnt = v[map[i][j][a]].kcnt;
                                maxd = v[map[i][j][a]].d;
                                maxidx = map[i][j][a];
                            }
                            v[map[i][j][a]].kcnt = 0;
                        }
                        v[maxidx].kcnt = sum;
                        v[maxidx].d = maxd;


                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<K;i++){
            if(v[i].kcnt==0)continue;
            res+=v[i].kcnt;
        }



        printf("#%d %d\n",tc+1,res);

    }



    return 0;
}

