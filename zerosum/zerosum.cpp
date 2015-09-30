/*
ID:thtfive
LANG:C++
TASK:zerosum
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>

using namespace std;
ofstream fout("output.txt");
string strlib="0123456789";

void create(int N,int times,string s)
{
    if (times==N+1)
    {
        int tmp1=1;

        int result=0;
        char flag='+';

        int len=s.length();
        for(int i=1;i<len;)
        {
            if (s[i]==' ')
            {
                tmp1=tmp1*10+s[i+1]-'0';;
            }
            else
            {
                if (flag=='+')result+=tmp1;
                else result-=tmp1;
                tmp1=s[i+1]-'0';
                flag=s[i];
            }
            i=i+2;
        }
        if (flag=='+')result+=tmp1;
        else result-=tmp1;

        if (result==0)fout<<s<<"\n";
    }
    else
    {
        for (int i=-1;i>-4;i--)
        {
            switch(i)
            {
                case -1:
                    {
                        create(N,times+1,s+" "+strlib[times]);
                        break;
                    }
                case -2:
                    {
                        create(N,times+1,s+"+"+strlib[times]);
                        break;
                    }
                case -3:
                    {
                        create(N,times+1,s+"-"+strlib[times]);
                        break;
                    }
            }
        }
    }
}

int main()
{
    ifstream fin("input.txt");

    int N;
    fin>>N;
    create(N,2,"1");


    return 0;
}
