
 //Created by 김소연 on 30/01/2019.


#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int check[101]={1,1};
 int point;
 int line;

queue <int >q;

//그래프와 bfs 합친 문제
int bfs(vector<vector<int >> arr ,int num){

    q.push(num);
    int cnt =0;

    while(!q.empty())
    {
        int nq = q.front();
        q.pop();
        int a = arr[nq].size();
        for(int i=0;i<a;i++){
            int tmp =arr[nq][i];
            if(check[tmp]==0 ){
                q.push(tmp);
                check[tmp]=1;
                cnt++;
            }

        }

    }
    return cnt;
}



int main(){
    scanf("%d %d",&point,&line);
    vector<vector<int>> arr(point+1);

    for(int i=0;i<line;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        arr[u].push_back(v);
        arr[v].push_back(u);
}

    int result=bfs(arr,1);
    printf("%d",result);
    return 0;
}

