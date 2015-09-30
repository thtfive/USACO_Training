/*
ID:thtfive
LANG:C++
TASK:hamming
*/
#include<fstream>
#include<iostream>
using namespace std;
#define max_num 65
int mark[max_num];
int index=0;

bool binary_compare(int lib,int num,int D)
{
    string str1="00000000",str2="00000000";
    int idx=0;
    while (lib!=0)
    {
        if (1==lib%2)str1[idx]='1';
        lib/=2;
        idx++;
    }
    idx=0;
    while (num!=0)
    {
        if (1==num%2)str2[idx]='1';
        num/=2;
        idx++;
    }

    int counter=0;
    for (int i=0;i<8;i++)if (str1[i]!=str2[i])counter++;
    if (counter>=D)
    {
        return true;
    }
    return false;
}

void compare(int num,int D)///check w
{
    if (0==index)mark[index++]=num;
    else
    {
        bool flag=true;
        for (int i=0;i<index;i++)
        {
            if(!binary_compare(mark[i],num,D)){flag=false;break;}
        }
        if (flag)mark[index++]=num;
    }
}

void solve(int N,int B,int D)///search from 0 to 2^B to get the answer
{
    int maxnum=1;
    for (int i=0;i<B;i++)maxnum*=2;
    for (int i=0;i<maxnum;i++)
    {
        compare(i,D);
        if (index==N)return;
    }
}
int main()
{
    ifstream fin("input.txt");
    ofstream fout("ouput.txt");
    int N,B,D;
    fin>>N>>B>>D;

    solve(N,B,D);

    int count=0;

    for (int i=0;i<N;i++)
    {
        fout<<mark[i];
        count++;
        if (count%10==0||i==N-1)fout<<"\n";
        else fout<<" ";

    }

    return 0;
}
