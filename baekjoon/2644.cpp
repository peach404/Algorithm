//
// Created by 김소연 on 30/01/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,x,y,line;
queue<int> q;
int check[101];
int bfs(vector<vector<int> >arr ,int a){
    q.push(a);

    while(!q.empty()){
        int nq = q.front();
        q.pop();

        int k = arr[nq].size();

        for(int i=0;i<k;i++){
            int tmp = arr[nq][i];
            if(check[tmp]==0){
                check[tmp] = check[nq]+1;
                q.push(tmp);
            }
        }
    }
    int ans = check[y];
    if(ans == 0){
        ans= -1;
    }

    return ans;
}
int main(){

    scanf("%d %d %d %d",&N,&x,&y,&line);
    vector<vector<int> > arr(N+1);

    for(int i=0;i<line;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

//    check[x]=1;
    int result= bfs(arr,x);

    printf("%d",result);
    return 0;
}