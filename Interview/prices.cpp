//
// Created by 김소연 on 03/06/2019.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

#include<vector>
#include<algorithm>
using namespace std;
int maxval =0;
void go(int a,int b,int n,vector<int> prices){
    if(b>n)return ;

    if(prices[a]>prices[b])
        return;

    else if(prices[a]<prices[b]){
        int tmp =prices[b]-prices[a];
        if(tmp>maxval){
            maxval = tmp;
        }
        go(a,b+1,n,prices);

        go(a,b+1,n,prices);
    }


}


int solution(vector<int> prices)
{

    int size = prices.size();
    go(0,1,size,prices);

    return maxval;
}
int main() {
    vector <int> prices ={3,4,1,5,4};
    solution(prices);
    return 0;
}



//
//int a[1001];
//int b[1001];
//char str1[1000];
//char str2[1000];
//int main(){
//
//
//    scanf("%s",str1);
//    scanf("%s",str2);
//    bool answer =false;
//    int n = strlen(str1)-1;
//
//    if(str1 == str2){
//        answer = true;
//    }
//    int cnt = n;
//    while(cnt--){
//        char tmp = str1[n];
//        for(int j=n;j>0;j--){
//            str1[j]=str1[j-1];
//        }
//        str1[0]= tmp;
//        if(str1 == str2){
//            answer = true;
//            break;
//        }
//    }
//
//
//    return 0;
//}