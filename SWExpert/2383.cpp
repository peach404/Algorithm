
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>


using namespace std;

int n;
int map[15][15];
int check[10];
vector<pair<int, int> > person;
vector<pair<int, int> > stair;
int pcnt;

int res=987654321;

int abs(int a) {
    return a > 0 ? a : -a;
}


int cal(int sy, int sx, int py, int px) {
    return abs(sy - py) + abs(sx - px);

}

int go() {
    int tmp = 0;
    priority_queue<int,vector<int>, greater<int> > st[2];
    for (int i = 0; i < pcnt; i++) {
        if (check[i] == 1) {
            tmp = cal(stair[0].first, stair[0].second, person[i].first,person[i].second) + 1;
            st[0].push(tmp);
        }
        if (check[i] == 2) {
            tmp = cal(stair[1].first, stair[1].second, person[i].first,person[i].second) + 1;
            st[1].push(tmp);
        }
    }

    int ans=0;
    for (int i = 0; i < 2; i++) {
        int a = 0;
        int b = 0;
        int c = 0;

        if (!st[i].empty()) {
            for (int t = 0;; t++) {

                if (a == 0 && b == 0 && c == 0 && st[i].empty()) {
                    if(ans<t){
                        ans = t;
                    }
                    break;
                }
                if (a > 0)a--;
                if (b > 0)b--;
                if (c > 0)c--;


                while (t >= st[i].top() && !st[i].empty()) {


                    if (a == 0) {
                        a = map[stair[i].first][stair[i].second];
                    }
                    else if (b == 0) {
                        b = map[stair[i].first][stair[i].second];
                    }
                    else if (c == 0) {
                        c = map[stair[i].first][stair[i].second];
                    }else break;
                    st[i].pop();
                }
            }

        }
    }
    return ans;
}



int val=0;
void dfs(int idx, int cnt) {

    if (cnt == pcnt) {
        val=go();
        if(val<res){
            res = val;
        }
        return;
    }

    for (int i = idx; i < pcnt; i++) {
        if (check[i] != 1) {
            check[i] = 1;
            dfs(idx + 1, cnt + 1);
        }
        if (check[i] != 2) {
            check[i] = 2;
            dfs(idx + 1, cnt + 1);
        }
        return;
    }

}

int main() {

    int T = 0;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {
        scanf("%d", &n);
        pcnt = 0;
        memset(check,0,sizeof(check));
        memset(map,0,sizeof(map));
        person.clear();
        stair.clear();
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &map[i][j]);

                if (map[i][j] == 1) {
                    person.push_back({i, j});
                    pcnt++;
                }
                else if (map[i][j] > 1) {
                    stair.push_back({i, j});

                }
            }
        }
        res=987654321;
        dfs(0, 0);
        printf("#%d %d\n",tc+1,res-1);
    }
    return 0;
}