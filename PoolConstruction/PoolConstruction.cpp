#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define inf 1000000000
#define maxn 2510
struct Edge
{
    int from,to,cap,flow;
    Edge(int fr,int t,int c,int f):from(fr),to(t),cap(c),flow(f){}
};

struct Model
{
    vector <int> G[maxn];
    vector <Edge> edges;
    int n,m,s,t;
    int p[maxn];
    int a[maxn];
    int d[maxn];
    int cur[maxn];

    void AddEdge(int from,int to,int cap,int flow)
    {
        edges.push_back(Edge(from,to,cap,flow));
        edges.push_back(Edge(to,from,0,flow));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS(int s,int t)
    {
        memset(d,-1,sizeof(d));
        queue<int>Q;
        Q.push(s);
        d[s]=0;
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            for(unsigned i=0;i<G[u].size();i++)
            {
                Edge &e=edges[G[u][i]];
                if(d[e.to]==-1&&e.cap-e.flow>0)
                {
                    d[e.to]=d[u]+1;
                    Q.push(e.to);
                }
            }
        }
        return d[t]!=-1;
    }

    int DFS(int x,int a)
    {
        if(x==t||a==0)return a;
        int flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            Edge &e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int dinic_maxflow(int s,int t)
    {
        this->s=s;
        this->t=t;
        int flow=0;
        while(BFS(s,t))
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,inf);
        }
        return flow;
    }

    int maxflow(int s,int t)
    {
        int flow=0;
        while(1)
        {
            memset(a,0,sizeof(a));
            a[s]=inf;
            queue <int> Q;
            Q.push(s);
            while(!Q.empty())
            {
                int u=Q.front();Q.pop();
                int len=G[u].size();
                for(int i=0;i<len;i++)
                {
                    Edge &e=edges[G[u][i]];
                    if(!a[e.to]&&e.flow<e.cap)
                    {
                        a[e.to]=min(a[u],e.cap-e.flow);
                        p[e.to]=G[u][i];
                        Q.push(e.to);
                    }
                }
                if(a[t])break;
            }
            if(!a[t])break;
            flow+=a[t];
            for(int u=t;u!=s;u=edges[p[u]].from)
            {
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
        }
        return flow;
    }
};

int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int T;
    cin>>T;
    while(T--)
    {
        int Width,Height,dig_cost,fill_cost,build_cost;
        Model Object;
        int total_cost=0;
        cin>>Width>>Height;
        cin>>dig_cost>>fill_cost>>build_cost;
        string strs[Height+1];
        for(int i=0;i<Height;i++)
            cin>>strs[i];
        for(int j=0;j<Width;j++)
        {
            if(strs[0][j]=='.')
            {
                strs[0][j]='#';
                total_cost+=fill_cost;
            }
            if(strs[Height-1][j]=='.')
            {
                strs[Height-1][j]='#';
                total_cost+=fill_cost;
            }
        }
        for(int i=1;i<Height-1;i++)
        {
            if(strs[i][0]=='.')
            {
                strs[i][0]='#';
                total_cost+=fill_cost;
            }
            if(strs[i][Width-1]=='.')
            {
                strs[i][Width-1]='#';
                total_cost+=fill_cost;
            }
        }
        int source=Width*Height;
        int terminal=source+1;
        for(int i=0;i<Height;i++)
        {
            for(int j=0;j<Width;j++)
            {
                if(i==0||i==Height-1||j==0||j==Width-1)
                {
                    Object.AddEdge(source,i*Width+j,inf,0);
                    Object.AddEdge(i*Width+j,terminal,0,0);
                }
                else
                {
                    if(strs[i][j]=='#')
                    {
                        Object.AddEdge(source,i*Width+j,dig_cost,0);
                    }
                    else
                    {
                        Object.AddEdge(i*Width+j,terminal,fill_cost,0);
                    }
                }
            }
        }
        for(int i=0;i<Height;i++)
        {
            for(int j=0;j<Width;j++)
            {
                int u=i*Width+j;
                if(j-1>=0)
                {
                    Object.AddEdge(u,i*Width+j-1,build_cost,0);
                }
                if(j+1<Width)
                {
                    Object.AddEdge(u,i*Width+j+1,build_cost,0);
                }
                if(i-1>=0)
                {
                    Object.AddEdge(u,(i-1)*Width+j,build_cost,0);
                }
                if(i+1<Height)
                {
                    Object.AddEdge(u,(i+1)*Width+j,build_cost,0);
                }
            }
        }
        //cout<<total_cost<<"before\n";
        total_cost+=Object.maxflow(source,terminal);
        cout<<total_cost<<"\n";
    }
    return 0;
}
