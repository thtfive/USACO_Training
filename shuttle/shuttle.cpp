/*
ID:thtfive
LANG:C++
TASK:shuttle
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;
int N;
string puzzle;
string goal;
ifstream fin("shuttle.in");
ofstream fout("shuttle.out");
void solution()
{
    queue<string>strque;
    queue<string>stepsque;
    queue<int>que;
    strque.push(puzzle);
    stepsque.push("");
    que.push(N);
    while(!strque.empty())
    {
        string str=strque.front();
        string steps=stepsque.front();
        int emptyplace=que.front();
        strque.pop();
        stepsque.pop();
        que.pop();
        if(str==goal)
        {
            int len=steps.length();
            int counter=0;
            for(int i=0;i<len-1;i++)
            {
                fout<<steps[i]-'A'+1;
                counter++;
                if(counter%20==0)fout<<"\n";
                else fout<<" ";
            }
            fout<<steps[len-1]-'A'+1;
            counter++;
            fout<<"\n";
            return;
        }
        if(emptyplace>=2&&str[emptyplace-1]=='B'&&str[emptyplace-2]=='W')
        {
            string strtmp=str;
            strtmp[emptyplace]='W';
            strtmp[emptyplace-2]='O';
            char ch;
            ch='A'+emptyplace-2;
            strque.push(strtmp);
            stepsque.push(steps+ch);
            que.push(emptyplace-2);
        }
        if(emptyplace>=1&&str[emptyplace-1]=='W')
        {
            string strtmp=str;
            strtmp[emptyplace]='W';
            strtmp[emptyplace-1]='O';
            char ch;
            ch='A'+emptyplace-1;
            strque.push(strtmp);
            stepsque.push(steps+ch);
            que.push(emptyplace-1);
        }
        if(emptyplace<=2*N&&str[emptyplace+1]=='B')
        {
            string strtmp=str;
            strtmp[emptyplace]='B';
            strtmp[emptyplace+1]='O';
            char ch;
            ch='A'+emptyplace+1;
            strque.push(strtmp);
            stepsque.push(steps+ch);
            que.push(emptyplace+1);
        }
        if(emptyplace<=2*N-1&&str[emptyplace+1]=='W'&&str[emptyplace+2]=='B')
        {
            string strtmp=str;
            strtmp[emptyplace]='B';
            strtmp[emptyplace+2]='O';
            char ch;
            ch='A'+emptyplace+2;
            strque.push(strtmp);
            stepsque.push(steps+ch);
            que.push(emptyplace+2);
        }
    }
}

int main()
{
    fin>>N;
    puzzle="";
    goal="";
    for(int i=0;i<N;i++)
    {
        puzzle+="W";
        goal+="B";
    }
    puzzle+="O";
    goal+="O";
    for(int i=0;i<N;i++)
    {
        puzzle+="B";
        goal+="W";
    }
    solution();
    return 0;
}
