/*
ID:thtfive
TASK:checker
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;

ifstream fin("checker.in");
ofstream fout("checker.out");
int N;
int result;
int resultlist[4][15];
bool used[15];
bool vis1[30];
bool vis2[30];
int order[15];
int G[15][15];
void input()
{
    fin>>N;
    result=0;
    memset(resultlist,0,sizeof(resultlist));
    memset(G,0,sizeof(G));
    memset(used,false,sizeof(used));
    memset(vis1,false,sizeof(vis1));
    memset(vis2,false,sizeof(vis2));
}

void checker(int num)
{
    for(int i=1;i<=N;i++)
    {
        if(!used[i]&&!vis1[num+i]&&!vis2[N+num-i])
        {
            used[i]=true;
            vis1[num+i]=true;
            vis2[N+num-i]=true;
            G[num][i]=1;
            if(num==N)
            {
                result++;
                if(result<4)
                {
                    for(int i=1;i<=N;i++)
                    {
                        for(int k=1;k<=N;k++)
                        {
                            if(G[i][k]==1)
                            {
                                resultlist[result][i]=k;
                            }
                        }
                    }
                }
            }
            else
            {
                checker(num+1);
            }
            G[num][i]=0;
            used[i]=false;
            vis1[num+i]=false;
            vis2[N+num-i]=false;
        }
    }
}

void solve()
{
    checker(1);
}
void output()
{
    for(int id=1;id<=3;id++)
    {
        for(int i=1;i<N;i++)
            cout<<resultlist[id][i]<<" ";
        cout<<resultlist[id][N]<<"\n";
    }
    cout<<result<<"\n";

    for(int id=1;id<=3;id++)
    {
        for(int i=1;i<N;i++)
            fout<<resultlist[id][i]<<" ";
        fout<<resultlist[id][N]<<"\n";
    }
    fout<<result<<"\n";
}
int main()
{
    input();
    solve();
    output();
    return 0;
}
