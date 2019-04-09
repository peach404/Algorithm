//
// Created by 김소연 on 09/04/2019.


#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;
int K,N;
int map[10][10];
char s[30];
set <int> sets;
/**
 *
 * 한 번 돌릴 때마다 숫자가 시계방향으로 한 칸씩 회전한다.
 * 각 변에는 동일한 개수의 숫자가 있고, 시계방향 순으로 높은 자리 숫자에  해당하며 하나의 수를 나타냄
 * 자물쇠의 비밀번호는 보물 상자에 적힌 숫자로 만들 수 있는 모든 수 중,
 * K번째로 큰 수를 10진 수로 만든 수이다.
 *
 * 1. 0,1,2,3 번 돌림 -> 돌리는 함수
 * 2. 돌린거 기반으로 숫자 저장(중복 제거)
 * 3. sort 함수로 정렬해서 K번째 수 구함
 * 4. 16진수 -> 10진수 변환해서 답구함
 *
 * */

int hextodec(int idx,int hex){
    int num=1;
    if(idx==1){
        return hex;
    }else {
        for (int i = 1; i <= idx; i++) {
            num = 16 * num;
        }
        return num*hex;
    }
}

void round(){
    int tmp = map[1][0];
    int newval=0;
    int size = N/4;

    newval = map[0][size];
    for(int i=size;i>=2;i--){
        map[0][i]=map[0][i-1];
    }
    map[0][1]=tmp;

    tmp = newval;
    newval = map[size][size+1];
    for(int i=size;i>=2;i--){
        map[i][size+1]=map[i-1][size+1];
    }
    map[1][size+1]=tmp;

    tmp = newval;
    newval = map[size+1][1];
    for(int i=1;i<=2;i++){
        map[size+1][i]=map[size+1][i+1];
    }
    map[size+1][size]=tmp;

    tmp = newval;
    for(int i=1;i<=2;i++){
        map[i][0]=map[i+1][0];
    }
    map[size][0]=tmp;

    return;
}

void makefun(){


    int tmp = N/4;
    int c=0;
    int num=0;
    int idx = tmp;
    for(int i=1;i<=tmp;i++){
        num+=hextodec(idx,map[0][i]);
        c++;
        idx--;
    }
   //    printf("%d\n",num);
    sets.insert(num);
    num=0;
    idx=tmp;
    for(int i=1;i<=tmp;i++){
        num+=hextodec(idx,map[i][tmp+1]);
        idx--;
        c++;
    }
  //   printf("%d\n",num);
    sets.insert(num);
    num=0;
    idx = tmp;
    for(int i=1;i<=tmp;i++){
        num+=hextodec(idx,map[tmp+1][i]);
        idx--;
        c++;

    }
     // printf("%d\n",num);
    sets.insert(num);
    num=0;
    idx=tmp;
    for(int i=1;i<=tmp;i++){
        num+=hextodec(idx,map[i][0]);
        idx--;
        c++;
    }
    sets.insert(num);


}


int main() {

    int T;
    scanf("%d",&T);


    for(int tc=0;tc<T;tc++){
        scanf("%d %d",&N,&K);

        for(int i=0;i<N;i++){
            cin >> s[i];

            if(s[i]<'A'){
                s[i]-='0';
            }
            else
                s[i]=s[i] -'A'+10;
        }

        int tmp = N/4;
        int c=0;
        int num=0;
        int idx = tmp;
        for(int i=1;i<=tmp;i++){
            map[0][i]=s[c];
            num+=hextodec(idx,s[c]);
            c++;
            idx--;
        }
    //    printf("%d\n",num);
        sets.insert(num);
        num=0;
        idx=tmp;
        for(int i=1;i<=tmp;i++){
            map[i][tmp+1]=s[c];
            num+=hextodec(idx,s[c]);
            idx--;
            c++;
        }
      //  printf("%d\n",num);
        sets.insert(num);
        num=0;
        idx = tmp;
        for(int i=1;i<=tmp;i++){

            map[tmp+1][i]=s[c];
            num+=hextodec(idx,s[c]);
            idx--;
            c++;

        }
     //   printf("%d\n",num);
        sets.insert(num);
        num=0;
        idx=tmp;
        for(int i=1;i<=tmp;i++){
            map[i][0]=s[c];
            num+=hextodec(idx,s[c]);
            idx--;
            c++;
        }
        sets.insert(num);
     //   printf("%d\n",num);

     for(int a=0;a<3;a++) {
         round();
         makefun();

     }
     int cnt=1;
     for(auto it=sets.begin();it != sets.end();it++){
         cout << *it << '\n';
//         if(cnt == K){
//             cout << *it << '\n';
//         }
         cnt++;
     }


    }
    return 0;
}

