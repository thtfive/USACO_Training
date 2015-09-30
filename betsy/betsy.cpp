/*
ID:thtfive
LANG:C++
TASK:betsy
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>

using namespace std;
///
///
///
ifstream fin("betsy.in");
ofstream fout("betsy.out");
int N;
int result;
int G[9][9];
void input()
{
    memset(G,0,sizeof(G));
    fin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            G[i][j]=1;
        }
    }
}

void direction(int &xtmp,int &ytmp,int way)
{
    switch(way)
    {
        case 1:ytmp++;break;
        case 2:xtmp++;break;
        case 3:ytmp--;break;
        case 4:xtmp--;break;
    }
}

bool inRange(int x,int y)
{
    return (x>0)&&(x<=N)&&(y>0)&&(y<=N);
}


bool feasible(int xplace,int yplace,int step)
{
    if(xplace==N&&yplace==1)return true;
    if(G[xplace][yplace+1]==1&&G[xplace][yplace-1]==1&&G[xplace+1][yplace]!=1&&G[xplace-1][yplace]!=1)
    {
        return false;
    }
    if(G[xplace][yplace+1]!=1&&G[xplace][yplace-1]!=1&&G[xplace+1][yplace]==1&&G[xplace-1][yplace]==1)
    {
        return false;
    }

    return true;
}

int nearbynum(int xplace,int yplace)
{
    int num=0;
    if(G[xplace][yplace+1]==1)num++;
    if(G[xplace+1][yplace]==1)num++;
    if(G[xplace][yplace-1]==1)num++;
    if(G[xplace-1][yplace]==1)num++;
    return num;
}

void searcher(int xplace,int yplace,int step)
{
  //  cout<<"xplace:"<<xplace<<" yplace:"<<yplace<<"\n";
    if(xplace==N&&yplace==1)
    {
        if(step==N*N)
        {
            result++;
        }
        return;
    }

    for(int d=1;d<=4;d++)
    {
        int xtmp=xplace,ytmp=yplace;
        direction(xtmp,ytmp,d);
        if(inRange(xtmp,ytmp)&&G[xtmp][ytmp]==1&&(xtmp!=N||ytmp!=1))
        {
            int number=nearbynum(xtmp,ytmp);
            if(number==1)
            {
                G[xtmp][ytmp]=2;
                searcher(xtmp,ytmp,step+1);
                G[xtmp][ytmp]=1;
                return;
            }
        }
    }

    for(int d=1;d<=4;d++)
    {
        int xtmp=xplace,ytmp=yplace;
        direction(xtmp,ytmp,d);
        if(inRange(xtmp,ytmp)&&G[xtmp][ytmp]==1&&feasible(xtmp,ytmp,step))
        {
            G[xtmp][ytmp]=2;
            searcher(xtmp,ytmp,step+1);
            G[xtmp][ytmp]=1;
        }
    }
}

void solve()
{
    G[1][1]=2;
    searcher(1,1,1);
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
