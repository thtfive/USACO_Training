/*
ID:thtfive
LANG:C++
TASK:rockers
*/
#include<iostream>
#include<fstream>
using namespace std;
#define max_N 20 ///the number of songs
#define max_M 20 ///the number of disk
#define max_left 20///the space left in the current-first disk
int recorder[max_N+1][max_M+1][max_left+1];
int MusicLength[max_N+1];
int N,T,M;

int recursive_solution(int n,int m,int left)
{
    if(recorder[n][m][left]!=-1)return recorder[n][m][left];
    int songNum1=0;
    int songNum2=0;

    if(left>=MusicLength[n])
    {
        songNum1=1;
        songNum1+=recursive_solution(n+1,m,left-MusicLength[n]);
    }
    else
    if(MusicLength[n]<=T&&m>1)
    {
        songNum1=1;
        songNum1+=recursive_solution(n+1,m-1,T-MusicLength[n]);
    }

    songNum2+=recursive_solution(n+1,m,left);

    if(songNum1>songNum2)
        recorder[n][m][left]=songNum1;
    else
        recorder[n][m][left]=songNum2;

    return recorder[n][m][left];
}

int main()
{
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");

    fin>>N>>T>>M;
    for (int i=1;i<=N;i++)
        fin>>MusicLength[i];

    for (int i=0;i<=N;i++)
    {
        for (int j=0;j<=M;j++)
        {
            for (int k=0;k<=T;k++)
            {
                recorder[i][j][k]=-1;
            }
        }
    }

    int result=0;
    result=recursive_solution(1,M,T);
    cout<<result<<"\n";
    fout<<result<<"\n";

    return 0;
}
