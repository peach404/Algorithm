#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

void PrintBracket(bool *state,int size)
{
    for(int i=1;i<size;i++)
    {
        if(state[i])
        {
            cout<<"(";
        }
        else
        {
            cout<<")";
        }
    }
    cout<<endl;
}
void Bracket(bool *state, int size,int start, int end)
{
    if(start==0&&end==0)	//베이스케이스
    {
        PrintBracket(state,size);
        return ;
    }
    if( start>0){				//괄호가 먼저 열리니깐 열림이 많은 것부터 뽑는다.
        state[size]=true;
        Bracket(state,size+1,start-1,end+1);
    }
    if(end>0){
        state[size]=false;
        Bracket(state,size+1,start,end-1);
    }
}

int main()
{
    int n;
    cin>>n;
    bool state[2*100];	//n은 최대 100개, 괄호를 열것인지 닫을것인지 넣는다.
    Bracket(state,1,n,0);
    return 0;
}