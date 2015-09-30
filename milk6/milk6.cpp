/*
ID:thtfive
LANG:C++
TASK:milk6
*/
#include<fstream>
#include<iostream>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std;
int G[33][33];
int Gf[33][33];
int flow[33][33];
int path[33];
int record[1001];
int recordnum;
int sides[1001][2];
short searched[33];
queue <int>pathque;
int mincut=999999999;
int N,M;

bool BFS()
{
    queue<int>que;
    que.push(1);
    bool flag[N+1];
    memset(path,-1,sizeof(path));
    memset(flag,false,sizeof(flag));
    flag[1]=true;

    while(!que.empty())
    {
        int node=que.front();
        que.pop();

        for(int i=1;i<=N;i++)
        {
            if(Gf[node][i]>0&&!flag[i])
            {
                flag[i]=true;
                path[i]=node;
                que.push(i);
            }
        }
    }
    if(path[N]!=-1)return true;
    else return false;
}

bool BFS2()
{
    queue<int>que;
    memset(searched,0,sizeof(searched));
    que.push(1);
    searched[1]=2;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(int i=1;i<N;i++)
        {
            if(Gf[node][i]>0&&searched[i]==0)
            {
                searched[i]=2;
                path[i]=node;
                que.push(i);
            }
        }
    }
    return true;
}

int index(int *road,int &index,int start,int finish)
{
    for(int result=1;result<=M;result++)
    {
        if(sides[result][0]==start&&sides[result][1]==finish)
            road[++index]=result;
    }
    return 0;
}

int partition(int *array,int start,int finish)
{
    int mid=start-1;
    for(int i=start;i<finish;i++)
    {
        if(array[i]<array[finish])
        {
            mid++;
            int tmp=array[i];
            array[i]=array[mid];
            array[mid]=tmp;
        }
    }
    mid++;
    int tmp=array[finish];
    array[finish]=array[mid];
    array[mid]=tmp;
    return mid;
}

void sort(int *array,int start,int finish)
{
    if(start<finish)
    {
        int mid=partition(array,start,finish);
        sort(array,start,mid-1);
        sort(array,mid+1,finish);
    }
}

void solution()
{
    BFS2();
    recordnum=0;
    mincut=999999321;
    int cuttmp=0;

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(searched[i]==2&&searched[j]!=2&&Gf[i][j]==0&&G[i][j]!=0)
            {
                if(j!=N)
                {
                    pathque.push(j);
                    searched[j]=1;
                }
                cuttmp+=flow[i][j]-flow[j][i];
                index(record,recordnum,i,j);
            }
        }
    }
    mincut=cuttmp;

    sort(record,1,recordnum);
    while(!pathque.empty())
    {
        int node=pathque.front();

        pathque.pop();
        searched[node]=2;

        int recordtmp[1001];
        int cutnum=0;
        cuttmp=0;
        bool flag=true;
        for(int i=1;i<N;i++)///计算新的最小割集
        {
            for(int j=1;j<=N;j++)
            {
                if(searched[i]==2&&searched[j]!=2&&G[i][j]>0)
                {
                    if(Gf[i][j]!=0)flag=false;
                    if(searched[j]==0&&j!=N)
                    {
                        searched[j]=1;
                        pathque.push(j);
                    }
                    index(recordtmp,cutnum,i,j);
                    cuttmp+=flow[i][j]-flow[j][i];
                }
            }
        }
        sort(recordtmp,1,cutnum);
        if(!flag)continue;
        if(cuttmp<mincut||(cuttmp==mincut&&recordnum>cutnum))
        {
            for(int i=1;i<=cutnum;i++)
            {
                record[i]=recordtmp[i];
            }
            recordnum=cutnum;
            mincut=cuttmp;
        }
        if(cuttmp==mincut&&recordnum==cutnum)
        {
            bool mark=false;
            for(int i=1;i<=cutnum;i++)
            {
                if(record[i]>recordtmp[i])
                {
                    mark=true;
                    break;
                }
                if(record[i]<recordtmp[i])
                {
                    mark=false;
                    break;
                }
            }
            if(mark)
            {
                for(int i=1;i<=recordnum;i++)
                    record[i]=recordtmp[i];
            }
        }
    }
}

int main()
{
    ifstream fin("milk6.in");
    ofstream fout("milk6.out");
    fin>>N>>M;
    memset(G,0,sizeof(G));
    memset(Gf,0,sizeof(Gf));
    memset(sides,-1,sizeof(sides));
    for(int i=1;i<=M;i++)
    {
        int start,finish,cost;
        fin>>start>>finish>>cost;
        sides[i][0]=start;
        sides[i][1]=finish;
        G[start][finish]+=cost;
        Gf[start][finish]=G[start][finish];
    }

    while(BFS())
    {
        int node=N;
        int min=99999999;
        int start,finish;
        while(path[node]!=-1)
        {
            start=path[node];
            finish=node;
            if(Gf[start][finish]<min)min=Gf[start][finish];
            node=start;
        }
        node=N;
        while(path[node]!=-1)
        {
            start=path[node];
            finish=node;

            flow[start][finish]+=min;
            Gf[start][finish]-=min;
            Gf[finish][start]=G[finish][start]+flow[start][finish];

            node=start;
        }
    }

    BFS2();
    solution();

    fout<<mincut<<" "<<recordnum<<"\n";
    for(int i=1;i<=recordnum;i++)
        fout<<record[i]<<"\n";

    return 0;
}
