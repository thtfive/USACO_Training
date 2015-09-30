/*
ID:thtfive
LANG:C++
TASK:charrec
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

ifstream fdict("font.in");
ifstream fin("charrec.in");
ofstream fout("charrec.out");
string result;
string dict[541];
string lib[1200];
string strs="0 abcdefghijklmnopqrstuvwxyz";
int N,dictN;
int start,finish;
int record[1200];
int unmatchnum[1201][541];
string recordstr[1200];

void init()
{
    memset(record,-1,sizeof(record));
    memset(unmatchnum,0,sizeof(unmatchnum));
    fin>>N;
    fdict>>dictN;
    for(int i=1;i<=dictN;i++)
    {
        fdict>>dict[i];
    }
    for(int i=1;i<=N;i++)
        fin>>lib[i];

    memset(unmatchnum,0,sizeof(unmatchnum));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=dictN;j++)
        {
            for(int k=0;k<20;k++)
            {
                if(lib[i][k]!=dict[j][k])
                    unmatchnum[i][j]++;
            }
        }
    }
}

int bestfit19(int start,int finish,string &str)
{
    int wrongnum=999999999;
    for(int ch=1;ch<=27;ch++)
    {
        int counter=999999999;

        for(int lack=0;lack<20;lack++)
        {
            int countertmp=0;
            for(int i=0;i<lack;i++)
            {
                countertmp+=unmatchnum[start+i][(ch-1)*20+i+1];
            }
            for(int i=lack+1;i<20;i++)
            {
                countertmp+=unmatchnum[start+i-1][(ch-1)*20+i+1];
            }
            counter=min(counter,countertmp);
        }
        if(counter<wrongnum)
        {

            wrongnum=counter;
            str=strs[ch];
        }
    }
    return wrongnum;
}

int bestfit20(int start,int finish,string &str)
{
    int wrongnum=999999999;
    for(int ch=1;ch<=27;ch++)
    {
        int counter=0;
        for(int i=0;i<20;i++)
        {
            counter+=unmatchnum[start+i][(ch-1)*20+i+1];
        }

        if(counter<wrongnum)
        {
            wrongnum=counter;
            str=strs[ch];
        }
    }

    return wrongnum;
}

int bestfit21(int start,int finish,string &str)
{
    int wrongnum=999999999;
    for(int ch=1;ch<=27;ch++)
    {
        int counter=999999999;
        for(int more=1;more<=20;more++)
        {
            int countertmp=0;
            for(int i=0;i<more;i++)
            {
                countertmp+=unmatchnum[start+i][(ch-1)*20+i+1];
            }
            for(int i=more+1;i<=20;i++)
            {
                countertmp+=unmatchnum[start+i][(ch-1)*20+i];
            }
            counter=min(counter,countertmp);
        }

        if(counter<wrongnum)
        {
            wrongnum=counter;
            str=strs[ch];
        }
    }
    return wrongnum;
}

void solution()
{
    record[0]=0;

    for(int finish=19;finish<=N;finish++)
    {
        bool flag1=false,flag2=false,flag3=false;
        int tmp1=999999999,tmp2=999999999,tmp3=999999999;
        string str1,str2,str3;

        int last=finish-19;
        if(last>=0&&record[last]!=-1)
        {
            flag1=true;
            tmp1=record[last]+bestfit19(last+1,finish,str1);
        }

        last=finish-20;
        if(last>=0&&record[last]!=-1)
        {
            flag1=true;
            tmp2=record[last]+bestfit20(last+1,finish,str2);
        }

        last=finish-21;
        if(last>=0&&record[last]!=-1)
        {
            flag3=true;
            tmp3=record[last]+bestfit21(last+1,finish,str3);
        }

        if(flag1==false&&flag2==false&&flag3==false)continue;

        if(tmp1<tmp2)
        {
            if(tmp1<tmp3)
            {
                record[finish]=tmp1;
                recordstr[finish]=recordstr[finish-19]+str1;
            }
            else
            {
                record[finish]=tmp3;
                recordstr[finish]=recordstr[finish-21]+str3;
            }
        }
        else
        {
            if(tmp2<tmp3)
            {
                record[finish]=tmp2;
                recordstr[finish]=recordstr[finish-20]+str2;
            }
            else
            {
                record[finish]=tmp3;
                recordstr[finish]=recordstr[finish-21]+str3;
            }
        }
    }
}
void print()
{
    string ans;
    ans=recordstr[N];

    cout<<ans<<"\n";
    fout<<ans<<"\n";
}

int main()
{
    init();
    solution();
    print();
    return 0;
}
