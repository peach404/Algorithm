//
// Created by 김소연 on 26/04/2019.
//

#include <vector>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;
bool cmp(string &a,string &b){
    if(a.size() == b.size()){
        return a <b;
    }
    else
        return a.size() <b.size();

}
int main() {
    int n;
    scanf("%d",&n);
    vector< string > v;
    string str;
    for(int i=0;i<n;i++){
        cin >> str;
        v.push_back(str);
    }

    vector <string>::iterator iter;
    vector <string>::iterator end_iter;

    sort(v.begin(),v.end(),cmp);

    end_iter = unique(v.begin(),v.end());

    for(iter=v.begin(); iter != end_iter;iter++){
        cout << *iter << endl;
    }
    return 0;
}