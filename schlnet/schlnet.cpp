/*
ID:thtfive
LANG:C++
TASK:schlnet
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>
using namespace std;
int N;
int cnt=0;
int G[101][101];
int GT[101][101];
int order[101];
int sequence[101];

void DFS(int start,int *color)
{
    color[start]=1;
  //  cnt++;
    for(int i=1;i<=N;i++)
    {
        if(G[start][i]&&color[i]==0)
        {
            DFS(i,color);
        }
    }
    cnt++;
    sequence[cnt]=start;
    color[start]=2;
    order[start]=cnt;
}
void DFS2(int start,int *color,int *component,int com)
{
    color[start]=1;
    for(int i=1;i<=N;i++)
    {
        if(GT[start][i]&&color[i]==0)
        {
            DFS2(i,color,component,com);
        }
    }
    color[start]=2;
    component[start]=com;
}

void DFS()
{
    int color[N+1];
    memset(color,0,sizeof(color));
    for(int i=1;i<=N;i++)
    {
        if(color[i]==0)DFS(i,color);
    }
}


void solution2(int &result1,int &result2)
{
    result1=0;
    result2=0;
    int color[N+1];
    int component[N+1];
    int com=0;
    memset(color,0,sizeof(color));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            GT[i][j]=G[j][i];

    for(int i=N;i>=1;i--)
    {
        int node=sequence[i];
        if(color[node]==0)
        {
            com++;
            DFS2(node,color,component,com);
        }
    }
    int newG[com+1][com+1];
    memset(newG,0,sizeof(newG));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(G[i][j]==1&&component[i]!=component[j])
            {
                newG[component[i]][component[j]]=1;
            }
        }
    }
    int in[com+1];
    int out[com+1];
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=1;i<=com;i++)
    {
        for(int j=1;j<=com;j++)
        {
            if(newG[i][j]==1)
            {
                in[j]++;
                out[i]++;
            }
        }
    }
    int a=0,b=0;
    for(int i=1;i<=com;i++)
    {
        if(in[i]==0)a++;
        if(out[i]==0)b++;
    }
    result1=a;
    result2=a>b?a:b;
    if(com==1)result2=0;

}

int main()
{
    ifstream fin("schlnet.in");
    ofstream fout("schlnet.out");
    fin>>N;
    memset(G,0,sizeof(G));
    for(int i=1;i<=N;i++)
    {
        int tmp;
        fin>>tmp;
        while(tmp!=0)
        {
            G[i][tmp]=1;
            fin>>tmp;
        }
    }

    DFS();
    int result2;
    int result1;
    solution2(result1,result2);

//    for(int i=1;i<=N;i++)
//        cout<<"seq: "<<sequence[i]<<"\n";
    cout<<result1<<"\n"<<result2<<"\n";
    fout<<result1<<"\n"<<result2<<"\n";
    return 0;
}
