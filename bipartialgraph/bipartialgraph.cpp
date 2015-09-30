#define LOCAL
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

#define maxN 100010
vector <int>G[maxN];
int color[maxN];
int T;
bool flag;

void encolor(int node,int c)
{
    if(color[node]!=-1)
    {
        if(color[node]!=c)
        {
            flag=false;
        }
        return;
    }
    color[node]=c;
    int num=G[node].size();
    for(int i=0;i<num;i++)
    {
        encolor(G[node][i],(c+1)%2);
    }
    return;
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    cin>>T;
    int N,M;
    while(T--)
    {
        cin>>N>>M;
        for(int i=1;i<=N;i++)
            G[i].clear();

        int x,y;

        memset(color,-1,sizeof(color));
        for(int i=1;i<=M;i++)
        {
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        flag=true;
        for(int i=1;i<=N;i++)
        {
            if(color[i]==-1)
                encolor(i,0);
        }

        if(flag)cout<<"Correct\n";
        else cout<<"Wrong\n";

    }
    return 0;
}
