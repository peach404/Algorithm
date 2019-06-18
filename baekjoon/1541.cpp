//
// Created by 김소연 on 18/06/2019.
//

#include <cstdio>
#include <string>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

int main() {

    string arr;

    cin >> arr;
    int size = arr.size();

    string tmp;
    int ans=0;
    bool flag = false;
    for(int i=0;i<=size;i++){

        if(arr[i]=='-' || arr[i]=='+' || arr[i]=='\0'){
            if(flag){
                ans -= stoi(tmp); // 문자열 정수로 바꾸는 함수
            }else{
                ans += stoi(tmp);
            }

            if(arr[i]=='-'){
                flag = true;
            }
            tmp =""; //문자열 초기화
        }
        else{
            tmp+=arr[i];
        }
    }
    printf("%d\n",ans);

    return 0;
}

