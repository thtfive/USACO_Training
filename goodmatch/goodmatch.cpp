#define local
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>

#define maxN 100010
using namespace std;
pair<long long,long long> Num1[maxN];
pair<long long,long long> Num2[maxN];
int main()
{
    #ifdef local
    freopen("input.txt","r",stdin);
    #endif // local
    int T;
    cin>>T;
    while(T--)
    {

        int m,n,x,y;
        cin>>m>>n;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            Num1[i]=make_pair(x,y);
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            Num2[i]=make_pair(x,y);
        }
        sort(Num1+1,Num1+m+1);
        sort(Num2+1,Num2+n+1);

        for(int i=2;i<=n;i++)
        {
            Num2[i].second+=Num2[i-1].second;
        }

        long long ans=0;
        int index=1;
        for(int i=1;i<=m;i++)
        {
            while(index<=n&&Num1[i].first>Num2[index].first)
            {
                index++;
            }
            if(index>1&&Num1[i].first>Num2[index-1].first)
                ans+=Num1[i].second*Num2[index-1].second;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
