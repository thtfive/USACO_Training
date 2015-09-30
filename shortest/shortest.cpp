#define L
#include <iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define maxN 100010

using namespace std;
int M,N,S,T;
vector<pair<int,int> >G[maxN];
int dist[maxN];

void shortestpath()
{
    bool done[N+1];
    memset(done,false,sizeof(done));
    for(int i=0;i<maxN;i++)dist[i]=-1;
    priority_queue <pair<int,int> >Q;
    dist[S]=0;
    Q.push(make_pair(0,S));
    while(!Q.empty())
    {
        pair<int,int>P=Q.top();
        Q.pop();
        int d=-1*P.first;
        int node=P.second;
        if(done[node])continue;
        done[node]=true;
        //cout<<"node:"<<node<<"->"<<dist[node]<<"\n";
        int Gnum=G[node].size();
        for(int i=0;i<Gnum;i++)
        {
            int n=G[node][i].first;
            int l=G[node][i].second;
            if(dist[n]==-1||dist[n]>d+l)
            {
                dist[n]=d+l;
                Q.push(make_pair(-1*(dist[n]),n));
            }
        }
    }
    return ;
}

int main()
{
    #ifdef L
    freopen("input.txt","r",stdin);
    #endif // L

    cin>>N>>M>>S>>T;
    for(int i=1;i<=M;i++)
    {
        int x,y,length;
        cin>>x>>y>>length;
        G[x].push_back(make_pair(y,length));
        G[y].push_back(make_pair(x,length));
    }
    shortestpath();
    cout<<dist[T]<<"\n";
    return 0;
}
