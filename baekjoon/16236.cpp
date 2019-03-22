
//
// Created by 김소연 on 21/03/2019.
//

#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[22][22];

int eat;
int shark_size;
int N;
int bx[4]={1,-1,0,0};
int by[4]={0,0,1,-1};

struct Shark{
    int y;
    int x;
    int time;
};

Shark shark;

int main() {

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            scanf(" %d", &arr[i][j]);
            if(arr[i][j]==9){
                shark.y = i;
                shark.x = j;
                shark.time = 0;
                shark_size =2;
                arr[i][j]=0;
            }
        }
    }
    bool flag = true;

    while(flag){
        flag = false;

        //초기화
        bool visitied[22][22]={false, };
        queue <Shark> q;
        visitied[shark.y][shark.x]=true;
        q.push(shark);

        //먹을 물고기 후보
        Shark tmpshark;
        tmpshark.y=20;
        tmpshark.time=-1;



       while(!q.empty()){
            Shark cur = q.front();
            q.pop();

            if(tmpshark.time != -1 && tmpshark.time < cur.time){
                break;
            }
            if(arr[cur.y][cur.x]<shark_size  && arr[cur.y][cur.x]>0){
                flag = true;
                if((cur.y==tmpshark.y && cur.x<tmpshark.x)|| tmpshark.y > cur.y) {
                    tmpshark = cur;
                }
            }

            for(int i=0;i<4;i++){
                Shark next;
                next.y = cur.y + by[i];
                next.x = cur.x + bx[i];
                next.time = cur.time + 1;

                if(next.y>=0 && next.x >=0 && next.x<N && next.y<N){

                    if(!visitied[next.y][next.x] && arr[next.y][next.x]<=shark_size){
                        visitied[next.y][next.x]=true;
                        q.push(next);
                    }


                }

            }

        }


        if(flag){
            shark = tmpshark;
            eat++;

            if(eat == shark_size){
                shark_size++;
                eat=0;
            }
            arr[shark.y][shark.x]=0;
        }
    }

    printf("%d\n",shark.time);


    return 0;
}

