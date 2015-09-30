#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;
const int maxn=209;
int N;
map<string,int>ID_cache;
vector<int>G[maxn];
int d[maxn][2];
bool f[maxn][2];

void DFS(int u)
{
    int sz=G[u].size();
    int choosed=1;
    int unchoosed=0;
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        DFS(v);
        choosed+=d[v][0];
        if(f[v][0]==0)f[u][1]=0;///update if u is choosed

        if(d[v][0]==d[v][1])///update if us is not choosed
        {
            unchoosed+=d[v][1];
            f[u][0]=0;
        }
        if(d[v][0]<d[v][1])
        {
            unchoosed+=d[v][1];
            if(f[v][1]==0)f[u][0]=0;
        }
        if(d[v][0]>d[v][1])
        {
            unchoosed+=d[v][0];
            if(f[v][0]==0)f[u][0]=0;
        }
    }
    d[u][1]=choosed;
    d[u][0]=unchoosed;
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>N;
    while(N)
    {
        ID_cache.clear();
        memset(f,1,sizeof(f));
        for(int i=0;i<=N;i++)G[i].clear();
        string boss,employee;
        int id=0;
        cin>>boss;
        ID_cache[boss]=id++;
        for(int i=1;i<N;i++)
        {
            cin>>employee>>boss;
            if(ID_cache.count(boss)==0)
            {
                ID_cache[boss]=id++;
            }
            if(ID_cache.count(employee)==0)
            {
                ID_cache[employee]=id++;
            }
            int b=ID_cache[boss];
            int e=ID_cache[employee];
            G[b].push_back(e);
        }
        DFS(0);
        bool flag;
        int result;
        if(d[0][0]==d[0][1])
        {
            result=d[0][0];
            flag=0;
        }
        if(d[0][0]>d[0][1])
        {
            result=d[0][0];
            flag=f[0][0];
        }
        if(d[0][1]>d[0][0])
        {
            result=d[0][1];
            flag=f[0][1];
        }
        cout<<result;
        if(flag)cout<<" Yes\n";
        else cout<<" No\n";
        cin>>N;
    }
    return 0;
}
