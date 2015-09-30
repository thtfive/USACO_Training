/*
ID:thtfive
TASK:latin
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
ifstream fin("latin.in");
ofstream fout("latin.out");
int N;
long long result;
int G[9][9];
int placerecord[9];
int cnt[9];
int maxlength;

void input()
{
    fin>>N;
    result=0;
    memset(G,0,sizeof(G));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=N;i++)
        G[1][i]=i;
    for(int j=1;j<=N;j++)
        G[j][1]=j;
}

void searcher(int step)
{
    if(step==N*(N-1))
    {
        result++;
        cnt[maxlength]++;
        return;
    }

    int x=step/N+1;
    int y=step%N+1;
    if(x==3&&y==1)
    {
        for(int j=1;j<=N;j++)
            placerecord[j]=G[2][j];
        bool vis[N+1];
        memset(vis,false,sizeof(vis));

        maxlength=0;
        for(int j=1;j<=N;j++)
        {
            if(!vis[j])
            {
                vis[j]=true;
                int length=1;
                int idx=placerecord[j];
                while(!vis[idx])
                {
                    vis[idx]=true;
                    length++;
                    idx=placerecord[idx];
                }
                maxlength=max(maxlength,length);
            }
        }
        if(cnt[maxlength]>0)
        {
            result+=cnt[maxlength];
            return;
        }
    }

    if(G[x][y]!=0)step++;
    x=step/N+1;
    y=step%N+1;

    bool flag[N+1];
    memset(flag,false,sizeof(flag));
    for(int i=1;i<x;i++)
    {
        flag[G[i][y]]=true;
    }
    for(int j=1;j<y;j++)
    {
        flag[G[x][j]]=true;
    }
    for(int i=1;i<=N;i++)
    {
        if(!flag[i])
        {
            G[x][y]=i;
            searcher(step+1);
            G[x][y]=0;
        }
    }
    return;
}

void solve()
{
    searcher(N);
    for(int i=N-1;i>0;i--)
        result*=i;
    if(N==1)result=1;
}

void output()
{
    cout<<result<<"\n";
    fout<<result<<"\n";
}

int main()
{
    input();
    solve();
    output();
    return 0;
}
