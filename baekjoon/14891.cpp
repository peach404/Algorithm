//
// Created by 김소연 on 25/03/2019.
//


#include <queue>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int wheel1[3][3]={0, };
int wheel2[3][3]={0, };
int wheel3[3][3]={0, };
int wheel4[3][3]={0, };
int kmap[101][2]={0, };

int clocky[8]={0,0,1,2,2,2,1,0};
int clockx[8]={1,2,2,2,1,0,0,0};
void round(int arr[4]){
    for(int i=0;i<4;i++) {
        int backup=0;
        if (arr[i] == 1) {
           if(i==0){
               backup= wheel1[0][0];
               wheel1[0][0]=wheel1[1][0];
               wheel1[1][0]=wheel1[2][0];
               wheel1[2][0]=wheel1[2][1];
               wheel1[2][1]=wheel1[2][2];
               wheel1[2][2]=wheel1[1][2];
               wheel1[1][2]=wheel1[0][2];
               wheel1[0][2]=wheel1[0][1];
               wheel1[0][1]=backup;
           }else if(i==1){
               backup= wheel2[0][0];
               wheel2[0][0]=wheel2[1][0];
               wheel2[1][0]=wheel2[2][0];
               wheel2[2][0]=wheel2[2][1];
               wheel2[2][1]=wheel2[2][2];
               wheel2[2][2]=wheel2[1][2];
               wheel2[1][2]=wheel2[0][2];
               wheel2[0][2]=wheel2[0][1];
               wheel2[0][1]=backup;

           }else if(i==2){
               backup= wheel3[0][0];
               wheel3[0][0]=wheel3[1][0];
               wheel3[1][0]=wheel3[2][0];
               wheel3[2][0]=wheel3[2][1];
               wheel3[2][1]=wheel3[2][2];
               wheel3[2][2]=wheel3[1][2];
               wheel3[1][2]=wheel3[0][2];
               wheel3[0][2]=wheel3[0][1];
               wheel3[0][1]=backup;
           }else if(i==3){
               backup= wheel4[0][0];
               wheel4[0][0]=wheel4[1][0];
               wheel4[1][0]=wheel4[2][0];
               wheel4[2][0]=wheel4[2][1];
               wheel4[2][1]=wheel4[2][2];
               wheel4[2][2]=wheel4[1][2];
               wheel4[1][2]=wheel4[0][2];
               wheel4[0][2]=wheel4[0][1];
               wheel4[0][1]=backup;
           }
        }

        /////////////////////////////////////////
        else if (arr[i] == -1) {
            if(i==0){
                backup= wheel1[0][1];
                wheel1[0][1]=wheel1[0][2];
                wheel1[0][2]=wheel1[1][2];
                wheel1[1][2]=wheel1[2][2];
                wheel1[2][2]=wheel1[2][1];
                wheel1[2][1]=wheel1[2][0];
                wheel1[2][0]=wheel1[1][0];
                wheel1[1][0]=wheel1[0][0];
                wheel1[0][0]=backup;
            }else if(i==1){
                backup= wheel2[0][1];
                wheel2[0][1]=wheel2[0][2];
                wheel2[0][2]=wheel2[1][2];
                wheel2[1][2]=wheel2[2][2];
                wheel2[2][2]=wheel2[2][1];
                wheel2[2][1]=wheel2[2][0];
                wheel2[2][0]=wheel2[1][0];
                wheel2[1][0]=wheel2[0][0];
                wheel2[0][0]=backup;

            }else if(i==2){
                backup= wheel3[0][1];
                wheel3[0][1]=wheel3[0][2];
                wheel3[0][2]=wheel3[1][2];
                wheel3[1][2]=wheel3[2][2];
                wheel3[2][2]=wheel3[2][1];
                wheel3[2][1]=wheel3[2][0];
                wheel3[2][0]=wheel3[1][0];
                wheel3[1][0]=wheel3[0][0];
                wheel3[0][0]=backup;
            }else if(i==3){
                backup= wheel4[0][1];
                wheel4[0][1]=wheel4[0][2];
                wheel4[0][2]=wheel4[1][2];
                wheel4[1][2]=wheel4[2][2];
                wheel4[2][2]=wheel4[2][1];
                wheel4[2][1]=wheel4[2][0];
                wheel4[2][0]=wheel4[1][0];
                wheel4[1][0]=wheel4[0][0];
                wheel4[0][0]=backup;
            }

        }
    }
    return;

}

