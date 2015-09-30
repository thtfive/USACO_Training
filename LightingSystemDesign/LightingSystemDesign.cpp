#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define inf 2000000000
#define maxn 1002

struct Light
{
    int v,k,c,l;
    Light(int V,int K,int C,int L):v(V),k(K),c(C),l(L){}
    Light(){}
    friend bool operator<(const Light & a,const Light & b)
    {
        return a.v<b.v;
    }
}lights[maxn];

int N;
int num[maxn];
int d[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    cin>>N;
    while(N)
    {
        for(int i=1;i<=N;i++)
        {
            int v,k,c,l;
            cin>>v>>k>>c>>l;
            lights[i]=Light(v,k,c,l);
        }
        sort(lights+1,lights+N+1);
        num[0]=0;
        for(int i=1;i<=N;i++)
        {
            num[i]=lights[i].l+num[i-1];
        }
        d[0]=0;
        for(int i=1;i<=N;i++)
        {
            d[i]=inf;
            for(int j=0;j<i;j++)
            {
                d[i]=min(d[i],d[j]+(num[i]-num[j])*lights[i].c+lights[i].k);
            }
        }
        printf("%d\n",d[N]);
        cin>>N;
    }
    return 0;
}
