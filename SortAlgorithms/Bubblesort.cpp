//
// Created by 김소연 on 21/05/2019.
//

#include <cstdio>
#include <iostream>

using namespace std;
int arr[1001];
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }

    int k=0;
    int cnt = n;
    while(cnt--) {
        int b = n-1;
        int a = b-1;

        while (a >= k) {

            if (arr[b] < arr[a]) {
                int tmp = arr[b];
                arr[b] = arr[a];
                arr[a] = tmp;
            }
            b--;
            a--;
        }
        k++;
    }

    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}