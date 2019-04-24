//
// Created by 김소연 on 24/04/2019.
//

#include <cstdio>

using namespace std;
int map[301][301];

int main() {

    int n,m,k;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            scanf("%d", &map[i][j]);
            if(i==1 &&j==1) continue;
            if (i == 1 && j != 1) {
                map[i][j] = map[i][j - 1] + map[i][j];
            } else if (j == 1 && i != 1) {
                map[i][j] = map[i - 1][j] + map[i][j];
            } else {
                map[i][j] =( map[i - 1][j] + map[i][j - 1] +map[i][j])- map[i - 1][j - 1];

            }
        }
    }

    scanf("%d",&k);

    for(int a=0;a<k;a++){
        int i,j,x,y;
        scanf("%d %d %d %d",&i,&j,&y,&x);

        int ans=map[y][x]-map[i-1][x]-map[y][j-1]+map[i-1][j-1];

        printf("%d\n",ans);

    }


    return 0;
}