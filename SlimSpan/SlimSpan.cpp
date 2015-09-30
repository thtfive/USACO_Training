#define local
#include<iostream>
#include<fstream>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxM 5000
#define maxN 110
#define inf 1000000000
///with kruskal method build MST
///choose the minimum edge from the smallest weighted-edge to the biggest one
pair<int,pair<int,int> >edges[maxM];
int father[maxN];
int m,n;
int findfather(int x)
{
    return father[x]==x?x:father[x]=findfather(father[x]);
}
bool build_MST(int start,int &finish)
{
    for(int i=1;i<=n;i++)
        father[i]=i;
    int x,y;
    for(int e=start;e<=m;e++)
    {
        x=edges[e].second.first;
        y=edges[e].second.second;
        int px=findfather(x);
        int py=findfather(y);
        if(px!=py)
        {
            father[px]=py;
            finish=e;
        }
    }
    int samefather=findfather(1);
    for(int i=2;i<=n;i++)
    {
        if(findfather(i)!=samefather)return false;
    }
    return true;
}
int main()
{
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    cin>>n>>m;
    while(n||m)
    {
        int x,y,weight;
        int slim=inf;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y>>weight;
            edges[i]=make_pair(weight,make_pair(x,y));
        }
        sort(edges+1,edges+m+1);
        int finish;
        for(int i=1;i<=m-n+2;i++)
        {
            if(build_MST(i,finish))
            {
                int large=edges[finish].first;
                int small=edges[i].first;
                int diff=large-small;
               // cout<<"start:"<<i<<" finish:"<<finish<<" "<<diff<<endl;
                slim=slim<diff?slim:diff;
            }
            else
                break;
        }
        if(slim!=inf)
            cout<<slim<<"\n";
        else
            cout<<-1<<"\n";
        cin>>n>>m;
    }
    return 0;
}