int main() {

    int k=0;

    for(int a=0;a<4;a++) {
        for (int i = 0; i < 8; i++) {
            int ny = clocky[i];
            int nx = clockx[i];

            if (a == 0)
                scanf("%1d", &wheel1[ny][nx]);
            else if (a == 1)
                scanf("%1d", &wheel2[ny][nx]);
            else if (a == 2)
                scanf("%1d", &wheel3[ny][nx]);
            else
                scanf("%1d", &wheel4[ny][nx]);

        }
    }
    scanf("%d",&k);

    for(int i=0;i<k;i++){
        scanf("%d %d",&kmap[i][0],&kmap[i][1]);
    }

    int idx=0;
    while(k--){

        if(kmap[idx][0]==1){
            int check[4]={0, };
            check[0]=kmap[idx][1];

            if(wheel1[1][2] != wheel2[1][0]){
                if(check[0]==1)
                    check[1]= -1;
                else check[1] =1;

                if(wheel2[1][2] != wheel3[1][0]){
                    if(check[1]==1)
                        check[2]= -1;
                    else check[2] =1;
                    if(wheel3[1][2] != wheel4[1][0]){
                        if(check[2]==1)
                            check[3]= -1;
                        else check[3] =1;
                    }
                }
            }

            round(check);
            idx++;

        }else if(kmap[idx][0]==2){
            int check[4]={0, };
            check[1]=kmap[idx][1];

            if(wheel1[1][2] != wheel2[1][0]){
                if(check[1]==1)
                    check[0]= -1;
                else check[0] =1;
            }
            if(wheel2[1][2] != wheel3[1][0]){
                if(check[1]==1)
                    check[2]= -1;
                else check[2] =1;

                if(wheel3[1][2] != wheel4[1][0]){
                    if(check[2]==1)
                        check[3]= -1;
                    else check[3] =1;
                }
            }

            round(check);
            idx++;

        }else if(kmap[idx][0]==3){
            int check[4]={0, };
            check[2]=kmap[idx][1];


            if(wheel2[1][2] != wheel3[1][0]){
                if(check[2]==1)
                    check[1]= -1;
                else check[1] =1;

                if(wheel1[1][2] != wheel2[1][0]){
                    if(check[1]==1)
                        check[0]= -1;
                    else check[0] =1;
                }
            }
            if(wheel3[1][2] != wheel4[1][0]){
                if(check[2]==1)
                    check[3]= -1;
                else check[3] =1;
            }
            round(check);
            idx++;

        }else{

            int check[4]={0, };
            check[3]=kmap[idx][1];

            if(wheel3[1][2] != wheel4[1][0]) {
                if (check[3] == 1)
                    check[2] = -1;
                else check[2] = 1;

                if (wheel2[1][2] != wheel3[1][0]) {
                    if (check[2] == 1)
                        check[1] = -1;
                    else check[1] = 1;

                    if(wheel1[1][2] != wheel2[1][0]){
                        if(check[1]==1)
                            check[0]= -1;
                        else check[0] =1;
                    }

                }
            }
            round(check);
            idx++;

        }
    }


    int ans=0;

    if(wheel1[0][1]==1) ans+=1;
    if(wheel2[0][1]==1) ans+=2;
    if(wheel3[0][1]==1) ans+=4;
    if(wheel4[0][1]==1) ans+=8;

    printf("%d\n",ans);

    return 0;
}