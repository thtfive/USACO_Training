#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int subset[20];
int cover[1<<16];
int d[1<<16];
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    int kase=0;
    while (cin>>n,n)
    {
        int ALL=(1<<n)-1;
        int m,tmp;
        for(int i=0;i<n;i++)
        {
            subset[i]=(1<<i);
            cin>>m;
            for(int j=0;j<m;j++)
            {
                cin>>tmp;
                subset[i]|=(1<<tmp);
            }
        }
        int totalnum=(1<<n);
        for(int S=0;S<totalnum;S++)
        {
            cover[S]=0;
            for(int i=0;i<n;i++)
                if((1<<i)&S)
                    cover[S]|=subset[i];
        }
        for(int S=0;S<totalnum;S++)
        {
            d[S]=0;
            for(int S0=S;S0;S0=(S0-1)&S)
                if(cover[S0]==ALL)
                    d[S]=max(d[S],d[S^S0]+1);
        }
        cout<<"Case "<<(++kase)<<": "<<d[ALL]<<"\n";
    }
    return 0;
}
