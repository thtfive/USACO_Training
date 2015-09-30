/*
ID:thtfive
LANG:C++
TASK:tour
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<string.h>
using namespace std;
///该题利用动态规划方法解决

int N;
string cities[101];
bool flag[101];
int G[101][101];

int findindex(string city)
{
   for(int i=1;i<=N;i++)
   {
       if(city==cities[i])return i;
   }
   return 0;
}

int main()
{
    ifstream fin("tour.in");
    ofstream fout("tour.out");

    int V;
    fin>>N>>V;

    memset(G,0,sizeof(G));
    for(int i=1;i<=N;i++)
    {
        fin>>cities[i];
    }
    for(int i=1;i<=V;i++)
    {
        string city1;
        string city2;
        fin>>city1>>city2;
        int index1,index2;
        index1=findindex(city1);
        index2=findindex(city2);
        G[index1][index2]=1;
        G[index2][index1]=1;
    }

    int record[N+1][N+1];
    memset(record,0,sizeof(record));

    record[1][1]=1;
    for(int a=1;a<=N;a++)
    {
        for(int b=a+1;b<=N;b++)
        {
            int maxnum=-100;
            for(int k=1;k<b;k++)
            {
                if(G[k][b]==1&&record[a][k]>0)
                {
                    maxnum=max(maxnum,record[a][k]+1);
                }
            }
            record[a][b]=maxnum;
            record[b][a]=maxnum;
        }
    }

//    int maxnum=1;
//    for(int k=1;k<N;k++)
//    {
//        if(G[k][N]==1)
//        {
//            maxnum=max(maxnum,record[N][k]);
//        }
//    }

    int result=1;
    for (int i=1;i<N;i++)
        if (G[i][N]==1&&record[i][N]>result)
            result=record[i][N];

    cout<<result<<"\n";
    fout<<result<<"\n";


    return 0;
}
