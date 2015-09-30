#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;

//ifstream fin("input.txt");
int testtime;
string T;
string P;
int result;
int Next[10010];

void output(int result)
{
    cout<<result<<"\n";
}

void compute_prefix()
{
    int m=P.length();
    memset(Next,-1,sizeof(Next));
    int k=-1;
    for(int q=1;q<m;q++)
    {
        while(k>=0&&P[k+1]!=P[q])
            k=Next[k];
        if(P[k+1]==P[q])
            k=k+1;
        Next[q]=k;
    }
}

void KMP_matcher()
{
    compute_prefix();
    int n=T.length();
    int m=P.length();
    int q=-1;
    for(int i=0;i<n;i++)
    {
        while(q>=0&&P[q+1]!=T[i])
            q=Next[q];
        if(P[q+1]==T[i])
            q=q+1;
        if(q==m-1)
        {
            result++;
            q=Next[q];
        }
    }
}

void solve()
{
    KMP_matcher();
}

void input()
{
    cin>>testtime;
    for(int i=0;i<testtime;i++)
    {
        result=0;
        cin>>P>>T;
        solve();
        output(result);
    }
}
int main()
{
    input();
    return 0;
}
