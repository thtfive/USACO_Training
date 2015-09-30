#define L
#include <iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define maxN 110
#define inf 10000001

using namespace std;
int M,N;
int G[maxN][maxN];
int dist[maxN][maxN];

int shortestpath()
{
    int minnum=inf;
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                //if(G[i][j]<inf&&G[k][j]<inf)
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    return minnum;
}

int main()
{
    #ifdef L
    freopen("input.txt","r",stdin);
    #endif // L

    cin>>N>>M;
    for(int i=0;i<=101;i++)
    {
        for(int j=0;j<=101;j++)
        {
            G[i][j]=inf;
        }
        G[i][i]=0;
    }
    for(int i=1;i<=M;i++)
    {
        int x,y,length;
        cin>>x>>y>>length;
        G[x][y]=min(G[x][y],length);
        G[y][x]=min(G[y][x],length);
    }
    shortestpath();
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
