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

string str;
bool d[maxn][maxn];
int num[maxn];
int N;
int main()
{
    freopen("input.txt","r",stdin);
    cin>>N;
    while(N--)
    {
        cin>>str;
        int len=str.length();
        memset(d,false,sizeof(d));
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<=i;j++)
            {
                d[i][j]=1;
            }
        }

        for(int l=2;l<=len;l++)
        {
            for(int start=0;start+l-1<len;start++)
            {
                if(str[start]==str[start+l-1]&&d[start+1][start+l-2])
                {
                    d[start][start+l-1]=true;
                }
                else
                {
                    d[start][start+l-1]=false;
                }
            }
        }

        num[0]=1;
        for(int i=1;i<len;i++)
        {
            num[i]=inf;
            for(int j=0;j<=i;j++)
            {
                if(d[j][i])
                {
                    if(j==0)
                    {
                        num[i]=1;
                    }
                    else if(num[i]>num[j-1]+1)
                    {
                        num[i]=num[j-1]+1;
                    }
                }
            }
        }
        cout<<num[len-1]<<endl;
    }
    return 0;
}
