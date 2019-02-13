//
// Created by 김소연 on 13/02/2019.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;
int N,M,a,b;
int minv=987654321;
int ans;


int bfs(vector<vector <int>> friends,int num){
    vector<int> sumv(N+1);
    queue <int> q;

    q.push(num);
    while(!q.empty()){
        int nq = q.front();
        q.pop();

        int nsize = friends[nq].size();
        for(int i=0;i<nsize;i++){
            int val = friends[nq][i];
            if(sumv[val] == 0 && val != num) {
                sumv[val] = sumv[nq] + 1;
                q.push(val);
            }
        }
    }
    int idxsum=0;
    for(int i=1;i<=N;i++){
        idxsum+=sumv[i];
    }
    return idxsum;
}


int main(){

     scanf("%d %d",&N,&M);
    vector<vector<int>> friends(N+1);
     for(int i=0;i<M;i++){
         scanf("%d %d",&a,&b);
         friends[a].push_back(b);
         friends[b].push_back(a);
     }

     for(int i=1;i<=N;i++){
         int tmp= bfs(friends,i);
         if(tmp < minv){
             minv = tmp;
             ans = i;
         }
     }

     printf("%d\n",ans);
    return 0;

}