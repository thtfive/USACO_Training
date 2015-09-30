/*
ID:thtfive
LANG:C++
TASK:runround
*/
#include<fstream>
#include<iostream>
using namespace std;
string strlib="0123456789";
int M;
int mark[10];
bool flag=false;
ifstream fin("input.txt");
ofstream fout("output.txt");


bool judge(int num)
{
    if (num>0&&num<10)return true;
    int tmp;
    int mark1[10];
    for (int i=0;i<10;i++)mark1[i]=0;
    string str="";
    while(num!=0)
    {
        tmp=num%10;
        num/=10;
        if (0==tmp||mark1[tmp]==1)return false;
        mark1[tmp]=1;
        str=strlib[tmp]+str;
    }
    int len=str.length();
    if (1==mark1[len])return false;

    for (int i=0;i<10;i++)mark1[i]=0;
    int index=0;

    for (int i=0;i<len;i++)
    {
        index=(index+(str[index]-'0'))%len;
        if(1==mark1[index])return false;
        mark1[index]=1;
    }

    return true;
}

void picknum(int N,int n,int value)
{
    if (flag)return;
    if (n==N)
    {
        if(value>M&&judge(value))
        {
            fout<<value<<endl;
            flag=true;
            return;
        }
    }
    else
    {
        for (int i=1;i<10;i++)
        {
            if (mark[i]==0)
            {
                mark[i]=1;
                picknum(N,n+1,value*10+i);
                mark[i]=0;
            }
        }
    }
}

int countnum(int num)
{
    int cons=0;
    while(num!=0)
    {
        cons++;
        num/=10;
    }
    return cons;
}

int main()
{
    fin>>M;
    int tmp=M;

    for (int i=0;i<10;i++)mark[i]=0;

    int low=countnum(tmp);

    if (M<9){fout<<M+1<<endl;return 0;}
    for (int i=low;i<9;i++)
    {
        mark[i]=1;
        picknum(i,0,0);
        mark[i]=0;
        if (flag)break;
    }

    return 0;
}
