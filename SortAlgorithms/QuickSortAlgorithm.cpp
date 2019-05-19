//
// Created by 김소연 on 19/05/2019.
//

#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int arr[10]={5,4,7,6,10,8,3,1,2,9};

struct Box{
    int l;
    int r;
    int k;
};
Box box;

void quick(int left,int right){
    int i=left+1;
    int j=right;

    while(i<j)
    {
        bool flag = true;
        while (flag) {
            flag = false;
            if (arr[i] < arr[left] && i<right) {
                i++;
                flag = true;
            }
        }
        flag = true;
        while(flag){
            flag = false;
            if(arr[j]>=arr[left] && j >left)
            {
                j--;
                flag = true;
            }
        }

        if(i <j){
            int tmp = arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;

        }
    }


    if(arr[left] >arr[j]){
        int tmp = arr[left];
        arr[left] = arr[j];
        arr[j] = tmp;
    };


    if(left < j - 1) {
        quick(left, j - 1);
    }

    if (right> j+ 1) {

        quick(j+1,right);
    }

}

int main() {


    quick (0, 9);


    for(int i=0;i<10;i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");


    return 0;
}