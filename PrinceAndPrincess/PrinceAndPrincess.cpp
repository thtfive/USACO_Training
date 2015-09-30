#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 62510
int num[maxn];
int n,p,q;
int Len[maxn];
int B[maxn];
int record[maxn];
int maxL;

int first_bigger(int *arr,int start,int finish,int key)
{
    int mid=(start+finish)/2;
    if(start==finish)return start;
    if(arr[mid]<key)
    {
        return first_bigger(arr,mid+1,finish,key);
    }
    else
    {
        return first_bigger(arr,start,mid,key);
    }
}
int main()
{
    #define local
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif
    int T;
    int kase=0;
    cin>>T;
    while(T--)
    {
        kase++;
        cin>>n>>p>>q;
        memset(num,0,sizeof(num));
        for(int i=1;i<=p+1;i++)
        {
            int a;
            cin>>a;
            num[a]=i;
        }
        for(int j=1;j<=q+1;j++)
        {
            int b;
            cin>>b;
            B[j]=num[b];
        }
        for(int i=0;i<=q+1;i++)
            record[i]=maxn;
        int ans=0;
        for(int i=1;i<=q+1;i++)
        {
            int k=first_bigger(record,1,q+1,B[i]);
            record[k]=B[i];
            Len[i]=k;
            ans=max(k,ans);
        }
        cout<<"Case "<<kase<<": "<<ans<<"\n";
    }
    return 0;
}
