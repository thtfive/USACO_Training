/*
ID:thtfive
LANG:C++
TASK:stall4
*/
/// 利用匈牙利算法解决
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
#define max_M 201
int G[201][201];
int path[max_M];
bool used[max_M];
int N,M;

bool DFS(int node)
{
    for(int i=1;i<=M;i++)
    {
        if(G[node][i]==1&&!used[i])
        {
            used[i]=true;
            if(path[i]==-1||DFS(path[i]))
            {
                path[i]=node;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");
    fin>>N>>M;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            G[i][j]=0;
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
            G[v1][v2]=1;
        }
    }

    int result=0;
    memset(path,-1,sizeof(path));
    for(int i=1;i<=N;i++)
    {
        memset(used,false,sizeof(used));
        if(DFS(i))result++;
    }

    cout<<result<<endl;
    fout<<result<<"\n";
    return 0;
}
