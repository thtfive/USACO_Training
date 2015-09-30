#include<iostream>
#include<fstream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
//ifstream fin("input.txt");
struct Trie
{
    int data[1000010][26];
    int val[1000010];
    int sz;
    Trie()
    {
        sz=0;
        memset(data,0,sizeof(data));
        memset(val,0,sizeof(val));
    }
    void insert(string str)
    {
        int length=str.length();
        int u=0;
        for(int i=0;i<length;i++)
        {
            int num=str[i]-'a';
            if(!data[u][num])
            {
                data[u][num]=++sz;
            }
            u=data[u][num];
            val[u]++;
        }
    }

    int searcher(string str)
    {
        int length=str.length();
        int result=0;
        int u=0;
        for(int i=0;i<length;i++)
        {
            int num=str[i]-'a';
            if(!data[u][num])
            {
                return 0;
            }
            u=data[u][num];
        }
        result=val[u];
        return result;
    }
}trie;

void output(int result)
{
    cout<<result<<"\n";
}

void input()
{
    cin>>n;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        trie.insert(str);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>str;
        int result;
        result=trie.searcher(str);
        output(result);
    }
}

int main()
{
    input();
    return 0;
}
