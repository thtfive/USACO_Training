#define LOCAL
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define maxn 110

int N;

vector <int> G[maxn];
struct treeNode
{
    int father;
    treeNode()
    {
        father=-1;
    }
}nodes[maxn];

void build_tree(int root,int father)
{
    nodes[root].father=father;
    cout<<father<<"->"<<root<<"\n";
    int num=G[root].size();
    for(int i=0;i<num;i++)
    {
        int n=G[root][i];
        if(n!=father)
        {
            build_tree(n,root);
        }
    }
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int tmp1,tmp2;
        for(int i=1;i<=N;i++)G[i].clear();
        for(int i=1;i<N;i++)
        {
            cin>>tmp1>>tmp2;
            G[tmp1].push_back(tmp2);
            G[tmp2].push_back(tmp1);
        }
        build_tree(1,0);
        int M;
        cin>>M;
        int order[M];
        for(int i=0;i<M;i++)
            cin>>order[i];
        int pre[maxn];
        bool flag=true;
        memset(pre,0,sizeof(pre));
        for(int i=0;i<M&&flag;i++)
        {
            int p=order[i];
            if(pre[p]==1)
            {
                flag=false;
                break;
            }
            while(nodes[p].father!=0)
            {
                p=nodes[p].father;
                pre[p]=1;
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
