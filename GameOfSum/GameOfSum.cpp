#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=100000000;
int d[101][101];///用d[i][j]代表从i->j这个段先取的人可以取到的最大和
///d[i][j]=max(sum[i...j]-d[k][j],sum[i...j]-d[i][t],sum[i...j]),i<k<=j,i<=t<j
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    while(cin>>n,n)
    {
        int num[n+1];
        int sum[n+1];
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            d[i][i]=num[i];
            sum[i]=sum[i-1]+num[i];
        }
        for(int len=2;len<=n;len++)
        {
            int j;
            for(int i=1;j=i+len-1,j<=n;i++)
            {
                int maxnum=-inf;
                int sum_tmp=sum[j]-sum[i-1];
                for(int k=i;k<j;k++)
                    maxnum=max(maxnum,sum[j]-sum[i-1]-d[k+1][j]);

                for(int k=i+1;k<=j;k++)
                    maxnum=max(maxnum,sum_tmp-d[i][k-1]);
                maxnum=max(maxnum,sum[j]-sum[i-1]);
                d[i][j]=maxnum;
            }
        }
        int result=2*d[1][n]-sum[n];
        cout<<result<<endl;
    }
}
