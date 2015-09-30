/*
ID:thtfive
TASK:cowxor
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
#define maxnum 100000+10
ifstream fin("cowxor.in");
ofstream fout("cowxor.out");
int N;
int start;
int finish;
int result;
int values[maxnum];
int xorsum[maxnum];

struct Trie
{
    int ch[2<<18][2];
    int val[2<<18];
    int sz;
    int idx(char c){return c-'0';}
    Trie()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
    }

    void insert(string s,int v)
    {
        int u=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }

    int find_max(int value,int &maxindex)
    {
        int maxvalue=0;
        int u=0;
        for(int i=20;i>=0;i--)
        {
            int tmp=((value&(1<<i))>>i);
            int c=tmp^1;
            if(!ch[u][tmp^1])
                c=tmp;
            u=ch[u][c];
            maxvalue=(maxvalue<<1)+c;
        }
        maxindex=val[u];
        maxvalue=maxvalue^value;
        return maxvalue;
    }

}trie;

string tobitString(int x)
{
    string str;
    for(int i=20;i>=0;i--)
    {
        int tmp=(x&(1<<i))>>i;
        str+=(tmp==1)?"1":"0";
    }
    return str;
}

void input()
{
    result=-1;
    start=0;
    finish=0;
    fin>>N;

}



void solve()
{
    xorsum[0]=0;
    string str0=tobitString(0);
    trie.insert(str0,0);
    for(int i=1;i<=N;i++)
    {
        fin>>values[i];
        xorsum[i]=xorsum[i-1]^values[i];
        string str=tobitString(xorsum[i]);
        trie.insert(str,i);
        int starttmp;
        int valuetmp=0;
        valuetmp=trie.find_max(xorsum[i],starttmp);
        if(valuetmp>result)
        {
            result=valuetmp;
            start=starttmp+1;
            finish=i;
        }
    }
    if(N==1)
    {
        start=finish=1;
    }
}

void output()
{
    cout<<result<<" "<<start<<" "<<finish<<"\n";
    fout<<result<<" "<<start<<" "<<finish<<"\n";
}

int main()
{
    input();
    solve();
    output();
    return 0;
}
