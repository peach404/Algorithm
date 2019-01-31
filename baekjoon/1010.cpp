
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int test_case;
int n,m;
int d[101][101];

int main() {
    scanf("%d\n", &test_case);
    for(int tc=0;tc<test_case;tc++){
        int a,b;
        scanf("%d %d",&a,&b);

        if(a<b){
            swap(a,b);
        }
        for(int i=0;i<=a;i++){
            d[i][0]=1;

            for(int j=1;j<=i;j++){
                d[i][j] = d[i-1][j-1] + d[i-1][j];
            }
        }
        printf("%d\n",d[a][b]);

        memset(d,0,sizeof(d));
    }
    return 0;
}