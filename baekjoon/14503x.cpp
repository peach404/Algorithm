////
//// Created by 김소연 on 04/03/2019.
////
//
//#include <queue>
//#include <vector>
//#include <stack>
//#include <cstdio>
//#include <iostream>
//#include <string.h>
//#include <algorithm>
//
//using namespace std;
//int N,M;
//
//int arr[51][51];
//int visited[51][51];
//int by[4]={-1,0,1,0};
//int bx[4]={0,1,0,-1};
//queue <pair<pair <int,int>, int> >q;
//int ans=0;
//void bfs(int y,int x,int d){
//    q.push({{y,x},d});
//    visited[y][x]=1;
//    if(arr[y][x]==0){
//        ans+=1;
//    }
//
//
//    while(!q.empty()){
//        int cnt=0;
//        int qy = q.front().first.first;
//        int qx = q.front().first.second;
//        int qd = q.front().second;
//
//        q.pop();
//
//        for(int i=0;i<5;i++){
//            qd = (qd+3) %4;
//
//            int ny = qy + by[qd];
//            int nx = qx + bx[qd];
//
//            if(ny>=0 && nx>=0 && ny<N &&nx<M){
//                if( visited[ny][nx]==0 && arr[ny][nx]==0){
//                    visited[ny][nx]=1;
//                    ans+=1;
//                    //printf("%d %d num: %d\n",ny,nx,ans);
//                    q.push({{ny,nx},qd});
//                    break;
//                }
//                cnt++;
//            }
//            if(cnt==4){
//
//                //뒤로가기
////                int tmpqd = qd;
////
////                if(qd==0)qd=2;
////                else if(qd==1)qd=3;
////                else if(qd ==2)qd=0;
////                else qd=1;
//
//                int yy = qy + by[(qd+2)%4];
//                int yx = qx + bx[(qd+2)%4];
//
//                q.push({{yy,yx},qd});
//            }
//
//        }
//    }
//
//}
//
//int main() {
//
//    scanf("%d %d",&N,&M);
//
//    int rx,ry,rd;
//    scanf("%d %d %d",&ry,&rx,&rd);
//
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            scanf(" %d",&arr[i][j]);
//        }
//    }
//
//    bfs(ry,rx,rd);
//    printf("%d\n",ans);
//
//    return 0;
//}


#include<cstdio>
using namespace std;

int n, m, result,flag;
int y, x, dir;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int map[52][52];


int main(void) {

    scanf("%d %d", &n, &m);
    scanf("%d %d %d",&y,&x,&dir);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    while (true) {

        if (map[y][x] == 0) {
            map[y][x] = 2;
            result++;
        }

        for (int i = 0; i < 5; i++) {
            if (i == 4) {
                int next_dir = (dir + 2) % 4;
                int nexty = y + dy[next_dir];
                int nextx = x + dx[next_dir];

                if (map[nexty][nextx] == 1) {
                    flag = 1;
                }
                else {
                    y = nexty;
                    x = nextx;
                }
                break;
            }
            int next_dir = (dir + 3) % 4;
            int nexty = y + dy[next_dir];
            int nextx = x + dx[next_dir];

            if (map[nexty][nextx] == 0) {
                dir = next_dir;
                y = nexty;
                x = nextx;
                break;
            }
            else {
                dir = next_dir;
            }
        }
        if (flag) break;
    }
    printf("%d",result);
    return 0;
}
