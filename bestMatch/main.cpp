#define local
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxN 1010
vector<int> G[maxN];
int color[maxN];
int p[maxN],used[maxN];
int m,n;
void encolor_aux(int node,int c)
{
    color[node]=c;
    int s=G[node].size();
    for(int i=0;i<s;i++)
    {
        if(color[G[node][i]]==-1)
        encolor_aux(G[node][i],(c+1)%2);
    }
}
void encolor()
{
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            encolor_aux(i,0);
        }
    }
}
bool DFS(int node0)
{
    int s=G[node0].size();
    for(int i=0;i<s;i++)
    {
        int node1=G[node0][i];
        if(!used[node1])
        {
            used[node1]=1;
            if(p[node1]==-1||DFS(p[node1]))
            {
                p[node1]=node0;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    memset(G,0,sizeof(G));
    memset(color,-1,sizeof(color));
    memset(p,-1,sizeof(p));
    memset(used,0,sizeof(used));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    encolor();
    int result=0;
    for(int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if(color[i]==0&&DFS(i))
            result++;
    }
    cout<<result<<"\n";
    return 0;
}
