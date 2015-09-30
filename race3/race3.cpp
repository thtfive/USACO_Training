/*
ID:thtfive
LANG:C++
TASK:race3
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int G[50][50];
int N;

bool BFS(int node)
{
    queue<int>que;
    que.push(0);
    bool flag[N];
    for(int i=0;i<N;i++)
        flag[i]=false;
    flag[node]=true;
    flag[0]=true;
    while(!que.empty())
    {
        int point=que.front();
        que.pop();
        for(int i=0;i<N;i++)
        {
            if(G[point][i]==1&&!flag[i])
            {
                flag[i]=true;
                que.push(i);
            }
        }
    }
    return flag[N-1];///judge if point N-1 has been in the queue
}

bool BFScommon(int node)
{
    queue<int>que;
    que.push(0);
    short flag[N];
    for(int i=0;i<N;i++)
        flag[i]=0;
    flag[node]=2;
    flag[0]=1;

    while(!que.empty())
    {
        int point=que.front();
        que.pop();
        for(int i=0;i<N;i++)
        {
            if(G[point][i]==1&&flag[i]==0)
            {
                flag[i]=1;
                que.push(i);
            }
        }
    }

    que.push(node);
    while(!que.empty())
    {

        int point=que.front();
        que.pop();
        for(int i=0;i<N;i++)
        {
            if(G[point][i]==1&&flag[i]==0)
            {
                flag[i]=2;
                que.push(i);
            }
            if(G[point][i]==1&&flag[i]==1)return false;
        }
    }
    return true;
}

int main()
{
    int tmp;
    ifstream fin("race3.in");
    ofstream fout("race3.out");
    N=0;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            G[i][j]=0;
        }
    }

    while(1)
    {
        while(1)
        {
            fin>>tmp;
            if(tmp!=-2&&tmp!=-1)
            {
                G[N][tmp]=1;
            }
            else break;
        }
        if(tmp==-1)break;
        N++;
    }

    bool unavoidable[N];
    bool seperatepoint[N];
    for(int i=0;i<N;i++)
    {
        unavoidable[i]=false;
        seperatepoint[i]=false;
    }
    int num1=0,num2=0;

    for(int i=1;i<N-1;i++)
    {
        if(!BFS(i))
        {
            unavoidable[i]=true;
            num1++;
        }
    }

    for(int i=0;i<N;i++)
    {
        if(unavoidable[i])
        {
            seperatepoint[i]=BFScommon(i);
            if(seperatepoint[i])num2++;
        }
    }

    fout<<num1;
    for(int i=0;i<N;i++)
    {
        if(unavoidable[i])fout<<" "<<i;
    }
    fout<<"\n";
    fout<<num2;
    for(int i=0;i<N;i++)
    {
        if(seperatepoint[i])fout<<" "<<i;
    }
    fout<<"\n";

    return 0;
}
