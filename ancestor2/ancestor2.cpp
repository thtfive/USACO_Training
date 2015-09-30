#define LOCAL
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<fstream>
#include<cmath>
using namespace std;

#define maxN 100010
map <string,int>ID;
string Name[maxN];
int color[maxN];
int father[maxN];
vector<int>son[maxN];
vector<pair<int,int> >query[maxN];
int ans[maxN];

int findfather(int id)
{
    return color[father[id]]==1?father[id]:father[id]=findfather(father[id]);
}

void searcher(int id)
{
    color[id]=1;
    int relatenum=query[id].size();
    for(int i=0;i<relatenum;i++)
    {
        pair<int,int>P=query[id][i];
        if(color[P.first]==1)
        {
            ///如果相关联的被查找过
            ans[P.second]=P.first;
        }
        if(color[P.first]==2)
        {
            ///如果相关联颜色为2
            int fatherid=findfather(P.first);
            ans[P.second]=fatherid;
        }
    }

    int sonnum=son[id].size();
    for(int i=0;i<sonnum;i++)
    {
        int sonid=son[id][i];
        searcher(sonid);
    }
    color[id]=2;
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    int N;
    int M;
    cin>>N;
    string name1,name2;
    int ancestor;
    int tot=0;
    memset(father,-1,sizeof(father));
    memset(color,0,sizeof(color));
    for(int i=1;i<=N;i++)
    {
        cin>>name1>>name2;
        if(ID[name1]==0)
        {
            tot++;
            ID[name1]=tot;
            Name[tot]=name1;
        }
        if(ID[name2]==0)
        {
            tot++;
            ID[name2]=tot;
            Name[tot]=name2;
        }
        father[ID[name2]]=ID[name1];
        son[ID[name1]].push_back(ID[name2]);
        if(father[ID[name1]]==-1)ancestor=ID[name1];
    }
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>name1>>name2;
        query[ID[name1]].push_back(make_pair(ID[name2],i));
        query[ID[name2]].push_back(make_pair(ID[name1],i));
    }
    searcher(ancestor);

    for(int i=0;i<M;i++)
    {
        cout<<Name[ans[i]]<<"\n";
    }
    return 0;
}
