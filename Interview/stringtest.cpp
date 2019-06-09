//
// Created by 김소연 on 03/06/2019.
//
#include <iostream>
#include <cstdio>
#include <string.h>


using namespace std;

int main() {
    char str[1000];
    char str2[1000];
    string first[100];
    string second[100];


    scanf ("%[^\n]%*c", str);
    scanf("%[^\n]%*c", str2);

    char * tmp = strtok(str," "); //공백 기준으로 잘라서 스트링에 저장
    int a =0;
    while(tmp != NULL){
        first[a]= tmp;
        a++;
        tmp = strtok(NULL," ");
    }


    char * sub = strtok(str2," ");
    int b=0;
    while(sub != NULL){
        printf("%s\n",sub);
        second[b]= sub;
        b++;
        sub = strtok(NULL," ");
    }
    string ans[1000];
    bool flag;
    int k=0;
    for(int i=0;i<a;i++){
        flag = false;
        for(int j=0;j<b;j++){
            if(first[i]==second[j]) {
                flag = true;
                break;
            }
        }
        if(!flag){
            ans[k]=first[i];
            k++;
        }
    }



    return 0;
}