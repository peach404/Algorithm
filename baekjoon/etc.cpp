//
// Created by 김소연 on 24/04/2019.
//

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(){

    char num[100000];
    string str;
    scanf("%s",&num);


    int tmp=0;
    int n=strlen(num);
    int val = n;
    for(int i=0;i<n;i++) {
        tmp = num[i] - '0';
        if (tmp == 1 && val == 1) {
            str += "일";
        } else {
            switch (tmp) {
                case 2:
                    str += "이";
                    break;
                case 3:
                    str += "삼";
                    break;
                case 4:
                    str += "사";
                    break;
                case 5:
                    str += "오";
                    break;
                case 6:
                    str += "육";
                    break;
                case 7:
                    str += "칠";
                    break;
                case 8:
                    str += "팔";
                    break;
                case 9:
                    str += "구";
                    break;

            }
        }
        if (tmp != 0) {
            switch (val) {
                case 2:
                    str += "십";
                    break;
                case 3:
                    str += "백";
                    break;
                case 4:
                    str += "천";
                    break;
                case 5:
                    str+="만";
                    break;
            }

        }
        val--;
    }
    cout << str;

    return 0;
}