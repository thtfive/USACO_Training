/*
ID:thtfive
LANG:C++
TASK:range
*/
///solving this problem using Dynamic Programming
///the data to check the square of s to check the square of s+1
#include<iostream>
#include<fstream>
using namespace std;
int counter[251];
bool flag[251][251];

void solution(int size,int N)
{
    for(int i=0;i<=N-size;i++)
    {
        for(int j=0;j<=N-size;j++)
        {
            if(flag[i][j]&&flag[i][j+1]&&flag[i+1][j]&&flag[i+1][j+1])
            {
                flag[i][j]=true;
                counter[size]++;
            }
            else
                flag[i][j]=false;
        }
    }
}

int main()
{
    ifstream fin("range.in");
    ofstream fout("range.out");
    int N;
    fin>>N;
    string str;
//    bool map[N+1][N+1];
    for (int i=0;i<N;i++)
    {
        fin>>str;
        for (int j=0;j<N;j++)
            flag[i][j]=(str[j]=='1');
    }
    for(int i=0;i<=N;i++)
        counter[i]=0;

    for (int s=2;s<=N;s++)
        solution(s,N);

    for (int s=2;s<=N;s++)
    {
        if(counter[s]!=0)
            fout<<s<<" "<<counter[s]<<"\n";
    }
    if(counter[2]==0)fout<<"\n";





    return 0;
}
