#include<iostream>
#include<fstream>
#include<stack>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#include<queue>
///solve this problem using classic Tarjan algorithm
using namespace std;
#define maxn 20020
typedef pair<int,int>Edge;
vector<int>G[maxn];
bool iscutnode[maxn];
int number[maxn];
int lowpt[maxn];
int dfs_clk;
priority_queue <pair<int,int> > Q;
int DFS(int u,int fa)
{
    lowpt[u]=number[u]=++dfs_clk;
    int child=0;
    int d=G[u].size();
    for(int i=0;i<d;i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        if(!number[v])
        {
            child++;
            int lowv=DFS(v,u);
            if(lowv>=number[u])
            {
                iscutnode[u]=1;
            }
            if(lowv>number[u])
            {
                Q.push(make_pair(-min(u,v),-max(u,v)));
            }
            lowpt[u]=min(lowpt[u],lowv);
        }
        else if(number[v]<number[u])
        {
            lowpt[u]=min(lowpt[u],number[v]);
        }
    }
    if(child==1&&fa==-1)iscutnode[u]=0;
    return lowpt[u];
}
void solution(int N)
{
    memset(number,0,sizeof(number));
    memset(lowpt,0,sizeof(lowpt));
    dfs_clk=0;
    for(int i=1;i<=N;i++)
    {
        if(!number[i])DFS(i,-1);
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
        int from,to;
        cin>>from>>to;
        G[from].push_back(to);
        G[to].push_back(from);
    }
    solution(N);
    int counter=0;
    for(int i=1;i<=N;i++)
    {
        if(iscutnode[i])
        {
            cout<<i<<" ";
            counter++;
        }
    }
    if(!counter)cout<<"Null";
    cout<<"\n";
    while(!Q.empty())
    {
        cout<<-Q.top().first<<" "<<-Q.top().second<<"\n";
        Q.pop();
    }
    return 0;
}
