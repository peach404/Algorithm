//
// Created by 김소연 on 14/06/2019.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
 // 오름차순 정렬하고 채용된 사람 기준으로 면접 횟수 비교
struct Person {
    int c;
    int m;
};

bool cmp(Person p1, Person p2) {
    return p1.c < p2.c;
}

int main() {
    int T = 0;
    int N = 0;
    scanf("%d", &T);
    while (T--) {

        scanf("%d", &N);
        vector<Person> p(N);

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &p[i].c, &p[i].m);
        }

        sort(p.begin(), p.end(), cmp);

        int cnt = 1;

        int hiredm = p[0].m;
        for (int i = 1; i < N; i++) {
            if (hiredm > p[i].m) {
                cnt++;
                hiredm = p[i].m;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}