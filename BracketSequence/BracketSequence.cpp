#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
static const int maxn=120;
static const int inf=100000000;
using namespace std;
int d[maxn][maxn];
char str[maxn];
bool match(const char &ch1,const char &ch2)
{
    if(ch1=='('&&ch2==')')return true;
    if(ch1=='['&&ch2==']')return true;
    return false;
}
void print(int start,int finish)
{
    if(start>finish)return;
    if(start==finish)
    {
        if(str[start]=='('||str[start]==')')cout<<"()";
        else cout<<"[]";
        return;
    }
    if(d[start][finish]==d[start+1][finish-1]&&match(str[start],str[finish]))
    {
        cout<<str[start];
        print(start+1,finish-1);
        cout<<str[finish];
        return;
    }
    for(int k=start;k<finish;k++)
    {
        if(d[start][finish]==d[start][k]+d[k+1][finish])
        {
            print(start,k);
            print(k+1,finish);
            return;
        }
    }
}
void readline(char* S) {
  fgets(S, maxn, stdin);
}
int main()
{
    int T;
    memset(d,0,sizeof d);
    freopen("input.txt","r",stdin);
    readline(str);
    sscanf(str, "%d", &T);
    readline(str);
    while(T--)
    {
        readline(str);
        int L=strlen(str)-1;

        for(int i=0;i<L;i++)
        {
            d[i][i]=1;
        }
        for(int i=L-2;i>=0;i--)
        {
            for(int j=i+1;j<L;j++)
            {
                d[i][j]=inf;
                if(match(str[i],str[j]))d[i][j]=min(d[i][j],d[i+1][j-1]);
                for(int k=i;k<j;k++)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]);
                }
            }
        }
        print(0,L-1);
        cout<<endl;
        if(T)cout<<endl;
        readline(str);
    }
    return 0;
}
