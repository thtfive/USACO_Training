/*
ID:thtfive
LANG:C++
TASK:prefix
*/
#include<fstream>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define max_num 200
string strlib[max_num];
int libN;
int minlen;
int maxlen;

int len;
string str;
int place_record[11][200];
int num_record[11];

int marked_recursive(int sidx,int *mark);

int marked_chain(int sidx,int *mark);

class Node
{
    public:
    string data;
    int flag;
    Node *next[26];
    Node()
    {
        flag=0;
        for (int i=0;i<26;i++)
        next[i]=NULL;
    }
};

class tree
{
    public:
    Node *root;
    tree()
    {
        root=NULL;
    }

    void insert(string str)
    {
        int len=str.length();
        if (root==NULL)root=new Node;
        Node *pt=root;
        for (int idx=0;idx<len;idx++)
        {
            if(pt->next[str[idx]-'A']==NULL)pt->next[str[idx]-'A']=new Node;
            pt=pt->next[str[idx]-'A'];
        }
        pt->flag=1;
    }
    int search(string str)
    {
        int len=str.length();
        if (root==NULL)return -1;
        Node *pt=root;
        for (int idx=0;idx<len;idx++)
        {
            if(pt->next[str[idx]-'A']==NULL)return -1;
            pt=pt->next[str[idx]-'A'];
        }
        return pt->flag;
    }

}Tree;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
//    ifstream fin("prefix.in");
//    ofstream fout("prefix.out");
    string tmp;

    fin>>tmp;
    maxlen=0;
    minlen=11;
    for (int i=1;i<11;i++)num_record[i]=0;
    while(tmp!=".")
    {
        Tree.insert(tmp);
        int lentmp=tmp.length();
        place_record[lentmp][num_record[lentmp]++]=libN;
        if (lentmp>maxlen)maxlen=lentmp;
        if (lentmp<minlen)minlen=lentmp;
        libN++;
        fin>>tmp;
    }

    while(fin>>tmp)str+=tmp;
    len=str.length();
    int mark[len+1];

    //    for (int i=0;i<=maxlen;i++)
//        for (int j=0;j<=len;j++)
//            flag[i][j]=false;
    for (int i=0;i<=len;i++)mark[i]=-1;


//    for (int j=0;j<libN;j++)
//    {
//        int length=strlib[j].length();
//
//        for (int sidx=0;sidx<=len-length;sidx++)
//        {
//            if(!flag[length][sidx])
//            {
//                string strtmp="";
//                for (int t=sidx;t<sidx+length;t++)
//                {
//                    strtmp+=str[t];
//                }
//
//                if (strlib[j]==strtmp)
//                {
//                    flag[length][sidx]=true;
//                }
//            }
//        }
//    }

 //   marked_recursive(0,mark);
     marked_chain(0,mark);
//    for (int i=minlen;i<=maxlen;i++)
//    {
//        cout<<"length: "<<i<<endl;
//        for (int j=0;j<=len;j++)
//        {
//            cout<<flag[i][j]<<" ";
//        }
//        cout<<endl;
//    }

//    mark[len]=0;
//    for (int sidx=len-minlen;sidx>=0;sidx--)
//    {
//        int max=0;
//        for (int l=minlen;l<=maxlen;l++)
//        {
//            if (flag[l][sidx])
//            {
//                int ans=l+mark[sidx+l];
//                if (ans>max)max=ans;
//            }
//        }
//        mark[sidx]=max;
//    }



//
//    for (int i=0;i<libN;i++)cout<<strlib[i]<<"\n";
//    cout<<str<<"\n";

//    if(maxlen-minlen<=5)
//    {
//        marked_recursive(0,mark);
//    }
//    else
//    {
//        marked_chain(0,mark);
//    }
    fout<<mark[0]<<endl;
    cout<<mark[0]<<endl;



    return 0;
}

int marked_recursive(int sidx,int *mark)
{
    if (mark[sidx]!=-1){return mark[sidx];}
//    cout<<"len: "<<len<<endl;
    if (sidx>=len)return 0;
//    cout<<"sidx: "<<sidx<<endl;

    int max=0;
    string strtmp="";
    for (int i=sidx;i<sidx+minlen-1;i++)strtmp+=str[i];
    for (int len=minlen;len<=maxlen;len++)
    {
        strtmp+=str[sidx+len-1];
        if (Tree.search(strtmp)==1)
        {
            int ans=len+marked_recursive(sidx+len,mark);
            if (ans>max)max=ans;
        }

    }

    mark[sidx]=max;
    return max;
}


int marked_chain(int sidx,int *mark)
{
    mark[len]=0;
    int strlen=str.length();
    for (int sidx=len-minlen;sidx>=0;sidx--)
    {

        int max=0;
        int judge=0;
        string strtmp="";
        for (int i=sidx;i<sidx+minlen-1;i++)strtmp+=str[i];
        for (int len=minlen;len<=maxlen&&sidx+len<=strlen;len++)
        {
            strtmp+=str[sidx+len-1];
            judge=Tree.search(strtmp);
            if (judge==-1)break;
            if (judge==1)
            {
                int ans=len+mark[sidx+len];
                if (ans>max)max=ans;
            }
        }
        mark[sidx]=max;
    }
    return mark[0];
}
