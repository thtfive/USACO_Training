#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=101;
const int maxm=6;
const int inf=100000000;
int M,K;
int cost[maxm];
vector<int>stop[maxm];
struct Edge
{
    int from,to,cost;
    Edge(int f,int t,int c):from(f),to(t),cost(c){}
};
struct Dijkstra
{
    vector<Edge>edges;
    vector<int>G[5*maxn];
    int d[5*maxn];
    void init(int M,int K)
    {
        edges.clear();
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<100;j++)
                G[i*100+j].clear();
        }
        G[500].clear();
    }
    void AddEdge(int from,int to,int cost)
    {
        edges.push_back(Edge(from,to,cost));
        edges.push_back(Edge(to,from,cost));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int shortestway()
    {
        priority_queue <pair<int,int> >Q;
        bool done[100]{0};
        memset(d,-1,sizeof(d));
        Q.push(make_pair(0,500));
        while(!Q.empty())
        {
            auto P=Q.top();Q.pop();
            int u=P.second;
            d[u]=-P.first;
            done[u%100]=1;
            for(int &m:G[u])
            {
                Edge &e=edges[m];
                if(d[e.to]==-1||d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    Q.push(make_pair(-d[e.to],e.to));
                }
            }
            if(done[K])break;
        }
        int result=inf;
        for(int i=0;i<M;i++)
            if(d[i*100+K]!=-1)result=min(result,d[i*100+K]);
        return result;
    }
};
Dijkstra Object;
int main()
{
    freopen("input.txt","r",stdin);
    while(cin>>M>>K)
    {
        for(int i=0;i<M;i++)
            cin>>cost[i];

        Object.init(M,K);
        for(int i=0;i<M;i++)
        {
            int floor,last;
            Object.AddEdge(500,i*100,0);
            cin>>floor;
            last=floor;
            for(int j=0;j<M;j++)
                if(j!=i)Object.AddEdge(i*100+floor,j*100+floor,60);///从floor 层换乘的时间
            if(cin.get()=='\n')continue;
            while(cin>>floor)
            {
                Object.AddEdge(i*100+last,i*100+floor,(floor-last)*cost[i]);///到达上一个停靠点的时间
                last=floor;
                for(int j=0;j<M;j++)
                    if(j!=i)Object.AddEdge(i*100+floor,j*100+floor,60);
                if(cin.get()=='\n')break;
            }
        }
        int result=Object.shortestway();
        if(result!=inf)cout<<result<<endl;
        else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
