#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
#define inf 2000000000
#define maxn 20002

int N,M;
int grass[maxn];
int newgrass[maxn];
vector<int>G[maxn];
vector<int>newG[maxn];
int dfs_clk;
int scc;
int sccno[maxn];
int number[maxn];
int low_pt[maxn];
stack<int>S;
void DFS(int u)
{
    dfs_clk++;
    number[u]=low_pt[u]=dfs_clk;
    S.push(u);
    int n=G[u].size();
    for(int i=0;i<n;i++)
    {
        int v=G[u][i];
        if(!number[v])
        {
            DFS(v);
            low_pt[u]=min(low_pt[u],low_pt[v]);
        }
        else if(!sccno[v])
        {
            low_pt[u]=min(low_pt[u],number[v]);
        }
    }
    if(low_pt[u]==number[u])
    {
        scc++;
        while(1)
        {
            int x=S.top();S.pop();
            sccno[x]=scc;
            if(x==u)break;
        }
    }
}

void findscc()
{
    memset(sccno,0,sizeof(sccno));
    memset(number,0,sizeof(number));
    memset(low_pt,0,sizeof(low_pt));
    scc=0;
    dfs_clk=0;
    for(int i=1;i<=N;i++)
    {
        if(!sccno[i])
        {
            DFS(i);
        }
    }
}
void createnewnode()
{
    memset(newgrass,0,sizeof(newgrass));
    for(int i=1;i<=N;i++)
    {
        newgrass[sccno[i]]+=grass[i];
        int n=G[i].size();
        for(int j=0;j<n;j++)
        {
            int x=sccno[i];
            int y=sccno[G[i][j]];
            if(x!=y)
            {
                newG[x].push_back(y);
            }
        }
    }
}
int longestway()
{
    queue<int>Q;
    int d[maxn];
    memset(d,0,sizeof(d));
    int maxgrass=0;
    Q.push(sccno[1]);
    d[sccno[1]]=newgrass[sccno[1]];
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        maxgrass=max(maxgrass,d[u]);
        int n=newG[u].size();
        for(int i=0;i<n;i++)
        {
            int v=newG[u][i];
            d[v]=max(d[v],d[u]+newgrass[v]);
           // d[v]=d[u]+newgrass[v];
            Q.push(v);
        }
    }
    return maxgrass;
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        cin>>grass[i];
    for(int i=1;i<=M;i++)
    {
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
    }
    findscc();
    createnewnode();
    int result=longestway();
    cout<<result<<endl;
    return 0;
}
