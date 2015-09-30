#define LOCAL
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
int need[510];
int value[510];
int M,N;
int result;
int record[100010];
int searcher(int money)
{
    if(record[money]!=-1)return record[money];
    int maxvalue=0;
    for(int i=0;i<N;i++)
    {
        if(money-need[i]>=0&&searcher(money-need[i])+value[i]>maxvalue)
        {
            maxvalue=searcher(money-need[i])+value[i];
        }
    }
    return record[money]=maxvalue;
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    cin>>N>>M;
    result=0;
    for(int i=0;i<N;i++)
        cin>>need[i]>>value[i];
    memset(record,-1,sizeof(record));

    searcher(M);
    for(int i=0;i<=M;i++)
        result=max(result,record[i]);
    cout<<result<<"\n";
    return 0;
}
