/*
ID:thtfive
LANG:C++
TASK:kimbits
*/
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");
    int N,L;
    long long I;
    fin>>N>>L>>I;

    long long num_map[N+1][L+1];
    for (int i=0;i<=N;i++)
        for (int j=0;j<=L;j++)
            num_map[i][j]=0;

    for (int i=1;i<=N;i++)
    {
        num_map[i][1]=i+1;
    }
    for (int j=1;j<=L;j++)
        num_map[1][j]=2;


    for (int i=2;i<=N;i++)
    {
        for (int j=2;j<=L;j++)
        {
            num_map[i][j]=num_map[i-1][j-1]+num_map[i-1][j];
        }
    }

    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=L;j++)
        {
            cout<<num_map[i][j]<<" ";
        }
        cout<<endl;
    }

    bool flag[N+1];
    for (int i=0;i<=N;i++)flag[i]=false;

    int len=L;
    long long number=I;

    while (1)
    {
        if(len!=1)
        {
            bool mark=true;
            for (int idx=N;idx>=1;idx--)
            {
                if (number>num_map[idx][len])
                {
                    flag[idx+1]=true;
                    number-=num_map[idx][len];
                    len--;
                    mark=false;
                    break;
                }
            }
            if(mark)len=1;
        }
        else
        {
            if(number>1)flag[number-1]=true;
            len--;
        }
        if(len==0)break;
    }

    string str;
    string strlib="01";
    for (int i=N;i>=1;i--)
    {
        if(flag[i])str+=strlib[1];
        else str+=strlib[0];
    }
    cout<<str<<endl;
    fout<<str<<endl;

    return 0;
}
