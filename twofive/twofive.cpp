/*
ID:thtfive
LANG:C++
TASK:twofive
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

ifstream fin("twofive.in");
ofstream fout("twofive.out");
string operation;
string Word;
char resultstr[25];
string strs="ABCDEFGHIJKLMNOPQRSTUVWXY";
int record[6][6][6][6][6];
int states[26][100][6];
int statenum[26];
int xpos[26];
int ypos[26];
int result;
int Number;

void init()
{
    fin>>operation;
    if(operation=="W")
    {
        fin>>Word;
    }
    else
    {
        fin>>Number;
    }
    memset(states,0,sizeof(states));
    memset(statenum,0,sizeof(statenum));
    for(int i1=0;i1<6;i1++)
        for(int i2=0;i2<=i1;i2++)
            for(int i3=0;i3<=i2;i3++)
                for(int i4=0;i4<=i3;i4++)
                    for(int i5=0;i5<=i4;i5++)
                    {
                        int sum=i1+i2+i3+i4+i5;
                        statenum[sum]++;
                        int statecount=statenum[sum];
                        states[sum][statecount][1]=i1;
                        states[sum][statecount][2]=i2;
                        states[sum][statecount][3]=i3;
                        states[sum][statecount][4]=i4;
                        states[sum][statecount][5]=i5;
                    }
}

int DP()
{
    memset(record,0,sizeof(record));
    record[5][5][5][5][5]=1;
    for(int sum=24;sum>=0;sum--)
    {
        for(int state=1;state<=statenum[sum];state++)
        {
            int row[6];
            row[0]=5;
            row[1]=states[sum][state][1];
            row[2]=states[sum][state][2];
            row[3]=states[sum][state][3];
            row[4]=states[sum][state][4];
            row[5]=states[sum][state][5];
            int a=row[1];
            int b=row[2];
            int c=row[3];
            int d=row[4];
            int e=row[5];
          //  cout<<a<<" "<<b<<" "<<c<<" "<<d<< " "<<e<<"  row\n";
            record[row[1]][row[2]][row[3]][row[4]][row[5]]=0;
            if(!xpos[sum])
            {
                if(a<5)record[a][b][c][d][e]+=record[a+1][b][c][d][e];
                if(b<a)record[a][b][c][d][e]+=record[a][b+1][c][d][e];
                if(c<b)record[a][b][c][d][e]+=record[a][b][c+1][d][e];
                if(d<c)record[a][b][c][d][e]+=record[a][b][c][d+1][e];
                if(e<d)record[a][b][c][d][e]+=record[a][b][c][d][e+1];
            }
            else
            {
                if(row[xpos[sum]]<row[xpos[sum]-1]&&row[xpos[sum]]+1==ypos[sum])
                {
                    row[xpos[sum]]++;
                    record[a][b][c][d][e]+=record[row[1]][row[2]][row[3]][row[4]][row[5]];
                }
            }
        }
    }
    return record[0][0][0][0][0];
}


void word2num()
{
    memset(xpos,0,sizeof(xpos));
    memset(ypos,0,sizeof(ypos));
    result=0;
    int ch;

    for(int len=0;len<=24;len++)
    {
        for(ch=0;ch<Word[len]-'A';ch++)
        {
            if(!xpos[ch])
            {
                xpos[ch]=len/5+1;
                ypos[ch]=len%5+1;
                int totalnum=DP();
                result+=totalnum;
                xpos[ch]=0;
                ypos[ch]=0;
            }

        }
        xpos[ch]=len/5+1;
        ypos[ch]=len%5+1;
    }
    result++;
}
void num2word()
{
    memset(xpos,0,sizeof(xpos));
    memset(ypos,0,sizeof(ypos));
    for(int m=1;m<=5;m++)
    {
        for(int n=1;n<=5;n++)
        {
            for(int ch=0;ch<=24;ch++)
            {
                if(xpos[ch]==0)
                {
                    xpos[ch]=m;
                    ypos[ch]=n;
                    int totalnum=DP();
                    if(Number>totalnum)
                    {
                        Number-=totalnum;
                    }
                    else
                    {
                        break;
                    }
                    xpos[ch]=0;
                    ypos[ch]=0;
                }
            }

        }
    }
    for(int ch=0;ch<=24;ch++)
    {
        resultstr[(xpos[ch]-1)*5+ypos[ch]-1]=strs[ch];
    }
}


void solution()
{
    if(operation=="W")
    {
        word2num();
    }
    else
    {
        num2word();
    }
}

void print()
{
    if(operation=="W")
    {
        cout<<result<<"\n";
        fout<<result<<"\n";
    }
    else
    {
        cout<<resultstr<<"\n";
        fout<<resultstr<<"\n";
    }
}

int main()
{
    init();
    solution();
    print();
    return 0;
}
