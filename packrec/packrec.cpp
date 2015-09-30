/*
ID:thtfive
TASK:packrec
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("packrec.in");
ofstream fout("packrec.out");
int sides[4][2];
int result;
int resultnum;
int rect[100][2];

void input()
{
    result=0;
    for(int i=0;i<4;i++)
    {
        fin>>sides[i][0]>>sides[i][1];
    }
}

void solve()
{

}

void output()
{
    cout<<result<<"\n";
    for(int i=0;i<resultnum;i++)
    {
        cout<<rect[i][0]<<" "<<rect[i][1]<<"\n";
    }
}

int main()
{
    input();
    solve();
    output();
    return 0;
}
