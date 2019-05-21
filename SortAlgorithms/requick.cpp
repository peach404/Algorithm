//
// Created by 김소연 on 21/05/2019.
//

#include <iostream>
#include <cstdio>

using namespace std;
int arr[100];

void quick(int left,int right){
    int i=left+1;
    int j=right;

    while(i<j){
        bool flag = true;
        while(flag){
            flag = false;
            if(arr[i] < arr[left] && i<right){
                i++;
                flag = true;
            }
        }
        flag = true;
        while(flag){
            flag = false;
            if(arr[j] > arr[left] && j >left){
                j--;
                flag = true;
            }

        }

       if(i<j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    if(arr[left] > arr[j]){
        int tmp = arr[left];
        arr[left] = arr[j];
        arr[j] = tmp;
    }

    if(j-1 >left) {
        quick(left, j - 1);
    }
    if(j+1 <right) {
        quick(j + 1, right);
    }

}


int main() {
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quick(0,n-1);
    for(int i=0;i<n;i++) {
        printf("%d \t", arr[i]);
    }

    return 0;
}
