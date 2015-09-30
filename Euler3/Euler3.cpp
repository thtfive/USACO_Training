#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
vector<int>G[40000];
queue<int>S;
int num;
void DFS(int node)
{
    while(!G[node].empty())
    {
        int s=G[node].size();
        int newnode=G[node][s-1];
        int edge=node*2+(newnode%2);
        S.push(edge);
        G[node].pop_back();
        DFS(newnode);
    }
}

int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int N;
    cin>>N;
    num=1<<(N-1);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<=1;j++)
        {
           int x=(i<<1)%num+j;
           G[i].push_back(x);
        }
    }
    DFS(0);

    string str;
    string strlib="01";
    int node=S.front();S.pop();
    for(int i=1;i<=N;i++)
    {
        str=strlib[node%2]+str;
        node/=2;
    }
    while(!S.empty())
    {
        node=S.front();
        S.pop();
        if(str.length()<2*num)
        str+=strlib[node%2];
    }
    cout<<str<<"\n";
//    for(int i=0;i<num;i++)
//    {
//        int n=G[i].size();
//        for(int j=0;j<n;j++)
//        {
//            cout<<i<<"->"<<G[i][j]<<"\n";
//        }
//    }

    return 0;
}
