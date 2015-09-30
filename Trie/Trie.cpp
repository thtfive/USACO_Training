/*
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxnode 1000
#define sigma_size 26
struct Trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));}
    int idx(char c){return c-'a';}

    void insert(char *s,int v)
    {
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            cout<<"u: "<<u<<"\n";
            cout<<"c: "<<c<<"\n";
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }
}str;

int main()
{
    str.insert("afgd",2);
    cout<<"herehere\n";
    str.insert("afgdh",2);
        cout<<"herehere\n";
    str.insert("hk",2);

    return 0;
}
