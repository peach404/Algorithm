//
// Created by 김소연 on 01/06/2019.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
string roman[1002]={
        "","I","II","III","IV","V","VI","VII","VIII","IX","X"};

string ans[1001];


int main(){

    roman[20]="XX";
    roman[30]="XXX";
    roman[40]="XL";
    roman[50]="L";
    roman[60]="LX";
    roman[70]="LXX";
    roman[80]="LXXX";
    roman[90]="XC";
    roman[100]="C";
    roman[200]="CC";
    roman[300]="CCC";
    roman[400]="CD";
    roman[500]="D";
    roman[600]="DC";
    roman[700]="DCC";
    roman[800]="DCCC";
    roman[900]="CM";
    roman[1000]="M";
    int n;

    scanf("%d",&n);
    int tmp=0;
    int arr[4];
    int num=0;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        int k=1;
        while (tmp != 0) {
            num = tmp % 10;
            arr[k]=num;
            tmp /= 10;
            k++;
        }
        string ret;
        if(k==5){
            ret+=roman[1000];
        }
        if(k==4){ //3자리수
            int a = arr[3];
            a*=100;
            ret+=roman[a];
            k--;
        }
        if(k==3){
            int a = arr[2];
            a*=10;
            ret+=roman[a];
            k--;
        }
        if(k==2) {
            int a = arr[1];
            ret += roman[a];
            k--;
        }

        ans[i]= ret;
    }
    for(int i=0;i<n;i++) {
        printf("%s\n", &ans[i]);
    }
    return 0;
}