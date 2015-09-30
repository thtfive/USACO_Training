/*
ID:thtfive
LANG:C++
TASK:holstein
*/
#include<fstream>
#include<iostream>
#include<stack>
using namespace std;
#define maxV 25
#define maxG 15

ifstream fin("input.txt");
ofstream fout("output.txt");
int V=0,G=0;
int need[maxV];
int stein[maxG][maxV];
int store[maxV];
bool mark=false;

void comby(int n,int times)
{
    if (n==times)
    {
        int num[V];
        for (int k=0;k<V;k++)num[k]=0;

        for(int i=0;i<times;i++)
        {
            for (int j=0;j<V;j++)
            {
                num[j]+=stein[store[i]][j];
            }
        }
        bool flag=true;

        for (int k=0;k<V;k++)if(num[k]<need[k]){flag=false;break;}
        if (flag)
        {
            fout<<times<<" ";
            for (int i=0;i<times-1;i++)fout<<store[i]+1<<" ";
            fout<<store[times-1]+1<<"\n";


   //         cout<<times<<"\n";
    //        for (int i=0;i<times;i++)cout<<store[i]+1<<" ";
            mark=true;
            return;

        }
    }
    else
    {
        if (times!=0)
        {
            for (int i=store[times-1]+1;i<G;i++)
            {
                store[times]=i;
                comby(n,times+1);
            }
        }
        else
        {
            for (int i=0;i<G;i++)
            {
                store[times]=i;
                comby(n,times+1);
            }
        }
    }
}

int main()
{

    fin>>V;
    for (int i=0;i<V;i++)fin>>need[i];
    fin>>G;

    for (int i=0;i<G;i++)
        for (int j=0;j<V;j++)
            fin>>stein[i][j];

    for (int i=1;i<=G;i++)
    {
        comby(i,0);
        if (mark)break;
    }


    return 0;
}
