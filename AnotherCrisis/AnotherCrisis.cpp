#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=100009;
int d[maxn];
int N,T;
vector<int>G[maxn];

int DFS(int boss)
{
    int sz=G[boss].size();
    vector<int>arr(sz);
    for(int i=0;i<sz;i++)
        arr[i]=DFS(G[boss][i]);
    sort(arr.begin(),arr.end());
    int num=(int)ceil(sz*T/100.0);
    d[boss]=0;
    for(int i=0;i<num;i++)
        d[boss]+=arr[i];
    if(sz==0)d[boss]=1;
    return d[boss];
}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>N>>T;
    while(N||T)
    {
        for(int i=0;i<=N;i++)
            G[i].clear();
        int boss;
        for(int i=1;i<=N;i++)
        {
            cin>>boss;
            G[boss].push_back(i);
        }
        DFS(0);
        cout<<d[0]<<"\n";
        cin>>N>>T;
    }
    return 0;
}
