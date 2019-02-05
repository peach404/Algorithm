//
// Created by 김소연 on 05/02/2019.
//
#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    string stick;

    stack <char> s;
    cin >> stick;
    int ans=0;

    int ssize = stick.size();

    for(int i=0;i<ssize;i++){
        if (stick[i]=='('){
            s.push(stick[i]);
        }
        else {
            s.pop();
            int tmp = stick[i-1];
            if (tmp =='(') {
                ans+=s.size();
            }
            else{
                ans++;
            }
        }
    }
    printf("%d",ans);

    return 0;
}

