//
// Created by 김소연 on 28/02/2019.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int n, m;

bool visited[10001];
int cnt[10001];
int ans[10001];

vector <int> help;

vector<vector<int> > v(10001);


int dfs(int u) {

    if(visited[u]){
        return 0;
    }
    visited[u]=true;
    for (int i = 0; i < v[u].size(); i++) {
        int val = v[u][i];
        cnt[u] += dfs(val);
    }

    return cnt[u]+1;

}


int main() {
    int a, b;
    scanf("%d %d", &n, &m);


    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);

        v[b].push_back(a);
    }


    for (int i = 1; i <=n; i++) {
        memset(visited,false,sizeof(visited));
        memset(cnt,0, sizeof(cnt));
        ans[i] = dfs(i);
    }

    int maxval = ans[1];
    help.push_back(1);

    for(int i=2;i<=n;i++){
        if(ans[i]>maxval){
            maxval=ans[i];
            help.clear();
            help.push_back(i);
        }
        else if(ans[i]==maxval){
            help.push_back(i);
        }
    }

    sort(help.begin(),help.end());
    int len=help.size();
    for(int i=0;i<len;i++){
        printf("%d ",help[i]);
    }

    return 0;
}