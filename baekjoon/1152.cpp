//
// Created by 김소연 on 25/04/2019.
//

#include <string.h>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    string map;
    getline(cin,map);
    int ans=1;
    bool flag = false;
    int size=map.length();
    for(int i=0;i<size;i++){

        if(map[i]==' '){
            ans++;
        }

        if((i==size-1 && map[i]==' ') || (i==size-1 && map[i]=='\0'))
            ans--;
    }
    if(map[0]==' '){
        ans--;
    }
    if(size==0)ans--;
    printf("%d",ans);

    return 0;
}