#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1000;
const char *s;
int sa[maxn],t[maxn],t2[maxn],c[maxn],n;

void build_sa(int m)
{
    int i,*Rank_tmp=t,*Sa_tmp=t2;
    for(int i=0;i<m;i++)c[i]=0;
    for(int i=0;i<n;i++)
    {
        c[Rank_tmp[i]=s[i]]++;
    }
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)sa[--c[Rank_tmp[i]]]=i;

    for(int k=1;k<=n;k*=2)
    {
        int p=0;
        for(int i=n-k;i<n;i++)Sa_tmp[p++]=i;///这句话的意思是，排在第0个的是suffix[n-k],第1个的是suffix[n-k+1]...第k-1个是suffix[n-1]
        for (int i=0;i<n;i++)if(sa[i]>=k)Sa_tmp[p++]=sa[i]-k;

        ///基数排序第一关键字
        for (int i=0;i<m;i++)c[i]=0;
        for (int i=0;i<n;i++)c[Rank_tmp[Sa_tmp[i]]]++;
        for (int i=1;i<m;i++)c[i]+=c[i-1];
        for (int i=n-1;i>=0;i--)sa[--c[Rank_tmp[Sa_tmp[i]]]]=Sa_tmp[i];

        swap(Rank_tmp,Sa_tmp);
        p=1;
        Rank_tmp[sa[0]]=0;
        for(int i=1;i<n;i++)
            Rank_tmp[sa[i]]=Sa_tmp[sa[i-1]]==Sa_tmp[sa[i]] && Sa_tmp[sa[i-1]+k]==Sa_tmp[sa[i]+k]?p-1:p++;
        if(p>=n)break;
        m=p;
    }
}


int main()
{
    s="dfafasdfagfs";
    build_sa(200);
    for (int i=0;i<n;i++)
    cout<<"Sa["<<i<<"]: "<<sa[i]<<endl;


    return 0;
}


