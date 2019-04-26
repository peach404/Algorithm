//
// Created by 김소연 on 26/04/2019.
//

#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(string &a,string &b){
    return a<b;
}
int main() {

    char str[1001];
    scanf("%s", str);

    int size = strlen(str);
    vector<string> v;
    int j = size;
    v.push_back(str);
    for (int i = 1; i < size; i++) {

        string sub_string(str + i, str + j);
        v.push_back(sub_string);
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<size;i++){

        cout << v[i] <<endl;
    }


    return 0;
}