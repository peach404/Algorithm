////
//// Created by 김소연 on 07/03/2019.
////
//
//
//#include <cstdio>
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//#include <set>
//
//using namespace std;
//int num;
//int flag= true;
////참1 엘리스 거짓0 bob
//int a=0;
//int b=0;
//int who;
//int go(int tmp,int win,int back,int origin){
//
//
//    if(tmp > num) {
//
//        if(back<=num && back != origin){
//            return back;
//        }else {
//            win= win ==1 ? 2:1;
//            who=win;
//            return win;
//        }
//    }
//    if(flag) {
//        a = go(tmp * 2, 1, tmp, origin);
//        tmp = origin;
//        flag=false;
//    }
//    if(!flag){
//        b = go(tmp * 2+1, 1, tmp, origin);
//        origin=max(a,b);
//        flag=true;
//        win=win ==1 ? 2:1;
//        go(origin,win,origin,origin);
//
//    }
//
//
//
//}
//
//int main(){
//
//    int T;
//    scanf("%d",&T);
//
//    for(int tc=0;tc<T;tc++){
//        scanf("%d",&num);
//        int y=go(1,1,1,1);
//
//        who == 2 ? printf("#%d Alice\n",tc+1) : printf("#%d Bob\n",tc+1);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <iostream>

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        unsigned long long n;
        scanf("%llu", &n);
        int check = 0;
        unsigned long long turn = 1;
        unsigned long long mul = 1;
        while (turn < n)
        {
            if (!check)
                mul *= 4;
            turn += mul;
            check = !check;
        }
        printf("#%d %s\n", test_case,check?"Alice":"Bob");


    }
    return 0;
}

