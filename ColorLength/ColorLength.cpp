#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 100000000
#define maxn 5002
int d[maxn][maxn];
int start1[26],start2[26];
int finish1[26],finish2[26];
int inRange(int x,int y)
{
    int counter=0;
    for(int idx=0;idx<26;idx++)
    if((x>=start1[idx]&&x<finish1[idx])||(y>=start2[idx]&&y<finish2[idx])
       ||(x>=start1[idx]&&y<finish2[idx])||(y>=start2[idx]&&x<finish1[idx]))
    {
        counter++;
    }
    return counter;
}
int main()
{
    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        string str1,str2;
        cin>>str1>>str2;
        str1=" "+str1;
        str2=" "+str2;
        int n1=str1.length();
        int n2=str2.length();

        for(int i=0;i<26;i++)
            start1[i]=start2[i]=inf;
        memset(finish1,-1,sizeof(finish1));
        memset(finish2,-1,sizeof(finish2));
        for(int i=1;i<n1;i++)
        {
            int ch=str1[i]-'A';
            if(start1[ch]==inf)
            {
                start1[ch]=i;
            }
            finish1[ch]=i;
        }
        for(int i=1;i<n2;i++)
        {
            int ch=str2[i]-'A';
            if(start2[ch]==inf)
            {
                start2[ch]=i;
            }
            finish2[ch]=i;
        }

        d[0][0]=0;
        for(int j=1;j<n2;j++)
        {
            d[0][j]=d[0][j-1]+inRange(0,j);
        }
        for(int i=1;i<n1;i++)
        {
            d[i][0]=d[i-1][0]+inRange(i,0);
        }
        for(int i=1;i<n1;i++)
        {
            for(int j=1;j<n2;j++)
            {
                d[i][j]=min(d[i-1][j],d[i][j-1])+inRange(i,j);
            }
        }
        cout<<d[n1-1][n2-1]<<endl;
    }
    return 0;
}
