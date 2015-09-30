#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
#define maxn 10010
vector<int> G[maxn];
int W[maxn];
bool vis[maxn];

int DFS(int u)
{
    int d=G[u].size();
    int result=W[u];
    int tmp=0;
    for(int i=0;i<d;i++)
    {
        int v=G[u][v];
        if(!vis[v])
        {
            vis[v]=1;
            tmp=max(tmp,DFS(v));
            vis[v]=0;
        }
    }
    result+=tmp;
    return result;
}

int solution()
{
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    int result=DFS(1);
    return result;
}
int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>W[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    int result;
   //result=solution();

    cout<<result<<"\n";
    return 0;
}
