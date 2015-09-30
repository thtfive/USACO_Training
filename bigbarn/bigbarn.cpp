/*
ID:thtfive
LANG:C++
TASK:bigbrn
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>
using namespace std;
int record[1001][1001];

bool inRange(int i,int j,int N)
{
    return (i>=1&&i<=N&&j>=1&&j<=N);
}
int main()
{
    ifstream fin("bigbrn.in");
    ofstream fout("bigbrn.out");
    int N,treenum;
    fin>>N>>treenum;
    bool G[N+1][N+1];
    memset(G,true,sizeof(G));
    for(int i=0;i<treenum;i++)
    {
        int x,y;
        fin>>x>>y;
        G[x][y]=false;
    }
    int result=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(G[i][j])result=1;
        }
    }

    memset(record,0,sizeof(record));
    for(int i=N;i>=1;i--)
    {
        for(int j=N;j>=1;j--)
        {
            if(G[i][j])
            {
                int a=0,b=0,c=0;
                if(inRange(i,j+1,N))a=record[i][j+1];
                if(inRange(i+1,j,N))b=record[i+1][j];
                if(inRange(i+1,j+1,N))c=record[i+1][j+1];
                int minnum=min(a,b);
                minnum=min(minnum,c);
                record[i][j]=minnum+1;
            }
            else record[i][j]=0;
        }
    }

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            result=max(result,record[i][j]);


    cout<<result<<"\n";
    fout<<result<<"\n";
}
