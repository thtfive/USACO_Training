#include<iostream>
#include<fstream>
#include<queue>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define inf 1000000000
#define maxn 110
typedef pair<double,int>Node;
struct Edge
{
    int from,to;
    double cost;
    Edge(int f,int t,double c):from(f),to(t),cost(c){}
};

struct Dijkstra
{
    vector<int>G[maxn];
    vector<Edge>edges;
    double d[maxn];
    int s,t;
    void init(int nn)
    {
        for(int i=0;i<=nn;i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,double cost)
    {
        edges.push_back(Edge(from,to,cost));
        int m=edges.size();
        G[from].push_back(m-1);
    }
    double dijkstra(int source,int terminal)
    {
        s=source,t=terminal;
        int done[maxn];
        priority_queue <Node>Q;
        Node u;
        u.first=0.0;
        u.second=0;
        Q.push(u);
        for(int i=0;i<maxn;i++)d[i]=-1;
        memset(done,0,sizeof(done));
        while(!Q.empty())
        {
            auto P=Q.top();Q.pop();
            int u=P.second;
            if(done[u])continue;
            d[u]=-P.first;
            done[u]=1;
            if(done[t])break;
            int len=G[u].size();
            for(int i=0;i<len;i++)
            {
                Edge &e=edges[G[u][i]];
                if(d[e.to]==-1||d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    Node nodetmp;
                    nodetmp.first=-d[e.to];
                    nodetmp.second=e.to;
                    Q.push(nodetmp);
                }
            }
        }
        return d[t];
    }
};
Dijkstra Object;
int place[maxn][4];
void Dcaculate(int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double dist=0;
            for(int k=0;k<3;k++)
                dist+=pow(double(place[i][k]-place[j][k]),2);
            dist=sqrt(dist);
            dist-=double(place[i][3]);
            //printf("function:place[%d][%d] is %d\n",i,3,place[i][3]);
            dist-=double(place[j][3]);
            dist=max(0.0,dist);
            Object.AddEdge(i,j,dist);
            Object.AddEdge(j,i,dist);
        }
    }
}

int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int kase=0;
    int hole;
    while(cin>>hole,hole!=-1)
    {
        Object.init(hole+1);
        kase++;
        for(int i=1;i<=hole;i++)
        {
            cin>>place[i][0]>>place[i][1]>>place[i][2]>>place[i][3];
        }
        cin>>place[0][0]>>place[0][1]>>place[0][2];
        place[0][3]=0;
        cin>>place[hole+1][0]>>place[hole+1][1]>>place[hole+1][2];
        place[hole+1][3]=0;
        Dcaculate(hole+1);
        int len=Object.edges.size();
        double tmp=10*Object.dijkstra(0,hole+1);
        int result=round(tmp);
        printf("Cheese %d: Travel time = %d sec\n",kase,result);
    }

    return 0;
}
