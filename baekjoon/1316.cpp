//
// Created by 김소연 on 25/04/2019.
//

#include <cstdio>
#include <string.h>

using namespace std;
char arr[200];
bool check[200];

int main(){
    int ans=0;
    int n=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",arr);
        bool flag = true;
        int size = strlen(arr);
        char tmp;
        for(int a=0;a<size;a++){
            if(!check[arr[a]-'a']){
                check[arr[a]-'a'] = true;
                tmp=arr[a];
            }else if(arr[a]==tmp){
                continue;
            }else{
                flag=false;
                continue;
            }
        }


        if(flag) ans++;
        memset(check,false,sizeof(check));

    }

    printf("%d",ans);

    return 0;
}