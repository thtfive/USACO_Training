#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=10009;
int d[maxn][3];
int N,exit_sign;
vector<int>G[maxn];
int father[maxn];
void build_tree(int u,int fa)
{
    int sz=G[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if(v!=fa)
        {
            father[v]=u;
            build_tree(v,u);
        }
    }
}

void DFS(int u)
{
    int sz=G[u].size();
    d[u][0]=1;
    d[u][1]=0;
    d[u][2]=0;
    int num=maxn;
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if(v==father[u])continue;
        DFS(v);
        d[u][0]+=min(d[v][0],d[v][1]);
        d[u][1]+=d[v][2];
    }
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if(v==father[u])continue;
        num=min(num,d[u][1]-d[v][2]+d[v][0]);
    }
    d[u][2]=num;
}

int main()
{
    freopen("input.txt","r",stdin);
    while(1)
    {
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            G[i].clear();
        }
        int first,second;
        for(int i=1;i<N;i++)
        {
            cin>>first>>second;
            G[first].push_back(second);
            G[second].push_back(first);
        }
        build_tree(1,0);
        DFS(1);
        int result=maxn;
        result=min(result,d[1][0]);
        result=min(result,d[1][2]);
        cout<<result<<"\n";
        cin>>exit_sign;
        if(exit_sign==-1)break;
    }
    return 0;
}
