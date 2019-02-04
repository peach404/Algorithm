//
// Created by 김소연 on 04/02/2019.
//


#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 100001;
bool visited[MAX];
bool finish[MAX];
int cnt;
int n;
int arr[MAX];
void dfs(int num) {
    visited[num]=true;
    int next = arr[num];

    if(!visited[next]) {
        dfs(next);

    }else if(!finish[next]){ // 사이클을 이루는 경우 다시 방문할 가능성이
                            //있기때문에 한번 더 체크
        for(int i=next;i !=num;i=arr[i])
            cnt++; //팀원 세는것
        cnt++; //자기자신 세는것
    }

    finish[num]=true;
}

int main() {
    int T;

    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {

        scanf("%d", &n);
        memset(visited, 0, sizeof(visited));
        memset(finish,0,sizeof(finish));
        memset(arr,0,sizeof(arr));
        cnt=0;

        for (int i = 1; i <= n; i++) {
            int tmp=0;
            scanf("%d", &arr[i]);

        }

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                dfs(j);

            }
        }
        printf("%d\n", n-cnt);
    }

    return 0;
}