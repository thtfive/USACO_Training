#define local
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
#define maxN 26
map<string,int>ID_cache;
string Name_cache[30];
int G[maxN][maxN];

int main()
{
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int n,m;
    int T=0;
    cin>>n>>m;
    while(1)
    {
        int id=1;
        T++;
        ID_cache.clear();
        memset(G,0,sizeof(G));
        for(int i=1;i<=m;i++)
        {
            string name1,name2;
            cin>>name1>>name2;
            if(ID_cache[name1]==0)
            {
                Name_cache[id]=name1;
                ID_cache[name1]=id++;
            }
            if(ID_cache[name2]==0)
            {
                Name_cache[id]=name2;
                ID_cache[name2]=id++;
            }
            G[ID_cache[name1]][ID_cache[name2]]=1;
        }
        for(int k=1;k<=n;k++)///floyd method for transitive closure
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                G[i][j]=G[i][j]||(G[i][k]&&G[k][j]);
            }
        }

        int flag[n+1];
        memset(flag,false,sizeof(flag));
        vector<int>circles[n+1];
        for(int i=1;i<=n;i++)
        {
            if(!flag[i])
            {
                flag[i]=true;
                circles[i].push_back(i);
                for(int j=1;j<=n;j++)
                {
                    if(G[i][j]&&G[j][i]&&i!=j)
                    {
                        circles[i].push_back(j);
                        flag[j]=true;
                    }
                }
            }
        }
        cout<<"Calling circles for data set "<<T<<":\n";
        for(int i=1;i<=n;i++)
        {
            int s=circles[i].size();
            if(s>0)
            {
                for(int j=0;j<s-1;j++)
                {
                    cout<<Name_cache[circles[i][j]]<<", ";
                }
                cout<<Name_cache[circles[i][s-1]]<<"\n";
            }
        }
        cin>>n>>m;
        if(n||m)cout<<"\n";
        else break;
    }
    return 0;
}
