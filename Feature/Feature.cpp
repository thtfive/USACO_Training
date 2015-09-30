#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define inf 1000000000
#define maxM 101
#define maxN 20
using namespace std;
int N,M;
int status[maxM][2][21];
int cost[maxM];
int d[(1<<20)+10];
bool intree[(1<<20)+10];
//map<string,int>d;
//map<string,int>intree;
priority_queue <pair<int,int> >PQ;
int start,finish;

bool ifsatisfy(int &start,int patchnum)
{
    for(int i=0;i<N;i++)
    {
        int tmp=start&(1<<i);
        if(status[patchnum][0][i]!=-1)
        {
            int flag=status[patchnum][0][i];
            if((!tmp&&flag)||(!flag&&tmp))
            return false;
        }
        int after=status[patchnum][1][i];
        if(after==1)
        {
            start|=(1<<i);
        }
        if(after==0)
        {
            start&=~(1<<i);
        }
    }
    return true;
}

void relaxion(int node,int D)
{
    for(int i=1;i<=M;i++)
    {
        int nodetmp=node;
        if(ifsatisfy(nodetmp,i))
        {
            if(d[nodetmp]==-1||d[nodetmp]>D+cost[i])
            {
                d[nodetmp]=D+cost[i];
                if(!intree[nodetmp])
                    PQ.push(make_pair(-D-cost[i],nodetmp));
            }
        }
    }
}
int dijkstra()
{
    finish=0;
    start=(1<<N)-1;
    d[start]=0;
    PQ.push(make_pair(0,start));
    memset(intree,0,sizeof(intree));
    memset(d,-1,sizeof(d));
    while(!PQ.empty())
    {
        pair<int,int>P=PQ.top();
        PQ.pop();
        if(intree[P.second])continue;
        intree[P.second]=1;
        d[P.second]=-P.first;
        relaxion(P.second,-P.first);
        if(intree[0])break;
    }
    if(intree[finish])return d[finish];
    else return -1;
}
int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int t=0;
    while(cin>>N>>M&&(N||M))
    {
        t++;
        while(!PQ.empty())
        {
            PQ.pop();
        }
        for(int i=1;i<=M;i++)
        {
            string str1,str2;
            cin>>cost[i]>>str1>>str2;
            for(int j=0;j<N;j++)
            {
                switch(str1[j])
                {
                    case '+':status[i][0][j]=1;break;
                    case '-':status[i][0][j]=0;break;
                    case '0':status[i][0][j]=-1;break;
                }
                switch(str2[j])
                {
                    case '+':status[i][1][j]=1;break;
                    case '-':status[i][1][j]=0;break;
                    case '0':status[i][1][j]=-1;break;
                }
            }
        }
        int result=dijkstra();

        cout<<"Product "<<t<<endl;
        if(result==-1)
            cout<<"Bugs cannot be fixed.\n";
        else
            cout<<"Fastest sequence takes "<<d[finish]<<" seconds.\n";
        cout<<"\n";
    }
    return 0;
}
