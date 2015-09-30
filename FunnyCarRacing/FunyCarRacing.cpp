#include<iostream>
#include<fstream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,s,t;
struct Edge
{
    int from,to,open,close,cost;
    Edge(int fr,int t,int op,int cl,int co):from(fr),to(t),open(op),close(cl),cost(co){}
};
int main()
{
    int kase=0;
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    while(cin>>n>>m>>s>>t)
    {
        kase++;
        vector<int>G[n+1];
        vector<Edge>edges;
        for(int i=1;i<=m;i++)
        {
            int from,to,open,close,cost;
            cin>>from>>to>>open>>close>>cost;
            edges.push_back(Edge(from,to,open,close,cost));
            G[from].push_back(edges.size()-1);
        }
        int d[n+2];
        memset(d,-1,sizeof(d));
        priority_queue<pair<int,int> >Q;
        bool inq[n+2];
        memset(inq,0,sizeof(inq));
        Q.push(make_pair(0,s));
        d[s]=0;
        while(!Q.empty())
        {
            pair<int,int>P;
            P=Q.top();Q.pop();
            int u=P.second;
            if(inq[u])continue;
            int len=G[u].size();
            int du=-P.first;
            inq[u]=1;
            d[u]=du;
            for(int i=0;i<len;i++)
            {
                int m=G[u][i];
                Edge &e=edges[m];
                int arrive;
                int st=du%(e.close+e.open);
                if(st<=e.open&&e.open-st>=e.cost)
                    arrive=du+e.cost;
                else
                    arrive=du+e.close+e.open-st+e.cost;
                if(e.cost<=e.open&&(d[e.to]==-1||d[e.to]>arrive))
                {
                   // cout<<e.to<<" arrive at :"<<arrive<<"\n";
                    d[e.to]=arrive;
                    Q.push(make_pair(-arrive,e.to));
                }
            }
            if(inq[t])break;
        }
        cout<<"Case "<<kase<<": "<<d[t]<<"\n";
    }
    return 0;
}
