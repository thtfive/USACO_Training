/*
ID:thtfive
LANG:C++
TASK:stall4
*/
///使用网络流法来解决此问题 二分图最大匹配问题
#include<fstream>
#include<iostream>
#include<queue>
using namespace std;
#define max_N 402
int G[max_N][max_N];
int Gf[max_N][max_N];
int Adj[max_N][max_N];
int flow[max_N][max_N];
int N,M;
int numV;
int path[max_N];

void BFS()
{
    bool flag[numV+2];
    for (int i=0;i<=numV+1;i++)
    {
        flag[i]=false;
        path[i]=-1;
    }
    queue <int>que;
    que.push(0);
    flag[0]=true;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(int i=1;i<=Adj[node][0];i++)
        {
            int v=Adj[node][i];
            if(!flag[v]&&Gf[node][v]>0)
            {
                flag[v]=true;
                path[v]=node;
                que.push(v);
            }
        }
    }
}

int main()
{
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");
    fin>>N>>M;
    numV=N+M;
    for(int i=0;i<=numV+1;i++)
    {
        for(int j=0;j<=numV+1;j++)
        {
            G[i][j]=0;
            Gf[i][j]=0;
            flow[i][j]=0;
        }
    }

    int num;
    for (int v1=1;v1<=N;v1++)
    {
        fin>>num;
        for (int j=1;j<=num;j++)
        {
            int v2;
            fin>>v2;
            v2+=N;
            G[v1][v2]=1;
            Gf[v1][v2]=1;
            Adj[v1][++Adj[v1][0]]=v2;
            Adj[v2][++Adj[v2][0]]=v1;
        }
    }

    for(int v1=1;v1<=N;v1++)
    {
        G[0][v1]=1;
        Gf[0][v1]=1;
        Adj[0][++Adj[0][0]]=v1;
        Adj[v1][++Adj[v1][0]]=0;
    }
    for(int v2=N+1;v2<=N+M;v2++)
    {
        G[v2][numV+1]=1;
        Gf[v2][numV+1]=1;
        Adj[v2][++Adj[v2][0]]=numV+1;
        Adj[numV+1][++Adj[numV+1][0]]=v2;
    }

    BFS();
    while(true)
    {
        BFS();
        if(path[numV+1]==-1)break;
        int start;
        int finish=numV+1;
        start=path[finish];
        while(start!=-1)
        {
            if(G[start][finish]>0)
            {
                flow[start][finish]=1;
                Gf[start][finish]=0;
                Gf[finish][start]=1;
            }
            else
            {
                flow[finish][start]=0;
                Gf[start][finish]=0;
                Gf[finish][start]=1;
            }
            finish=start;
            start=path[finish];
        }
    }

    int result=0;
    for(int v1=1;v1<=N;v1++)
        result+=flow[0][v1];
    cout<<result<<"\n";
    fout<<result<<"\n";
    return 0;
}
