//
// Created by 김소연 on 26/04/2019.
//

#include <cstdio>
#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int size;



int main() {

    char str[1001];

    scanf("%s",str);
    size=strlen(str);

    set <string> check;


    for(int i=0;i<size;i++){
        for(int j=i+1;j<=size;j++){

            string sub_string(str+i,str+j);
            check.insert(sub_string);
        }
    }

    cout << check.size();
    return 0;

}