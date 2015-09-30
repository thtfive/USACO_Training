/*
ID:thtfive
LANG:C++
TASK:telecow
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
/*
    该题首先将结点v分为两个结点v,v+100，赋予权值为1
    通过这种方式把求最小割点集的问题转换成求最小割边集的问题
    利用最大流算法求出了最小割边后，储存所有使得割边满流的结点
    再利用对结点从小到大排序然后依次分别将结点的最大流值置为0，如果网络流下降了1
    则说明该结点属于这个按字典顺序排列最小的割集
    如果没有下降，则不将该结点加入按字典顺序排列最小的割集中
    时间复杂度分析:最大的运算量在于max_flow()中
    每次最多可能运行O(N)次BFS
    在寻找字典序列最小的割集可能运行O(N)次max_flow()
    BFS()的时间复杂度为O(N)
    因此总时间复杂度O(N^3)//???
*/
ifstream fin("telecow.in");
ofstream fout("telecow.out");
int N,M,c1,c2;
int pathnum;
int pre[201];
int G[201][201];
int Gf[201][201];
int flow[201][201];
int result1;
int result2[101];
void init()
{
    memset(G,0,sizeof(G));
    memset(Gf,0,sizeof(Gf));
    memset(flow,0,sizeof(flow));
    memset(result2,0,sizeof(result2));
    result1=0;
    pathnum=0;
    fin>>N>>M>>c1>>c2;
    for(int i=1;i<=M;i++)
    {
        int tmp1,tmp2;
        fin>>tmp1>>tmp2;
        G[tmp1+100][tmp2]=1000;
        G[tmp2+100][tmp1]=1000;
    }
    for(int i=1;i<=N;i++)
    {
        G[i][i+100]=1;
    }
    for(int i=1;i<=200;i++)
    {
        for(int j=1;j<=200;j++)
        {
            Gf[i][j]=G[i][j];
        }
    }
}

bool BFS()
{
    int mark[N+101];
    memset(pre,-1,sizeof(pre));
    memset(mark,false,sizeof(mark));
    queue<int>que;
    que.push(c1+100);
    mark[c1+100]=true;
    mark[c1]=true;
    mark[c2+100]=true;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(int i=1;i<=N+100;i++)
        {
            if(!mark[i]&&Gf[node][i]>0)
            {
                mark[i]=true;
                pre[i]=node;
                que.push(i);
            }
        }
    }
    return mark[c2];
}

int max_flow()
{
    memset(flow,0,sizeof(flow));
    for(int i=1;i<=100+N;i++)
    {
        for(int j=1;j<=100+N;j++)
        {
            Gf[i][j]=G[i][j];
        }
    }

    while(BFS())
    {
        int tmp=pre[c2];
        int maxflow=1000;
        while(pre[tmp]!=-1)
        {
            int finish=tmp;
            int start=pre[tmp];
            maxflow=min(maxflow,Gf[start][finish]);
            tmp=pre[tmp];
        }
        tmp=c2;

        while(pre[tmp]!=-1)
        {
            int finish=tmp;
            int start=pre[tmp];
            flow[start][finish]+=maxflow;
            Gf[start][finish]-=maxflow;
            Gf[finish][start]+=maxflow;
            tmp=pre[tmp];
        }
    }

    int result=0;
    for(int i=1;i<=N;i++)
    {
        result+=flow[c1+100][i]-flow[i][c1];
    }
    return result;
}

void findlist()
{
    int comlist[N+1];
    memset(comlist,0,sizeof(comlist));
    for(int i=1;i<=N;i++)
    {
        if(Gf[i][i+100]==0)
        {
            comlist[++comlist[0]]=i;
        }
    }

    int innum=0;
    for(int i=1;i<=comlist[0];i++)
    {
        innum++;
        int node=comlist[i];
        G[node][node+100]=0;
        if(max_flow()==result1-innum)
        {
            result2[innum]=node;
        }
        else
        {
            G[node][node+100]=1;
            innum--;
        }
        if(innum==result1)break;
    }
}

void solution()
{
    result1=max_flow();
    findlist();
}

void print()
{
    cout<<result1<<"\n";
    fout<<result1<<"\n";
    for(int i=1;i<result1;i++)
        fout<<result2[i]<<" ";
    fout<<result2[result1]<<"\n";
    for(int i=1;i<=result1;i++)
        cout<<result2[i]<<"\n";
}

int main()
{
    init();
    solution();
    print();
    return 0;
}
