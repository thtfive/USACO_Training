/*
ID:thtfive
LANG:C++
TASK:numtri
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int N;
    fin>>N;
    int numtri[N][N];
    int maxnum;
    for (int i=0;i<N;i++)
        for (int j=0;j<=i;j++)
            fin>>numtri[i][j];
    for (int i=1;i<N;i++)
        for (int j=0;j<=i;j++)
        {
            if(j==0)numtri[i][j]+=numtri[i-1][0];
            if(j==i)numtri[i][j]+=numtri[i-1][i-1];
            if(j!=0&&j!=i)numtri[i][j]+=numtri[i-1][j-1]>numtri[i-1][j] ? numtri[i-1][j-1]:numtri[i-1][j];
        }

    maxnum=numtri[N-1][N-1];

    for (int i=0;i<N;i++)if(numtri[N-1][i]>maxnum)maxnum=numtri[N-1][i];
    fout<<maxnum<<"\n";
    return 0;
}
