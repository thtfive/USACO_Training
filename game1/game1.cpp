/*
ID:thtfive
LANG:C++
TASK:game1
*/
#include<iostream>
#include<fstream>
using namespace std;

int Numlib[101];
int record[101][101][3];

int solution(int start,int finish)
{
    if (record[start][finish][0]!=-1){return record[start][finish][0];}

    int value1;
    int value2;
    value1=Numlib[start];
    value2=Numlib[finish];

    if(start<finish-1)
    {
        solution(start+1,finish);
        value1+=solution(record[start+1][finish][1],record[start+1][finish][2]);
        solution(start,finish-1);
        value2+=solution(record[start][finish-1][1],record[start][finish-1][2]);
    }

    if(value1>value2)
    {
        record[start][finish][0]=value1;
        record[start][finish][1]=start+1;
        record[start][finish][2]=finish;
        return value1;
    }
    else
    {
        record[start][finish][0]=value2;
        record[start][finish][1]=start;
        record[start][finish][2]=finish-1;
        return value2;
    }
}

int main()
{
    int N;
    ifstream fin("game1.in");
    ofstream fout("game1.out");
    fin>>N;
    int idx=0;
    while(idx<N)
    {
        fin>>Numlib[idx];
        idx++;
    }
    for (int i=0;i<=100;i++)
    {
        for (int j=0;j<=100;j++)
        {
            record[i][j][0]=-1;
        }
    }

    int first=solution(0,N-1);
    int total=0;
    int second;
    for (int i=0;i<N;i++)
        total+=Numlib[i];
    second=total-first;
    fout<<first<<" "<<second<<"\n";

    return 0;
}
