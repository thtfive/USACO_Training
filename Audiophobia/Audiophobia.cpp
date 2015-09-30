#define local
#include<iostream>
#include<fstream>
#include<map>
#include<cstring>
using namespace std;
#define maxN 110
int inf=1000000000;
int G[maxN][maxN];

int main()
{
    int C,S,Q;
    int T=0;
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    cin>>C>>S>>Q;
    while(C||S||Q)
    {
        T++;
        for(int i=1;i<=C;i++)
            for(int j=1;j<=C;j++)
                G[i][j]=inf;
        for(int i=1;i<=S;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            G[x][y]=v;
            G[y][x]=v;
        }
        for(int k=1;k<=C;k++)
        {
            for(int i=1;i<=C;i++)
            {
                for(int j=1;j<=C;j++)
                {
                    G[i][j]=min(G[i][j],max(G[i][k],G[k][j]));
                }
            }
        }
        cout<<"Case #"<<T<<"\n";
        for(int i=1;i<=Q;i++)
        {
            int x,y;
            cin>>x>>y;
            if(G[x][y]==inf)
                cout<<"no path\n";
            else
                cout<<G[x][y]<<"\n";
        }
        cin>>C>>S>>Q;
        if(C||S||Q)cout<<"\n";
    }
}
