#define LOCAL

#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;

int need[510],value[510];
bool flag[100010][510];
int M;
int N;
int result;
int record[100010];

void searcher()
{
    for(int money=0;money<=M;money++)
    {
        int maxvalue=0;
        int place=-1;
        for(int i=0;i<N;i++)
        {
            if(money-need[i]>=0&&!flag[money-need[i]][i]&&record[money-need[i]]+value[i]>maxvalue)
            {
                maxvalue=record[money-need[i]]+value[i];
                place=i;
            }
        }
        if(place!=-1)
        {
            for(int i=0;i<N;i++)
            {
                flag[money][i]=flag[money-need[place]][i];
            }
            flag[money][place]=true;
        }
        record[money]=maxvalue;
        result=max(result,maxvalue);
    }
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #endif

    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>need[i]>>value[i];
    }
    result=0;
    memset(record,0,sizeof(record));
    memset(flag,false,sizeof(flag));
    searcher();
    cout<<result<<"\n";
    return 0;
}
