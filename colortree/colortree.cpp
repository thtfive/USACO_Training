#define LOCAL
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define maxn 100010

int N;
int totaltreenum;
int edgenum;
int starter[maxn];

map<int,int>son_num_of_color[maxn];
vector<int>G[maxn];

struct treeNode
{
    int color;
    int father;
    treeNode()
    {
        father=-1;
        color=0;
    }
};


void build_tree(int root,int fa,treeNode *nodes)
{
    nodes[root].father=fa;
    int num=G[root].size();
    for(int i=0;i<num;i++)
    {
        int n=G[root][i];
        if(n!=fa)
        {
//            cout<<root<<"->"<<n<<"\n";
            son_num_of_color[root][0]++;
            build_tree(n,root,nodes);
        }
    }
}

void change_treenum(int root,int color,treeNode *nodes)
{
    int father=nodes[root].father;
    int precolor=nodes[root].color;
    nodes[root].color=color;
    if(father!=-1)
    {
        if(precolor==nodes[father].color)
            totaltreenum++;
        if(color==nodes[father].color)
            totaltreenum--;
        son_num_of_color[father][precolor]--;
        son_num_of_color[father][color]++;
    }
    totaltreenum+=son_num_of_color[root][precolor];
    totaltreenum-=son_num_of_color[root][color];
}

int main()
{
    int Test;
    #ifdef LOCAL
    freopen("colortree.in","r",stdin);
    #endif // LOCAL
  //  cin>>Test;
    scanf("%d",&Test);
    for (int T=1;T<=Test;T++)
    {
        //cin>>N;
        scanf("%d",&N);
        edgenum=0;
        for(int i=0;i<=N;i++)G[i].clear();///clear G
        for(int i=0;i<=N;i++)son_num_of_color[i].clear();
        treeNode nodes[N+1];
        int tmp1,tmp2;
        memset(starter,0,sizeof(starter));
        for(int i=1;i<N;i++)
        {
            //cin>>tmp1>>tmp2;
            scanf("%d%d",&tmp1,&tmp2);
            G[tmp1].push_back(tmp2);
            G[tmp2].push_back(tmp1);
        }
        build_tree(1,-1,nodes);
        totaltreenum=1;
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",T);
        for(int i=0;i<q;i++)
        {
            int op;
            //cin>>op;
            scanf("%d",&op);
            if(op==1)
            {
                printf("%d\n",totaltreenum);
            }
            if(op==2)
            {
                int n,color;
                scanf("%d%d",&n,&color);
                change_treenum(n,color,nodes);
            }
        }
    }
    return 0;
}
