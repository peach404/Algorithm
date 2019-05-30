//
// Created by 김소연 on 30/05/2019.
//
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


int arr1[4][2] = {
        {1, 3},
        {1, 1},
        {2, 3},
        {3, 4}};
int arr2[][2] = {
        {1, 3},
        {3, 4},
        {2, 4},
        {2, 4},
        {2, 3},
        {1, 2}};
int arr3[][2] = {
        {3, 3},
        {2, 2},
        {1, 1},
        {4, 4},
        {5, 5},
        {6, 6}};


int solution(int n, int k, int t[][2] ) {
    int answer = 0;

    //n은 학생 수
    //k는 최대 상담 날짜

    vector <int> sum (k);

    for (int i = 0; i < n; i++) {
        for (int j = t[i][0]; j <= t[i][1]; j++) {
            sum[j - 1] = 1;
        }
    }

    for (int i = 0; i < k ; i++) {
        if (sum[i] == 1) answer++;
    }

    return answer;
}

int main(){

    int ans=solution(6,8, arr3);

    printf("%d",ans);
    return 0;
}