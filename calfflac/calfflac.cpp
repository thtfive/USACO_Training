/*
ID:thtfive
TASK:calfflac
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
///利用数组record记录从i开始长达len的数组是否是回文字符
///由于计算长度为len的回文需要用到长度为len-2的信息，因此要定义record的第一个维度为2
///递推计算
using namespace std;
ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
string strlib;
int record[2][20010];
bool charjudge[20010];
int length;
int start;
int finish;
int maxlen;

void input()
{
    char strtmp;
    strlib="";
    memset(record,-2,sizeof(record));
    memset(charjudge,false,sizeof(charjudge));
    while((strtmp=fin.get())!=EOF)
        strlib+=strtmp;
    length=strlib.length();
}

bool ischar(char ch)
{
     int a=ch-'a';
     int b=ch-'A';
     if(a>=0&&a<26)return true;
     if(b>=0&&b<26)return true;
     return false;
}

bool compare(char ch1,char ch2)
{
    if(ch1-'a'==ch2-'a')return true;
    if(ch1-'a'==ch2-'A')return true;
    if(ch1-'A'==ch2-'a')return true;
    return false;
}

void solution()
{
    maxlen=0;
    for(int i=0;i<length;i++)
    {
        if(ischar(strlib[i]))
        {
            charjudge[i]=true;
            record[1][i]=i;
            record[0][i]=i-1;
            if(maxlen==0)
            {
                maxlen=1;
                start=i;
                finish=i;
            }
        }
    }

    for(int len=1;len<2000;len++)
    {
        for(int i=0;i<length-len;i++)
        {
            if(charjudge[i])///如果strlib[i]是字符
            {
                for(int k=i+1;k<length;k++)
                {
                    if(charjudge[k])///如果strlib[k]是字符
                    {
                        if(record[(len+1)%2][k]!=-2)
                        {
                            for(int m=record[(len+1)%2][k]+1;m<length;m++)
                            {
                                if(charjudge[m])
                                {
                                    if(compare(strlib[i],strlib[m]))
                                    {
                                        record[(len+1)%2][i]=m;
                                        if(len+1>maxlen)
                                        {
                                            maxlen=len+1;
                                            start=i;
                                            finish=m;
                                        }
                                    }
                                    else
                                    {
                                        record[(len+1)%2][i]=-2;
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            record[(len+1)%2][i]=-2;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void output()
{
    cout<<strlib<<"\n";
    cout<<maxlen<<"\n";
    for(int i=start;i<=finish;i++)
        cout<<strlib[i];
    cout<<"\n";
    fout<<maxlen<<"\n";
    for(int i=start;i<=finish;i++)
        fout<<strlib[i];
    fout<<"\n";

}
int main()
{
    input();
    solution();
    output();
    return 0;
}
