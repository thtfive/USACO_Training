/*
ID:thtfive
LANG:C++
TASK:ditch
*/
#include<iostream>
#include<fstream>
#include<queue>
#define max_M 200
using namespace std;
bool flag[401];
int numV;
int path[2*max_M+1];
int distant[401];
int G[2*max_M+1][2*max_M+1];
int Adj[2*max_M+1][2*max_M+1];
int Gf[2*max_M+1][2*max_M+1];
int flow[2*max_M+1][2*max_M+1];

void BFS()
{
    for (int i=0;i<=numV;i++)
    {
        flag[i]=false;
        path[i]=-1;
    }
    queue <int>que;
    que.push(1);
    flag[1]=true;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(int i=1;i<=Adj[node][0];i++)
        {
            int idx=Adj[node][i];
            if(!flag[idx]&&Gf[node][idx]>0)
            {
                path[idx]=node;
                flag[idx]=true;
                que.push(idx);
            }
        }
    }
}

int main()
{
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");
    int N,M;
    fin>>N>>M;
    numV=M;

    for (int i=0;i<=2*M;i++)
        for (int j=0;j<=2*M;j++)
        {
            G[i][j]=0;
            flow[i][j]=0;
            Adj[i][j]=0;
        }
    for(int i=1;i<=N;i++)
    {
        int start;
        int finish;
        int weight;
        fin>>start>>finish>>weight;
        if(G[finish][start]==0)
        {
            G[start][finish]+=weight;

            Adj[start][++Adj[start][0]]=finish;
            Adj[finish][++Adj[finish][0]]=start;
        }
        else
        {
            if(G[start][numV]==0)numV++;
            G[start][numV]+=weight;
            G[numV][finish]+=weight;

            Adj[start][++Adj[start][0]]=numV;
            Adj[numV][++Adj[numV][0]]=start;
            Adj[numV][++Adj[numV][0]]=finish;
            Adj[finish][++Adj[finish][0]]=numV;
        }
    }

    for(int i=1;i<=numV;i++)
    {
        for(int j=1;j<=numV;j++)
        {
            Gf[i][j]=G[i][j];
        }
    }

    while(1)
    {
        BFS();
        if (path[M]==-1)break;
        int start;
        int finish=M;
        int minimum=999999999;
        while(path[finish]!=-1)
        {
            start=path[finish];
            minimum=minimum<Gf[start][finish]?minimum:Gf[start][finish];
            finish=start;
        }
        finish=M;
        while(path[finish]!=-1)
        {
            start=path[finish];
            if(G[start][finish]>0)
            {
                flow[start][finish]+=minimum;
                Gf[start][finish]=G[start][finish]-flow[start][finish];
                Gf[finish][start]=flow[start][finish];
            }
            else
            {
                flow[finish][start]-=minimum;
                Gf[start][finish]=flow[start][finish];
                Gf[finish][start]=G[start][finish]-flow[start][finish];
            }
            finish=start;
        }
    }
    int result=0;
    for (int i=2;i<=numV;i++)
        result+=flow[1][i];
    fout<<result<<"\n";
    cout<<result<<"\n";

//    cout<<"\n";
//    cout<<numV<<"\n";
//    for(int i=1;i<=numV;i++)
//    {
//        for(int j=0;j<=Adj[i][0];j++)
//            cout<<Adj[i][j]<<" ";
//        cout<<"\n";
//    }




    return 0;
}
