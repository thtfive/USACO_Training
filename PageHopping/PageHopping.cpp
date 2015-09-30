#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#define maxn 101
using namespace std;
int G[maxn][maxn];
map <int,int> ID;
int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int a,b;
    int T=0;
    while(cin>>a>>b,a||b)
    {
        T++;
        ID.clear();
        int id=0;
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                G[i][j]=1000;
            }
            G[i][i]=0;
        }
        do
        {
            if(ID.count(a)==0)
            {
                ID[a]=++id;
            }
            if(ID.count(b)==0)
            {
                ID[b]=++id;
            }
            G[ID[a]][ID[b]]=1;
        }while(cin>>a>>b,a||b);
        for(int k=1;k<=id;k++)
        {
            for(int i=1;i<=id;i++)
            {
                for(int j=1;j<=id;j++)
                {
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
                }
            }
        }
        int num=id*(id-1);
        int D=0;
        for(int i=1;i<=id;i++)
        {
            for(int j=1;j<=id;j++)
            {
                if(i!=j)
                    D+=G[i][j];
            }
        }
        double result=double(D)/double(num);
        printf("Case %d: average length between pages = %.3f clicks\n",T,result);
    }
}
