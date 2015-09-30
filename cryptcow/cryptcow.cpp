/*
ID:thtfive
TASK:cryptcow
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");
string breakMsg="Begin the Escape execution at the Break of Dawn";
string receiveMsg;
bool flag=false;
int result1=0;
int result2=0;

void input()
{
    char strtmp;
    string msg;
    while((strtmp=fin.get())!=EOF)
        msg+=strtmp;
    int length=msg.length();
    int len;
    for(len=length-1;len>=0;len--)
    {
        if(msg[len]=='\n'||msg[len]==' ')
            continue;
        break;
    }
    for(int i=0;i<=len;i++)
        receiveMsg+=msg[i];
}

void searcher(string str,int step)
{
   // cout<<str<<"\n";
    if(str.length()==breakMsg.length())
    {
        if(str==breakMsg)
        {
            result2=step;
            result1=1;
            flag=true;
        }
        return;
    }
    int length=str.length();

    for(int i=0;i<length;i++)
    {
        if(str[i]!='C')
        {
            if(str[i]!=breakMsg[i])
                return;
        }
        else
        {
            break;
        }
    }
    int len=breakMsg.length();
    for(int i=1;i<=length;i++)
    {
        if(str[length-i]!='W')
        {
            if(str[length-i]!=breakMsg[len-i])
                return;
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<length;i++)
    {
        if(str[i]=='C')
        {
            for(int j=i+1;j<length;j++)
            {
                if(str[j]=='O')
                {
                    for(int k=j+1;k<length;k++)
                    {
                        if(str[k]=='W')
                        {
                            string newstr;
                            for(int place=0;place<i;place++)
                            {
                                newstr+=str[place];
                            }
                            for(int place=j+1;place<k;place++)
                            {
                                newstr+=str[place];
                            }
                            for(int place=i+1;place<j;place++)
                            {
                                newstr+=str[place];
                            }
                            for(int place=k+1;place<length;place++)
                            {
                                newstr+=str[place];
                            }
                            if(!flag)
                            {
                                searcher(newstr,step+1);
                            }
                        }
                    }
                }
            }
        }
    }
}

void solve()
{
    searcher(receiveMsg,0);
}

void output()
{
    cout<<result1<<" "<<result2<<"\n";
    fout<<result1<<" "<<result2<<"\n";
}

int main()
{
    input();
    solve();
    output();
    return 0;
}
