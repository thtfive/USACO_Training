#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 20020
vector<int>G[maxn];
stack<pair<int,int> >S;
int dfs_clk;
int lowlink[maxn];
int number[maxn];
int biconnect[maxn];
int bc_cnt;
int bcno;

int DFS(int u,int fa)
{
    number[u]=lowlink[u]=++dfs_clk;
    int d=G[u].size();
    for(int i=0;i<d;i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        if(!number[v])
        {
            int lowv=DFS(v,u);
            lowlink[u]=min(lowlink[u],lowv);
            if(lowv>number[u])
            {
                G[u][i]=-1;
                int dd=G[v].size();
                for(int i=0;i<dd;i++)
                {
                    if(G[v][i]==u)
                    {
                        G[v][i]=-1;
                        break;
                    }
                }
            }
        }
        else if(number[v]<number[u])
        {
            lowlink[u]=min(lowlink[u],number[v]);
        }
    }
    return lowlink[u];
}
void firstsearch(int N)
{
    memset(number,0,sizeof(number));
    memset(lowlink,0,sizeof(lowlink));
    for(int i=1;i<=N;i++)
    {
        if(!number[i])
        {
            DFS(i,0);
        }
    }
}

void DFS2(int u)
{
    int d=G[u].size();
    number[u]=1;
    bcno=min(bcno,u);
    for(int i=0;i<d;i++)
    {
        int v=G[u][i];
        if(v==-1)continue;
        if(!number[v])
        {
            DFS2(v);
        }
    }
    biconnect[u]=bcno;
}

void secondsearch(int N)
{
    memset(number,0,sizeof(number));
    bc_cnt=0;
    for(int i=1;i<=N;i++)
    if(!number[i])
    {
        bcno=N+1;
        bc_cnt++;
        DFS2(i);
    }
}
int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    firstsearch(N);
    secondsearch(N);
    cout<<bc_cnt<<"\n";
    for(int i=1;i<=N;i++)
    {
        cout<<biconnect[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
