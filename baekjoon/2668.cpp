//
// Created by 김소연 on 26/04/2019.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
bool num[102];
int n;
int arr[102];

void checkfun() {

}

void go(int cnt,int idx) {

    if (cnt > 1) {
        for (int i = 1; i <= n; i++) {
            if (num[i]) {
                printf("%d\t", i);
            }
        }
        printf("\n");

        checkfun();
        return;
    }
    for (int i = idx; i <= n; i++) {
        num[i] = true;
        go(cnt + 1,idx+1);
        num[i] = false;
    }


}

int main() {


    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);

    }
    go(0,1);

    return 0;
}